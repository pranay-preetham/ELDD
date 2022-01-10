##ifneq($(KERNELRELEASE),)
	obj-m :=char_driver.o
##else
	KERNELDIR = /lib/modules/$(shell uname -r)/build
	PWD :=$(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	gcc -o test_app test_app.c

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
	rm test_app
install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install
#endif
