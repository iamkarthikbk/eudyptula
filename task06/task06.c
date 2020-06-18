// SPDX-License-Identifier: GPL-2.0
/*
 * task06.c
 */

#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/errno.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14 B K Karthik");
MODULE_DESCRIPTION("Misc char device driver with read and write operations. Task 06 of the eudyptula challenge");

#define TLF_ID "a24a6bdd6a14"
#define TLF_ID_LENGTH 13

static ssize_t my_read(struct file *file, char __user *buff, size_t count, loff_t *ppos)
{
	char *print_str = TLF_ID;
	int len = TLF_ID_LENGTH;

	return simple_read_from_buffer(buff, count, ppos, print_str, len);
}

static ssize_t my_write(struct file *file, char const __user *buff, size_t count, loff_t *ppos)
{
	char *print_str = TLF_ID;
	char input[TLF_ID_LENGTH];
	int len = TLF_ID_LENGTH;
	ssize_t retval = -EINVAL;

	if (count != len)
		return retval;

	retval = simple_write_to_buffer(input, count, ppos, buff, count);

	if (retval < 0)
		return retval;

	retval = strncmp(print_str, input, count) ? count : -EINVAL;
	return retval;
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
//https://gist.github.com/chuckleberryfinn/e50a938083ec355563efc9da1f2fa904 was used as a reference.
