#include<linux/kernel.h>
#include<linux/module.h>

static void __exit hello_exit(void)
{
	printk(KERN_INFO "function: %s from %s file",__func__,__FILE__);
	printk(KERN_ALERT "we are in exit function\n");
}
module_exit(hello_exit);

MODULE_LICENSE("GPL");

