#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/wait.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/poll.h>
#include <linux/mutex.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14 B K Karthik");
MODULE_DESCRIPTION("Task 18 of The Eudyptula Challenge");

static DECLARE_WAIT_QUEUE_HEAD(wee_wait);

static struct task_struct *eudy_thread;

#define NAME_LENGTH 20

struct identity {
	char name[NAME_LENGTH];
	int id;
	bool busy;
	struct list_head list;
};

static LIST_HEAD(identity_list);
static int counter;

static DEFINE_MUTEX(identity_mutex);

static struct identity *identity_get(void)
{
	struct identity *temp;

	if (list_empty(&identity_list))
		return NULL;

	mutex_lock_interruptible(&identity_mutex);
	temp = list_entry(identity_list.next, struct identity, list);
	list_del(&temp->list);
	mutex_unlock(&identity_mutex);

	return temp;
}

static struct identity *identity_find(int id)
{
	struct identity *temp;

	list_for_each_entry(temp, &identity_list, list) {
		if (temp->id == id)
			return temp;
	}

	return NULL;
}

static int identity_create(char *name, int id)
{
	struct identity *temp;

	if (identity_find(id))
		return -EINVAL;

	temp = kmalloc(sizeof(*temp), GFP_KERNEL);
	if (!temp)
		return -EINVAL;

	mutex_lock_interruptible(&identity_mutex);
	strncpy(temp->name, name, NAME_LENGTH-1);
	temp->name[NAME_LENGTH-1] = '\0';
	temp->id = id;
	temp->busy = false;
	list_add(&(temp->list), &identity_list);
	mutex_unlock(&identity_mutex);

	pr_debug("Created identity: %s %i\n", temp->name, temp->id);
	return 0;

}

static int thread_main(void *data)
{
	struct identity *temp;

	while (1) {
		if (wait_event_interruptible(wee_wait, 1))
			return -ERESTARTSYS;

		if (kthread_should_stop())
			break;

		temp = identity_get();

		if (temp) {
			msleep_interruptible(5000);
			pr_debug("Got identity: %s %i\n", temp->name, temp->id);
			kfree(temp);
		}
	}
	return 0;
}

static ssize_t my_write(struct file *file, char const __user *buf,
			size_t count, loff_t *ppos)
{
	char input[NAME_LENGTH];
	int real_count = (count >= NAME_LENGTH) ? NAME_LENGTH-1 : count;

	memset(input, '\0', NAME_LENGTH);

	if (copy_from_user(input, buf, real_count))
		return -EINVAL;

	if (identity_create(input, counter))
		return -EINVAL;

	counter++;
	wake_up(&wee_wait);
	return count;
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
	char *mythread = "eudyptula";

	eudy_thread = kthread_run(thread_main, NULL, mythread);
	if (eudy_thread == ERR_PTR(-ENOMEM))
		return -ENOMEM;

	return misc_register(&my_dev);
}

static void __exit my_exit(void)
{
	struct identity *temp, *next;

	kthread_stop(eudy_thread);
	misc_deregister(&my_dev);
	list_for_each_entry_safe(temp, next, &identity_list, list) {
		list_del(&temp->list);
		kfree(temp);
	}
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
