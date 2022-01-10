#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/string.h>
#include<asm/uaccess.h>

MODULE_LICENSE("GPL");

static char ker_buf[100];

static int dev_open(struct inode *inod,struct file *fil);
static ssize_t dev_read(struct file *filep,char *buf,size_t len,loff_t *off);
static ssize_t dev_write(struct file *filp,const char *buff,size_t len,loff_t *off);
static int dev_release(struct inode *inod,struct file *fil);

static struct file_operations fops=
{
	.read=dev_read,
	.write=dev_write,
	.open=dev_open,
	.release=dev_release,
};

static int hello_init(void)
{
	int t=register_chrdev(90,"mydev",&fops);
	if(t<0)
	printk(KERN_ALERT "device registration failed");
	else
		printk(KERN_ALERT "device registered\n");
	return 0;
}

static void hello_exit(void)
{
	unregister_chrdev(90,"mydev");
	printk(KERN_ALERT "exit");
}

static int dev_open(struct inode *inod,struct file *fil)
{
	printk(KERN_ALERT "device opened");
	return 0;
}

static ssize_t dev_read(struct file *filep,char *buf,size_t len,loff_t *off)
{
	copy_to_user(buf,ker_buf,len);
	return len;
}

static ssize_t dev_write(struct file *filp,const char *buf,size_t len,loff_t *off)
{
	copy_from_user(ker_buf,buf,len);
	ker_buf[len]=0;
	return len;
}

static int dev_release(struct inode *inod,struct file *fil)
{
	printk(KERN_ALERT "device closed\n");
	return 0;
}

module_init(hello_init);
module_exit(hello_exit);

