#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
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
__used __section(__versions) = {
	{ 0x1d172e8b, "module_layout" },
	{ 0xdc3c46c1, "__asan_register_globals" },
	{ 0xe894f8f4, "__asan_unregister_globals" },
	{ 0xed547d20, "kmem_cache_destroy" },
	{ 0x95882f13, "kmem_cache_create" },
	{ 0x5995a478, "kmem_cache_free" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x8c140f86, "__asan_store8_noabort" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0x876c131a, "__asan_store4_noabort" },
	{ 0x800e1a73, "__asan_store1_noabort" },
	{ 0x9166fada, "strncpy" },
	{ 0x52732999, "kmem_cache_alloc" },
	{ 0x8d16e664, "__asan_load8_noabort" },
	{ 0x866efaf8, "__asan_load4_noabort" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");

