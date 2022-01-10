#include<linux/init.h>
#include<linux/interrupt.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/spinlock.h>

static DEFINE_SPINLOCK(sl_static);
static DEFINE_SPINLOCK(sl_dynamic);
//static spinlock sl_dynamic;
//static spinlock s1_static;

static void example_spinlock_static(void)
{
	unsigned long flags;
	spin_lock_irqsave(&sl_static,flags);
	printk(KERN_ALERT "locked static spinlock\n");
	printk(KERN_ALERT "this is Bunny\n");
	spin_unlock_irqrestore(&sl_static,flags);
	printk(KERN_ALERT "unlocked static spinlock\n");

}
static void example_spinlock_dynamic(void)
{
        unsigned long flags;
        spin_lock_irqsave(&sl_dynamic,flags);
        printk(KERN_ALERT "locked static spinlock\n");
        printk(KERN_ALERT "this is Bunny\n");
        spin_unlock_irqrestore(&sl_dynamic,flags);
	printk(KERN_ALERT "Unlocked dynamic spinlock\n");
}

static int example_spinlock_init(void)
{
	printk(KERN_ALERT "the example of spinlock is started\n");
	example_spinlock_static();
	example_spinlock_dynamic();
	return 0;
}

static void example_spinlock_exit(void)
{
	printk(KERN_ALERT "spinlock exit\n");
}

module_init(example_spinlock_init);
module_exit(example_spinlock_exit);

MODULE_LICENSE("GPL");
