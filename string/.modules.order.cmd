cmd_/home/pi/DeDrive/string/modules.order := {   echo /home/pi/DeDrive/string/string.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/string/modules.order
