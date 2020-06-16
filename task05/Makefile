CFLAGS_task05.o = -DDEBUG

obj-m += task05.o

ARB_DIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(ARB_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(ARB_DIR) M=$(PWD) clean
