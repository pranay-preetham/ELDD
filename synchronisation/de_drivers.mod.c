#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
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
__used __section("__versions") = {
	{ 0xbd97005b, "module_layout" },
	{ 0xdd82b8cb, "class_unregister" },
	{ 0xc65b2c7a, "device_destroy" },
	{ 0xe346f67a, "__mutex_init" },
	{ 0xafe18e20, "class_destroy" },
	{ 0xfada38fe, "device_create" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xd9379699, "__class_create" },
	{ 0x6d266982, "__register_chrdev" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x5f754e5a, "memset" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x2cfde9a2, "warn_slowpath_fmt" },
	{ 0x97255bdf, "strlen" },
	{ 0xdd4ffa9b, "mutex_trylock" },
	{ 0xc5850110, "printk" },
	{ 0x67ea780, "mutex_unlock" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "79F686DE2BAD3AFE5491FB3");
