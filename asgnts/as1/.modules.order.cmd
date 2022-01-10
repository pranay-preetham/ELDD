cmd_/home/pi/DeDrive/asgnts/as1/modules.order := {   echo /home/pi/DeDrive/asgnts/as1/char_drive.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/asgnts/as1/modules.order
