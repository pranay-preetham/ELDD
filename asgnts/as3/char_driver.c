//program to open ,read,write and close dynamically

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define NAME mychardevice

//function prototypes
int NAME_open(struct inode *inode,struct file *filp);
int NAME_release(struct inode *inode,struct file *filp);
ssize_t NAME_write(struct file *filp,const char __user *Ubuff,size_t count,loff_t *offp);
ssize_t NAME_read(struct file *filp,char __user *Ubuff,size_t count,loff_t *offp);
//int NAME_flush(struct file *filp);

struct file_operations fops=
{
	.owner=THIS_MODULE,
	.open=NAME_open,
	.read=NAME_read,
	.write=NAME_write,
	.release=NAME_release,
//	.flush=NAME_flush,

};

struct cdev *my_cdev;

static int __init CharDevice_init(void)
{
	int result;
	int MAJOR,MINOR;
	dev_t Mydev;
	Mydev=MKDEV(255,0);//creates a device numbers
	MAJOR=MAJOR(Mydev);
	MINOR=MINOR(Mydev);
	printk("\n the major number is %d the minor number is %d\n",MAJOR,MINOR);
	result = register_chrdev_region(Mydev,1,"mychardevice");
	if(result<0)
	{
		printk(KERN_ALERT "\n the region requested for is not obtainable\n");
		return(-1);
	}
	my_cdev = cdev_alloc();//alocate memory to char device drivers
	//my_cdev -> ops = fops;//link our file operations to the char devices
	result = cdev_add(my_cdev,Mydev,1);//notify the kernel about the new device
	if(result<0)
	{
		printk(KERN_ALERT "\n the char device has not been created\n");
		unregister_chrdev_region(Mydev,1);
		return -1;
	}
	return 0;
}
//clean_up module
void __exit CharDevice_exit(void)
{
	dev_t Mydev;
	int MAJOR,MINOR;
	Mydev=MKDEV(255,0);
	MAJOR=MAJOR(Mydev);
	MINOR=MINOR(Mydev);
	printk("\n the major number is %d...the minor number is %d\n",MAJOR,MINOR);
	unregister_chrdev_region(Mydev,1);
	cdev_del(my_cdev);
	printk(KERN_ALERT "\n I have unregistered the stuff that was allocated ....goodbye for ever\n");
}

//open system call
int NAME_open(struct inode *inode,struct file *filp)
{
	printk(KERN_ALERT "\n this is kernel ....open call\n");
	return 0;
}
int NAME_release(struct inode *inode,struct file *filp)
{
	printk(KERN_ALERT "\n this is the release method of my character driver\n");
	return 0;
}
ssize_t NAME_write(struct file *filp,const char __user *Ubuff,size_t count,loff_t *offp)
{
	char Kbuff[80];
	unsigned long result;
	ssize_t retval;
	//strcpy(Kbuff,Ubuff);
	result=copy_from_user((char *)Kbuff,(char *)Ubuff,count);
	if(result == 0)
	{
		printk(KERN_ALERT "\ n message from the user ....\n>>>>%s <<<<\n",Kbuff);
		printk(KERN_ALERT "\n data successfully written...\n");
		retval=count;
		printk("\no. of bytes recieved=%d",count);
		return retval;
	}
	else if(result > 0)
	{
		printk(KERN_ALERT "\n message from the user ..\n  %s<<<<\n",Kbuff);
		printk(KERN_ALERT "\n part data copied\n");
		retval=(count-result);
		return retval;
	}
	else
	{
		printk(KERN_ALERT "\nerror writing Data\n");
		retval=-EFAULT;
		return (-1);
	}
}
//read functionality
ssize_t NAME_read(struct file *filp,char __user *Ubuff,size_t count,loff_t *offp)
{
	char Kbuff[]="This is ssome data from the kernel to the user...User";
	unsigned long result;
	ssize_t retval;
	//strcpy(K,Ubuff);
	result=copy_to_user((char *)Ubuff,(char *)Kbuff,count);
	if(result==0)
	{
		printk("\n message from the user...\n>>>%s<<<<\n");
		retval=count;
		return retval;
	}
	else if(result>0)
	{
	//printk(KERN_ALERT "\nmessage from the user ...\n>>>%s<<<\n",	Kbuff);
		printk(KERN_ALERT "\npart data available\n");
		retval=(count-result);
		return retval;
	}
	return count;
}

module_init(CharDevice_init);
module_exit(CharDevice_exit);
