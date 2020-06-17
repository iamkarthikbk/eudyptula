// SPDX-License-Identifier: GPL-2.0
/*
 * task05.c
 */

#include<linux/init.h>
#include<linux/module.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14 B K Karthik");

static int __init my_init(void)
{
	pr_debug("A USB Device was connected! - eudyptula-a24a6bdd6a14");
	return 0;
}

static void __exit my_exit(void)
{
	pr_debug("A USB Device was connected! - eudyptula-a24a6bdd6a14");
}

static struct usb_device_id usb_kbd_id_table[] = {
{ USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
	USB_INTERFACE_SUBCLASS_BOOT,
	USB_INTERFACE_PROTOCOL_KEYBOARD) },
{}
};

MODULE_DEVICE_TABLE(usb, usb_kbd_id_table);

module_init(my_init);
module_exit(my_exit);

//https://stackoverflow.com/questions/28369300/how-to-load-a-module-not-a-driver-when-a-usb-device-is-plugged-in was used as a reference.
