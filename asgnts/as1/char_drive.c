//Write a program to open and close the device

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");


dev_t dev = 0;
struct class *dev_class;
struct cdev etx_cdev;

static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);
static int etx_open(struct inode *inode,struct file *file);
static int etx_release(struct inode *inode,struct file *file);

//file operations structure
static struct file_operations fops=
{
	.owner   = THIS_MODULE,
	.open    = etx_open,
	.release = etx_release,
};

//open function
static int etx_open(struct inode *inode,struct file *file)
{
	printk(KERN_ALERT "device is opened\n");
	return 0;
}

//close function
static int etx_release(struct inode *inode,struct file *file)
{
	printk(KERN_ALERT "device is closed\n");
	return 0;
}


//init function

static int __init etx_driver_init(void)
{
	//allocation of character device
	if((alloc_chrdev_region(&dev,0,1,"my_device")) <0)
	{
		printk(KERN_INFO "Cannot allocate major number\n");
		return -1;
	}
	//major and minor no are:
	printk(KERN_INFO "Major no. = %d Minor no. = %d\n",MAJOR(dev),MINOR(dev));
	//creating cdev structre
	cdev_init(&etx_cdev,&fops);
	//adding character device to the system
	if((cdev_add(&etx_cdev,dev,1)) < 0)
	{
		printk(KERN_INFO "cannot add device to the system\n");
		goto r_class;
	}
	//creating struct class
	if((dev_class = class_create(THIS_MODULE,"my_class")) ==NULL)
	{
		printk(KERN_INFO "cannot create struct class\n");
		goto r_class;
	}
	//creating device
	if((device_create(dev_class,NULL,dev,NULL,"my_device")) == NULL)
	{
		printk(KERN_INFO "Cannot create the device\n");
		goto r_device;
	}
	printk(KERN_INFO "Device driver insert ...Done\n");
	return 0;
//destroy class if it is not able to create
r_device:
	class_destroy(dev_class);
//unregister character device if it is unable to be created
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}

//cleanup function
static void __exit etx_driver_exit(void)
{
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&etx_cdev);
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO "Device driver is removed\n");
}

module_init(etx_driver_init);
module_exit(etx_driver_exit);
