obj-m := add.o
KDIR = /lib/modules/$(shell uname -r)/build/
PWD := $(shell pwd)
all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -rf /lib/modules/$(shell uname -r)/extra/*
intsall:
	make -C $(KDIR) M=$(PWD) modules_install
	depmod -a
