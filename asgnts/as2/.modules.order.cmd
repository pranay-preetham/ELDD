cmd_/home/pi/DeDrive/asgnts/as2/modules.order := {   echo /home/pi/DeDrive/asgnts/as2/char_driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/asgnts/as2/modules.order
