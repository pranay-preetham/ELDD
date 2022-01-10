cmd_/home/pi/DeDrive/char_driver/modules.order := {   echo /home/pi/DeDrive/char_driver/chardriver.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/char_driver/modules.order
