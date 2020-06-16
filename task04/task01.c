// SPDX-License-Identifier: GPL-2.0
/*
 * helloworld.c
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14");
MODULE_DESCRIPTION("Task 01 of the Eudyptula Challenge");

static int hello_init(void)
{
	pr_debug("Hello World!\n");
	return 0;
}

static void hello_exit(void)
{
	pr_debug("Exiting [a24a6bdd6a14] Task 01.\n");
}

module_init(hello_init);
module_exit(hello_exit);

