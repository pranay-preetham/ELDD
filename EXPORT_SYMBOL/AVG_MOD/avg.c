#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include "add.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BUNNY");

static int avg_init(void)
{
	int sum = add(2,4);
	printk("Average = %d",(sum/2));
	return 0;
}

static void avg_exit(void)
{
	printk("Average calculated");
}

module_init(avg_init);
module_exit(avg_exit);


