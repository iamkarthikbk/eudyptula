// SPDX-License-Identifier: GPL-2.0
/*
 * task06.c
 */

#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/errno.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14 B K Karthik");
MODULE_DESCRIPTION("Misc char device driver with read and write operations. Task 06 of the eudyptula challenge");

#define TLF_ID "a24a6bdd6a14"
#define TLF_ID_LENGTH 13

static ssize_t my_read(struct file *file, char __user *buff, size_t count, loff_t *ppos)
{
	char *print_str = TLF_ID;

	if (*ppos != 0)
		return 0;
	if ((count < TLF_ID_LENGTH) || (copy_to_user(buff, print_str, TLF_ID_LENGTH)))
		return -EINVAL;
	*ppos += count;
	return count;
}

static ssize_t my_write(struct file *file, char const __user *buff, size_t count, loff_t *ppos)
{
	char *print_str = TLF_ID;
	char input[TLF_ID_LENGTH];

	if ((count != TLF_ID_LENGTH) ||
		(copy_from_user(input, buff, TLF_ID_LENGTH)) ||
		(strncmp(print_str, input, TLF_ID_LENGTH - 1)))
		return -EINVAL;
	else
		return count;
}

static const struct file_operations my_fops = {
	.owner = THIS_MODULE,
	.read = my_read,
	.write = my_write
};

static struct miscdevice my_dev = {
	MISC_DYNAMIC_MINOR,
	"eudyptula",
	&my_fops
};

static int __init my_init(void)
{
	int ret;

	ret = misc_register(&my_dev);
	pr_debug("Hello world! a24a6bdd6a14");
	return ret;
}

static void __exit my_exit(void)
{
	misc_deregister(&my_dev);
}

module_init(my_init);
module_exit(my_exit);

//https://www.linuxjournal.com/article/2920 was used as a reference.
//https://www.tldp.org/LDP/lkmpg/2.6/html/x569.html was used as a reference.
