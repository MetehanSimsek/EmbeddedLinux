cmd_/home/debian/EmLin_exp/gpio_lkm/modules.order := {   echo /home/debian/EmLin_exp/gpio_lkm/gpio_test.ko; :; } | awk '!x[$$0]++' - > /home/debian/EmLin_exp/gpio_lkm/modules.order
