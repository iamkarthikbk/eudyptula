obj-m += task01.o
ARB_DIR := /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(ARB_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(ARB_DIR) M=$(PWD) clean
