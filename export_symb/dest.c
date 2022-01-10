#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
#include"my_add.h"

MODULE_LICENSE("GPL");

static int one = 10;
static int two = 20;

static int __init add_init(void)
{
printk(KERN_ALERT "we are going to add\n");
printk(KERN_ALERT "The result is %d\n",my_add(one,two));
return 0;
}

static void __exit add_exit(void)
{
printk(KERN_ALERT "good bye all\n");
}

module_init(add_init);
module_exit(add_exit);
