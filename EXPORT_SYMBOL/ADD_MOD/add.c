#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BUNNY");

static int add(int x,int y)
{
	return(x+y);
}

EXPORT_SYMBOL_GPL(add);

static int fun1_init(void)
{
	printk("\nExplicitly added symbol\n");
	return 0;
}

static void fun1_exit(void)
{
	printk("\nCleanup\n");
}

module_init(fun1_init);
module_exit(fun1_exit);

