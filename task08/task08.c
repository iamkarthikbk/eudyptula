#include <linux/module.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/errno.h>
#include <linux/debugfs.h>
#include <linux/jiffies.h>
#include <linux/semaphore.h>

#define TLF_ID "a24a6bdd6a14"
#define TLF_ID_LEN 13   /* TLF_ID length */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14");
MODULE_DESCRIPTION("TASK 08 of THE EUDYPTULA CHALLENGE");

static ssize_t id_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
	char *hello_str = TLF_ID;

	if (*ppos != 0)
		return 0;

	if ((count < TLF_ID_LEN) ||
		(copy_to_user(buf, hello_str, TLF_ID_LEN)))
		return -EINVAL;

	*ppos += count;
	return count;
}

static ssize_t id_write(struct file *file, char const __user *buf,
			size_t count, loff_t *ppos)
{
	char *hello_str = TLF_ID;
	char input[TLF_ID_LEN];

	if ((count != TLF_ID_LEN) ||
		(copy_from_user(input, buf, TLF_ID_LEN)) ||
		(strncmp(hello_str, input, TLF_ID_LEN)))
		return -EINVAL;
	else
		return count;
}

static const struct file_operations id_fops = {
	.owner = THIS_MODULE,
	.read = id_read,
	.write = id_write
};

static int __init my_init(void)
{
	eudy = debugfs_create_dir("eudyptula", NULL);
	if (!eudy)
		goto fail;

	if (!debugfs_create_file("id", 0666, eudy, NULL, &id_fops))
		goto fail;

	pr_debug("Hello World!\n");
	foo_len = 0;
	return 0;

fail:	pr_alert("Could not create devices");
	return -ENODEV;
}

static void __exit my_exit(void)
{
	debugfs_remove_recursive(eudy);
}

module_init(my_init);
module_exit(my_exit);
