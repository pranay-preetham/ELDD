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
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xafe18e20, "class_destroy" },
	{ 0xc65b2c7a, "device_destroy" },
	{ 0xfada38fe, "device_create" },
	{ 0xd9379699, "__class_create" },
	{ 0x6d266982, "__register_chrdev" },
	{ 0x72664a4, "try_module_get" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xdd72b1c1, "module_put" },
	{ 0xc5850110, "printk" },
	{ 0xbb72d4fe, "__put_user_1" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8A6BD914B25FE43D1985529");
