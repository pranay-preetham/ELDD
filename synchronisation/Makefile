 obj-m := de_drivers.o
 KERNELDIR = /lib/modules/$(shell uname -r)/build
 PWD := $(shell pwd)

all:
	make -C $(KERNELDIR) M=$(PWD) modules
	$(CC) test_app.c -o test_app
clean:
	make -C $(KERNELDIR) M=$(PWD) clean
	rm test_app
