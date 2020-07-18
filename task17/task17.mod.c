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
	{ 0x66f38678, "module_layout" },
	{ 0xdc3c46c1, "__asan_register_globals" },
	{ 0xe894f8f4, "__asan_unregister_globals" },
	{ 0x24074438, "misc_deregister" },
	{ 0x1d1166fb, "kthread_stop" },
	{ 0xd476c5f0, "misc_register" },
	{ 0x85fafafb, "wake_up_process" },
	{ 0x5291e552, "kthread_create_on_node" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xbb4f4766, "simple_write_to_buffer" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1000e51, "schedule" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");

