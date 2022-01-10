#include<linux/kernel.h>
#include<linux/module.h>

static int __init hello_init(void)
{
	printk(KERN_INFO "function : %s from %s file",__func__,__FILE__);
	printk(KERN_ALERT "we are in init function\n");
	return 0;
}

module_init(hello_init);

MODULE_LICENSE("GPL");

