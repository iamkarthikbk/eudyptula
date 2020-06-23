#include <linux/module.h>
#include <linux/semaphore.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/poll.h>
#include <linux/kobject.h>
#include <linux/jiffies.h>

#define TLF_ID "a24a6bdd6a14"
#define TLF_ID_LENGTHGTH 13

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14");
MODULE_DESCRIPTION("[SYSFS] Task 09 of The Eudyptula Challenge");

static DEFINE_MUTEX(foo_mutex);
static char foo_data[PAGE_SIZE];
static int foo_len;

static struct kobject *my_kobj;

static ssize_t id_read(struct kobject *kobj, struct kobj_attribute *attr, char *buff)
{
	char *print_str = TLF_ID;

	strncpy(buff, print_str, TLF_ID_LENGTH);
	return TLF_ID_LENGTH;
}

static ssize_t id_write(struct kobject *kobj, struct kobj_attribute *attr, const char *buff, size_t count)
{
	char *print_str = TLF_ID;

	if (strncmp(print_str, buff, TLF_ID_LENGTH) || count != TLF_ID_LENGTH)
		return -EINVAL;
	else
		return TLF_ID_LENGTH;
}

static ssize_t jiffies_read(struct kobject *kobj, struct kobj_attribute *attr, char *buff)
{
	return sprintf(buff, "%lu\n", jiffies);
}

static ssize_t jiffies_write(struct kobject *kobj, struct kobj_attribute *attr, const char *buff, size_t count)
{
	return -EINVAL;
}

static ssize_t foo_read(struct kobject *kobj, struct kobj_attribute *attr, char *buff)
{
	mutex_lock(&foo_mutex);
	strncpy(buff, foo_data, foo_len);
	mutex_unlock(&foo_mutex);

	return foo_len;
}

static ssize_t foo_write(struct kobject *kobj, struct kobj_attribute *attr, const char *buff, size_t count)
{
	if (count > PAGE_SIZE)
		return -EINVAL;

	mutex_lock(&foo_mutex);
	strncpy(foo_data, buff, count);
	foo_len = count;
	mutex_unlock(&foo_mutex);

	return count;
}


static struct kobj_attribute id_attribute = __ATTR(id, 0666, id_read, id_write);
static struct kobj_attribute jiffies_attribute = __ATTR(jiffies, 0444, jiffies_read, jiffies_write);
static struct kobj_attribute foo_attribute = __ATTR(foo, 0644, foo_read, foo_write);

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
