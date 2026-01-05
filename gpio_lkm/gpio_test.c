#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/timer.h>
#include <linux/jiffies.h>

#define GPIO_LED 60
#define BLINK_PERIOD_MS 1000   // 1 saniye

static struct timer_list blink_timer;
static bool led_state = false;

static void blink_timer_callback(struct timer_list *t)
{
    led_state = !led_state;
    gpio_set_value(GPIO_LED, led_state);

    pr_info("LED %s\n", led_state ? "ON" : "OFF");

    /* Timer'Ä± tekrar 1 saniye sonrasÄ±na kur */
    mod_timer(&blink_timer, jiffies + msecs_to_jiffies(BLINK_PERIOD_MS));
}

static int __init gpio_init(void)
{
    int ret;

    pr_info("GPIO blink module init\n");

    ret = gpio_request(GPIO_LED, "bbb_led");
    if (ret)
        return ret;

    gpio_direction_output(GPIO_LED, 0);

    /* Timer tanÄ±mla */
    timer_setup(&blink_timer, blink_timer_callback, 0);

    /* Ä°lk tetik: 1 saniye sonra */
    mod_timer(&blink_timer, jiffies + msecs_to_jiffies(BLINK_PERIOD_MS));

    return 0;
}

static void __exit gpio_exit(void)
{
    del_timer_sync(&blink_timer);
    gpio_set_value(GPIO_LED, 0);
    gpio_free(GPIO_LED);

    pr_info("GPIO blink module exit\n");
}

module_init(gpio_init);
module_exit(gpio_exit);

MODULE_LICENSE("GPL");
