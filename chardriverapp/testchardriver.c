//$make
//$insmod testchardriver.ko
//./userapp
//rmmod testchardriver.ko

#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/semaphore.h>//access semaphores
#include<asm/uaccess.h>
#include<linux/device.h>

//create structure for char device
struct char_device
{
	char data[100];
	struct semaphore sem;
}virtual_device;

//register char device
struct cdev *mcdev;
int major_number,minor_number;
int ret;
dev_t dev_num;

static struct class *cl;
#define DEVICE_NAME "chardevice"
//inode refers to file in disk contains information about file
//open device
int device_open(struct inode *inode,struct file *filp)
//only one person can access this device -- mutex concept
{
	if(down_interruptible(&virtual_device.sem)!=0)
	{
		printk(KERN_ALERT "\nchardevice:could not lock during open");
		return(-1);
	}
	printk(KERN_INFO "\nchardevice:opened device");
	return 0;
}
//when user want to get information about device
ssize_t device_read(struct file *filp,char *bufstoredata,size_t bufcount,loff_t* curoffset)
{
//take data from kernel to user space
//copy_to_user(destination,source,sizeoftransfer
	printk(KERN_INFO "\nReading from device\n");
	ret=copy_to_user(bufstoredata,virtual_device.data,bufcount);
	return ret;
}
//when user wants to send the information to device
ssize_t device_write(struct file *filp,const char *bufsourcedata,size_t bufcount,loff_t* curoffset)
{
//send data from user to kernel
	printk(KERN_INFO "\n writing to the device\n");
	ret=copy_from_user(virtual_device.data,bufsourcedata,bufcount);
	return ret;
}
//to close the device
int device_close(struct inode *inode,struct file *filp)
{
//when up is called we release the mutex that we obtained at open
//then other process can take up this device 
	up(&virtual_device.sem);
	printk(KERN_INFO "\n closed device");
	return 0;
}
//tells the kernel which operation to call when user operates on our device file
struct file_operations fops=
{
	.owner=THIS_MODULE,
	.open=device_open,
	.read=device_read,
	.write=device_write,
	.release=device_close,
};

static int driver_entry(void)
{
//registering the char device
	ret=alloc_chrdev_region(&dev_num,0,1,DEVICE_NAME);
	if(ret<0)
	{
		printk(KERN_ALERT "\n failed to allocate device number\n");
		return ret;
	}
	major_number=MAJOR(dev_num);
	minor_number=MINOR(dev_num);
	printk(KERN_INFO "\nmodule loaded ,device is :/dev/%s",DEVICE_NAME);
	printk(KERN_INFO "\n major number is: %d,minor number is: %d",major_number,minor_number);
	mcdev=cdev_alloc();
	mcdev->ops = &fops;
	mcdev->owner=THIS_MODULE;
	if((cl=class_create(THIS_MODULE, "chardev")) == NULL)
	{
		unregister_chrdev_region(dev_num,1);
		return(-1);
	}
	//create /dev/chardevice node
	if(device_create(cl,NULL,dev_num,NULL,DEVICE_NAME) == NULL)
	{
		class_destroy(cl);
		unregister_chrdev_region(dev_num,1);
		return(-1);
	}
	//we add cdev to kernel
	ret=cdev_add(mcdev,dev_num,1);
	if(ret<0)
	{
		printk(KERN_INFO "\n unable to add cdev to the kernel");
		unregister_chrdev_region(dev_num,1);
		return ret;
	}
	sema_init(&virtual_device.sem,1);
	return 0;
}
static void driver_exit(void)
{
//unregistering character device driver
	cdev_del(mcdev);
	device_destroy(cl,dev_num);
	class_destroy(cl);
	unregister_chrdev_region(dev_num,1);
	printk(KERN_INFO "\n module unloaded");
}

module_init(driver_entry);
module_exit(driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BUNNY"); 
