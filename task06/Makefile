CFLAGS_task06.c = -DDEBUG

obj-m += task06.o

ARB_DIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(ARB_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(ARB_DIR) M=$(PWD) clean
