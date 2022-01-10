#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bunny");

static int my_add(int a,int b)
{
return (a+b);
}

EXPORT_SYMBOL(my_add);

static int __init expsym_init(void)
{
printk(KERN_ALERT "\nInitialization of module\n");
return 0;
}

static void __exit expsym_exit(void)
{
printk(KERN_ALERT "good bye\n");
}

module_init(expsym_init);
module_exit(expsym_exit);
