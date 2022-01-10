#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

int Hello=1;
// module_param(Hello,int,S_IRUGO);

static int __init helloworld_init(void)
{
	printk("Hello Boys\n");
	return 0;
}

static void __exit helloworld_exit(void)
{
	printk("Bye\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);


