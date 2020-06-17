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

static int __init usb_skel_init(void)
{
        int result;

        /* register this driver with the USB subsystem */
        result = usb_register(&skel_driver);
        if (result < 0) {
                err("usb_register failed for the "__FILE__ "driver."
                    "Error number %d", result);
                return -1;
        }

        return 0;
}

static void __exit usb_skel_exit(void)
{
        /* deregister this driver with the USB subsystem */
        usb_deregister(&skel_driver);
}

/* table of devices that work with this driver */
static struct usb_device_id skel_table [] = {
        { USB_DEVICE(USB_SKEL_VENDOR_ID, USB_SKEL_PRODUCT_ID) },
        { }                      /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, skel_table);

static int skel_probe(struct usb_interface *interface,
    const struct usb_device_id *id);

module_init(usb_skel_init);
module_exit(usb_skel_exit);
