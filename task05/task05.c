// SPDX-License-Identifier: GPL-2.0
/*
 * task05.c
 */

#include <linux/usb.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hid.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14 B K Karthik");
MODULE_DESCRIPTION("Eudyptula Challenge Task 05 When any USB keyboard is plugged in, the module will be automatically loaded by the correct userspace hotplug tools");

static int device_connect(struct usb_interface *interface, const struct usb_device_id *id)
{
	pr_alert("A USB Device was detected\n");
	return 0;
}

static void device_disconnect(struct usb_interface *interface)
{
	pr_alert("A USB Device was disconnected\n");
}

static const struct usb_device_id id_table[] = {
	{USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT, USB_INTERFACE_PROTOCOL_KEYBOARD)
	},
	{},
};

MODULE_DEVICE_TABLE(usb, id_table);

static struct usb_driver init_driver = {
	.name = "USBDevice",
	.probe = device_connect,
	.disconnect = device_disconnect,
	.id_table = id_table,
};

static int __init my_init(void)
{
	pr_debug("Hello world!\n");
	return usb_register(&init_driver);
}

static void __exit my_exit(void)
{
	pr_debug("[a24a6bdd6a14] Task 05 exiting\n");
	usb_deregister(&init_driver);
}

module_init(my_init);
module_exit(my_exit);

/*
 * REFERENCE by Grek Kroah-Hartman https://kernel.readthedocs.io/en/sphinx-samples/writing_usb_driver.html
 */
