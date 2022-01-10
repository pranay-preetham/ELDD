#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
#include<linux/kernel.h>
#include<linux/kern_levels.h>

int myint=120;
char *mystring = "Bunny";
int arr[2] = {1,2};
static int arr_count=0;

module_param(myint,int,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
MODULE_PARM_DESC(myint, "an integer");

module_param(mystring,charp,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
MODULE_PARM_DESC(mystring, "A character string");

static int __init parameter_init(void)
{
int i;
printk(KERN_ALERT "hello world\n");
printk(KERN_ALERT "my integer is %d\n",myint);
printk(KERN_ALERT "my string is %s\n",mystring);
for(i=0;i<2;i++)
{
printk(KERN_ALERT "\narr[%d] = %d\n",i,arr[i]);
}
arr_count=i;
printk(KERN_ALERT "the no. of elements in array are %d\n",arr_count);
return 0;
}

static void __exit parameter_exit(void)
{
	printk(KERN_ALERT "Goodbye\n");
}

module_init(parameter_init);
module_exit(parameter_exit);
MODULE_LICENSE("GPL");
