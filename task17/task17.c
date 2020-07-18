// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/miscdevice.h>
#include <linux/poll.h>
#include <linux/wait.h>
#include <linux/errno.h>

#define LFID "a24a6bdd6a14"
#define LFID_LENGTH 13

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14 B K Karthik");
MODULE_DESCRIPTION("Task 17 of The Eudyptula Challenge");

DECLARE_WAIT_QUEUE_HEAD(wee_wait);

static struct task_struct  * my_thread;

static int thread_init(void *data)
{
	while (true) {
		if (wait_event_interruptible(wee_wait, kthread_should_stop()))
			return -ERESTARTSYS;

		if (kthread_should_stop())
			break;
	}

	return 0;
}

static ssize_t my_write(struct file *file, const char __user *buff, size_t count, loff_t *ppos)
{
	char *print_str = LFID;
	char input[LFID_LENGTH];
	int len = LFID_LENGTH;
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
	.write = my_write
};

static struct miscdevice my_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "eudyptula",
	.fops = &my_fops,
	.mode = 0222
};

static int __init my_init(void)
{
	char *eudy_thread = "eudyptula";

	my_thread = kthread_run(thread_init, NULL, eudy_thread);
	if (my_thread == ERR_PTR(-ENOMEM))
		return -ENOMEM;

	return misc_register(&my_dev);
}

static void __exit my_exit(void)
{
	kthread_stop(my_thread);
	misc_deregister(&my_dev);
}

module_init(my_init);
module_exit(my_exit);

/*
 * https://lwn.net/Articles/577370/ was used as a reference.
 * https://www.kernel.org/doc/htmldocs/kernel-hacking/queues.html was used as a reference.
 * https://sysplay.in/blog/tag/wait-queues/ was used as a reference.
 * https://stackoverflow.com/questions/9481055/what-is-a-kernel-thread#:~:text=A%20kernel%20thread%20is%20a,t%20know%20what%20they%20are. was used as a reference.
 * https://sysplay.in/blog/tag/kernel-threads/ was used as a reference.
 * https://lwn.net/Articles/65178/ was used as a reference.
 */
