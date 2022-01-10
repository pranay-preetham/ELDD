cmd_/home/pi/DeDrive/char_exp/modules.order := {   echo /home/pi/DeDrive/char_exp/test.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/char_exp/modules.order
