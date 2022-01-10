#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/interrupt.h>
#include<linux/delay.h>

#ifndef DECLARE_TASKLET_OLD
#define DECLARE_TASKLET_OLD(arg1,arg2) DECLARE_TASKLET(arg1,arg2,0L)
#endif

static void tasklet_fn(unsigned long data)
{
	printk(KERN_INFO "tasklet starts\n");
	mdelay(5000);
	printk(KERN_INFO "tasklet ends\n");
}

static DECLARE_TASKLET_OLD(mytask,tasklet_fn);
static int example_tasklet_init(void)
{
	printk(KERN_INFO "we have started tasklet init\n");
	tasklet_schedule(&mytask);
	mdelay(200);
	printk(KERN_INFO "init contiues\n");
	return 0;
}

static void example_tasklet_exit(void)
{
	printk(KERN_INFO "tasklet exits\n");
	tasklet_kill(&mytask);
}

module_init(example_tasklet_init);
module_exit(example_tasklet_exit);
