#include <linux/module.h> //required for all kernel modules
#include <linux/kernel.h> //for KERN_INFO
#include <linux/init.h>   //for __init and __exit macros

MODULE_LICENSE("GNU General Public License v3");
MODULE_AUTHOR("B K Karthik a24a6bdd6a14");
MODULE_DESCRIPTION("[a24a6bdd6a14] Task 01 results");

static int __init my_init(void)
{
	printk(KERN_DEBUG "Hello world!");
	return 0;
}

static void __exit my_exit(void)
{
	printk(KERN_DEBUG "Exiting [a24a6bdd6a14] Task 01 results");
}

module_init(my_init);
module_exit(my_exit);
//The following webpage was used as a reference. "https://www.thegeekstuff.com/2013/07/write-linux-kernel-module/"
