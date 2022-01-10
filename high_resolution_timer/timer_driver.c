#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>

//timer variable
#define TIMEOUT_NSEC    (1000000000L)
#define TIMEOUT_SEC      (4)

static struct hrtimer etx_hr_timer;
static unsigned int count = 0;

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;

static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);

static int etx_open(struct inode *inode,struct file *file);
static int etx_release(struct inode *inode,struct file *file);
static ssize_t etx_read(struct file *filp,char __user *buf,size_t len,loff_t *off);
static ssize_t etx_write(struct file *filp,const char __user *buf,size_t len,loff_t *off);

static struct file_operations fops=
{
	.owner   = THIS_MODULE,
	.open    = etx_open,
	.release = etx_release,
	.read    = etx_read,
	.write   = etx_write,
};

enum hrtimer_restart timer_callback(struct hrtimer *timer)
{
	printk(KERN_INFO "timer callback function called [%d]\n",count++);
	hrtimer_forward_now(timer,ktime_set(TIMEOUT_SEC,TIMEOUT_NSEC));
	return HRTIMER_RESTART;
}

static int etx_open(struct inode *inode,struct file *file)
{
	printk(KERN_INFO "Device file opened...\n");
	return 0;
}

static int etx_release(struct inode *inode,struct file *file)
{
	printk(KERN_INFO "Device file closed.....\n");
	return 0;
}

static ssize_t etx_read(struct file *filp,char __user *buf,size_t len,loff_t *off)
{
	printk(KERN_INFO "Read functionality....\n");
	return 0;
}

static ssize_t etx_write(struct file *filp,const char __user *buf,size_t len,loff_t *off)
{
	printk(KERN_INFO "Write functionality...\n");
	return len;
}

static int __init etx_driver_init(void)
{
	ktime_t ktime;
	if((alloc_chrdev_region(&dev,0,1,"etx_dev")) < 0)
	{
		printk(KERN_ERR "cannot allocate major number\n");
		return -1;
	}
	printk(KERN_INFO "Major = %d Minor = %d \n",MAJOR(dev),MINOR(dev));

	cdev_init(&etx_cdev,&fops);

	if((cdev_add(&etx_cdev,dev,1))  < 0)
	{
		printk(KERN_INFO "Caannot add the device to the system\n");
		goto r_class;
	}
	if((dev_class = class_create(THIS_MODULE,"etx_class")) == NULL)
	{
		printk(KERN_INFO "Cannot create the struct class\n");
		goto r_class;
	}
	if((device_create(dev_class,NULL,dev,NULL,"etx_device")) == NULL)
	{
		printk(KERN_INFO "Cannot create the device\n");
		goto r_device;
	}

	ktime = ktime_set(TIMEOUT_SEC,TIMEOUT_NSEC);
	hrtimer_init(&etx_hr_timer,CLOCK_MONOTONIC,HRTIMER_MODE_REL);
	etx_hr_timer.function = &timer_callback;
	hrtimer_start(&etx_hr_timer,ktime,HRTIMER_MODE_REL);
	printk(KERN_INFO "Device driver insert .... Done !!!\n");
	return 0;

r_device:
	class_destroy(dev_class);
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}

static void __exit etx_driver_exit(void)
{
	hrtimer_cancel(&etx_hr_timer);
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&etx_cdev);
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO "Device driver remove....Done\n");
}

module_init(etx_driver_init);
module_exit(etx_driver_exit);

MODULE_LICENSE("GPL");
