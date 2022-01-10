cmd_/home/pi/DeDrive/asgnts/as3/modules.order := {   echo /home/pi/DeDrive/asgnts/as3/char_driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/asgnts/as3/modules.order
