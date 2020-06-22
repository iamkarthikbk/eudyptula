#include <linux/module.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/errno.h>
#include <linux/debugfs.h>
#include <linux/jiffies.h>
#include <linux/semaphore.h>

#define TLF_ID "a24a6bdd6a14"
#define TLF_ID_LENGTH 13   /* TLF_ID length */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14");
MODULE_DESCRIPTION("TASK 08 of THE EUDYPTULA CHALLENGE");

static DEFINE_SEMAPHORE(foo_sem);

static char foo_data[PAGE_SIZE];
static int foo_len;

static struct dentry *eudy;

static ssize_t id_read(struct file *file, char __user *buff,
			size_t count, loff_t *ppos)
{
	char *print_str = TLF_ID;
	int len = TLF_ID_LENGTH;

	return simple_read_from_buffer(buff, count, ppos, print_str, len);
}

static ssize_t id_write(struct file *file, char const __user *buff,
			size_t count, loff_t *ppos)
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

static const struct file_operations id_fops = {
	.owner = THIS_MODULE,
	.read = id_read,
	.write = id_write
};

static ssize_t foo_read(struct file *file, char __user *buff,
			size_t count, loff_t *ppos)
{
	int retval = -EINVAL;

	if (*ppos != 0)
		return 0;

	down(&foo_sem);

	if (!copy_to_user(buff, foo_data, foo_len)) {
		*ppos += count;
		retval = count;
	}

	up(&foo_sem);
	return retval;
}

static ssize_t foo_write(struct file *file, char const __user *buff,
			size_t count, loff_t *ppos)
{
	int retval = -EINVAL;

	if (count >= PAGE_SIZE)
		return -EINVAL;

	down(&foo_sem);

	if (copy_from_user(foo_data, buff, count)) {
		foo_len = 0;
	} else {
		foo_len = count;
		retval = count;
	}

	up(&foo_sem);
	return retval;
}

static const struct file_operations foo_fops = {
	.owner = THIS_MODULE,
	.read = foo_read,
	.write = foo_write
};

static int __init my_init(void)
{
	eudy = debugfs_create_dir("eudyptula", NULL);
	debugfs_create_file("id", 0666, eudy, NULL, &id_fops);
	debugfs_create_u32("jiffies", 0444, eudy, (u32*)&jiffies);
	debugfs_create_file("foo", 0644, eudy, NULL, &foo_fops);
	pr_debug("Hello World!\n");
	return 0;
}

static void __exit my_exit(void)
{
	debugfs_remove_recursive(eudy);
}

module_init(my_init);
module_exit(my_exit);
