#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7ba62dba, "module_layout" },
	{ 0x4a16f3de, "debugfs_remove_recursive" },
	{ 0x7c32d0f0, "printk" },
	{ 0x9b7fe4d4, "__dynamic_pr_debug" },
	{ 0x96f2ecf4, "debugfs_create_file" },
	{ 0xf35e130e, "debugfs_create_dir" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0xbb4f4766, "simple_write_to_buffer" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xbdfb6dbb, "__fentry__" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

