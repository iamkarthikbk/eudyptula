#include <linux/module.h>
#include <linux/semaphore.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/poll.h>
#include <linux/kobject.h>
#include <linux/jiffies.h>

#define TLF_ID "a24a6bdd6a14"
#define TLF_ID_LENGTH 13

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14 B K Karthik");
MODULE_DESCRIPTION("[SYSFS] Task 09 of The Eudyptula Challenge");

static DEFINE_MUTEX(foo_mutex);
static char foo_data[PAGE_SIZE];
static int foo_len;

static struct kobject *my_kobj;

static ssize_t id_show(struct kobject *kobj, struct kobj_attribute *attr,
				char *buff)
{
	char *print_str = TLF_ID;

	strncpy(buff, print_str, TLF_ID_LENGTH);
	return TLF_ID_LENGTH;
}

static ssize_t id_store(struct kobject *kobj, struct kobj_attribute *attr,
				const char *buff, size_t count)
{
	char *print_str = TLF_ID;

	if (strncmp(print_str, buff, TLF_ID_LENGTH)) {
		return -EINVAL;
	}
	else
		return TLF_ID_LENGTH;
}

static ssize_t jiffies_show(struct kobject *kobj,
				struct kobj_attribute *attr, char *buff)
{
	return sprintf(buff, "%lu\n", jiffies);
}

static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr,
				char *buff)
{
	mutex_lock(&foo_mutex);
	strncpy(buff, foo_data, foo_len);
	mutex_unlock(&foo_mutex);

	return foo_len;
}

static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr,
				const char *buff, size_t count)
{
	if (count > PAGE_SIZE)
		return -EINVAL;

	mutex_lock(&foo_mutex);
	strncpy(foo_data, buff, count);
	foo_len = count;
	mutex_unlock(&foo_mutex);

	return count;
}


static struct kobj_attribute id_attribute = __ATTR_RW(id);
static struct kobj_attribute jiffies_attribute = __ATTR_RO(jiffies);
static struct kobj_attribute foo_attribute = __ATTR_RW(foo);

static struct attribute *attrs[] = {
	&id_attribute.attr,
	&jiffies_attribute.attr,
	&foo_attribute.attr,
	NULL,
};

static struct attribute_group my_group = {
	.attrs = attrs,
};

static int __init my_init(void)
{
	int retval;

	my_kobj = kobject_create_and_add("eudyptula", kernel_kobj);
	if (!my_kobj)
		return -ENOMEM;

	retval = sysfs_create_group(my_kobj, &my_group);
	if (retval)
		kobject_put(my_kobj);

	pr_debug("Hello World! I am Task 09 of The Eudyptula Challenge");
	return retval;
}

static void __exit my_exit(void)
{
	kobject_put(my_kobj);
}

module_init(my_init);
module_exit(my_exit);

/*https://www.kernel.org/doc/Documentation/kobject.txt
 *	 was used as a reference.
 *https://www.google.com/url?sa=t&source=web&rct=j&url=
 *	https://www.cs.swarthmore.edu/~newhall/
 *	sysfstutorial.pdf&ved=2ahUKEwj134KJhJbqAhX5yDgG
 *	HZhHAWgQFjACegQIBBAB&usg=AOvVaw3vtjGN2zji2DU5x_
 *	aLtQCr was used as a reference.
 *https://www.linuxfoundation.org/blog/2013/06/
 *	how-to-create-a-sysfs-file-correctly/
 *	was used as a reference.
 *https://www.thegeekdiary.com/
 *	understanding-the-sysfs-file-system-in-linux/amp/
 *	was used as a reference.
 *https://www.linux.com/news/how-create-sysfs-file-correctly/
 *	was used as a reference.
 *http://pradheepshrinivasan.github.io/2015/07/02/
 *	Creating-an-simple-sysfs/ was used as a reference.
 *https://www.geeksforgeeks.org/mutex-vs-semaphore/
 *	was used as a reference.
 *https://stackoverflow.com/questions/62814/
 *	difference-between-binary-semaphore-and-mutex
 *	was used as a reference.
 *https://www.justsoftwaresolutions.co.uk/threading/
 *	locks-mutexes-semaphores.html was used as a reference.
 *http://lkml.iu.edu/hypermail/linux/kernel/0707.2/1361.html
 *	was used as a reference.
 *https://lore.kernel.org/patchwork/patch/416778/
 *	was used as a reference.
 *https://unix.stackexchange.com/questions/302003/
 *	shared-access-of-sysfs was used as a reference.
 *https://unix.stackexchange.com/questions/594504/
 *	negetive-width-in-bit-field-anonymous-while-running
 *	-make was used as a reference.
 *https://www.kernel.org/doc/Documentation/filesystems/sysfs.txt
 *	was used as a reference;
 */
