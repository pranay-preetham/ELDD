cmd_/home/pi/DeDrive/param/modules.order := {   echo /home/pi/DeDrive/param/para.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/param/modules.order
