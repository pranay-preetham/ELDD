cmd_/home/pi/DeDrive/synchronisation/modules.order := {   echo /home/pi/DeDrive/synchronisation/de_drivers.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/synchronisation/modules.order
