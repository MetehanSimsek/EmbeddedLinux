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
	{ 0x3726c6aa, "module_layout" },
	{ 0xfe990052, "gpio_free" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x2f129604, "gpiod_direction_output_raw" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x526c3a6c, "jiffies" },
	{ 0xc5850110, "printk" },
	{ 0x6eb0fe6d, "gpiod_set_raw_value" },
	{ 0xe62ca738, "gpio_to_desc" },
};

MODULE_INFO(depends, "");

