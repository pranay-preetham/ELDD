#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched.h>
#include<linux/tty.h>

static void print_string(char *str)
{
	struct tty_struct *my_tty = get_current_tty();
	if(my_tty)
	{
	const struct tty_operations *ttyops = my_tty->driver->ops;
	(ttyops->write)(my_tty,str,strlen(str));
	(ttyops->write)(my_tty, "\015\012",2);
	}
}

static int __init print_string_init(void)
{
	print_string("this module has been inserted. Hello world!\n");
	return 0;
}

static void __exit print_string_exit(void)
{
	print_string("This module has been removed.Good bye\n");
}

module_init(print_string_init);
module_exit(print_string_exit);

MODULE_LICENSE("GPL");
