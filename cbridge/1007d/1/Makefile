obj-m   := 1.o 
KDIR    := /lib/modules/$(shell uname -r)/build
PWD     := $(shell pwd) 
SYM=$(PWD) 
 
all: 
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
