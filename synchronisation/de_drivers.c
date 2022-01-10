#include<linux/init.h>
#include<linux/fs.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
#include<linux/mutex.h>
#include<linux/uaccess.h>
#include<linux/device.h>
#include<linux/ctype.h>
#include<linux/string.h>
#include<asm/rwonce.h>
#include<linux/sched.h>
#include<linux/types.h>

#define DEVICE_NAME "my_device"
#define CLASS_NAME "tdl"

MODULE_LICENSE("GPL");

static char message[256]={0};
static int sizeofmessage;
static int numberopens=0;

static struct class* tdlcharclass=NULL;
static struct device* tdlchardevice=NULL;
static int majornumber;

static DEFINE_MUTEX(tdlchar_mutex);

static int dev_open(struct inode *,struct file *);
static int dev_release(struct inode *,struct file *);
static ssize_t dev_read(struct file *,char *,size_t,loff_t *);
static ssize_t dev_write(struct file *,const char *,size_t,loff_t *);
static char totheupper(const char);

struct file_operations fops=
{
	.open = dev_open,
	.read = dev_read,
	.write = dev_write,
	.release = dev_release,
};

static int __init tdlchar_init(void)
{
	printk(KERN_INFO "TDLchar: initializing the TDLchar \n");
	majornumber = register_chrdev(0,DEVICE_NAME,&fops);
	if(majornumber < 0)
	{
		printk(KERN_ALERT "TDLchar failed to register a major number\n");
		return majornumber;
	}
	printk(KERN_ALERT "TDLChar: registered correctly with major number %d\n",majornumber);
	tdlcharclass=class_create(THIS_MODULE,CLASS_NAME);
	if(IS_ERR(tdlcharclass))
	{
		unregister_chrdev(majornumber,DEVICE_NAME);
		printk(KERN_ALERT "Filed to register the device\n");
		return PTR_ERR(tdlcharclass);
	}
	printk(KERN_INFO "TDLChar:device class registered correctly\n");
	tdlchardevice=device_create(tdlcharclass,NULL,MKDEV(majornumber,0),NULL,DEVICE_NAME);
	if(IS_ERR(tdlchardevice))
	{
		class_destroy(tdlcharclass);
		unregister_chrdev(majornumber,DEVICE_NAME);
		printk(KERN_ALERT "failed to create the device\n");
		return PTR_ERR(tdlchardevice);
	}
	printk(KERN_INFO "tdlchar:device class created correctly\n");
	mutex_init(&tdlchar_mutex);
	return 0;
}

static void __exit tdlchar_exit(void)
{
	mutex_destroy(&tdlchar_mutex);
	device_destroy(tdlcharclass,MKDEV(majornumber,0));
	class_unregister(tdlcharclass);
	class_destroy(tdlcharclass);
	unregister_chrdev(majornumber,DEVICE_NAME);
	printk(KERN_INFO "TDLChar:goodbye\n");
}

static int dev_open(struct inode *inode,struct file *filep)
{
	if(!mutex_trylock(&tdlchar_mutex))
	{
		printk(KERN_INFO "Device in use by another process\n");
		return -EBUSY;
	}
	numberopens++;
	printk(KERN_INFO "device has been opened %d times\n",numberopens);
	return 0;
}

static ssize_t dev_read(struct file *filep,char *buffer,size_t len,loff_t *offset)
{
	int error_count=0;
	error_count = copy_to_user(buffer,message,sizeofmessage);
	if(error_count==0)
	{
		printk(KERN_INFO "sent %d characters to the user \n",sizeofmessage);
		return(sizeofmessage = 0);
	}
	else
	{
		printk(KERN_INFO "failed to send %d characters to the user \n",error_count);
		return -EFAULT;
	}
}

static char totheupper(const char inchar)
{
	char outchar=inchar;
	if(inchar>='a' && inchar<='z')
	{
		outchar=inchar - ('a' -'A');
	}
	return outchar;
}

static ssize_t dev_write(struct file *filep,const char *buffer,size_t len,loff_t *offset)
{
	int i;
	for(i=0;i<len;i++)
	{
		message[i]=totheupper(buffer[i]);
	}
	message[len]='\0';
	sizeofmessage=(strlen(*message));
	printk(KERN_INFO "recieved %zu chracters from the user\n",len);
	copy_from_user(message,buffer,sizeofmessage);
	return len;
}

static int dev_release(struct inode *inode,struct file *filep)
{
	mutex_unlock(&tdlchar_mutex);
	printk(KERN_INFO "Device successfully closed\n");
	return 0;
}

module_init(tdlchar_init);
module_exit(tdlchar_exit);
