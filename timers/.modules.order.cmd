cmd_/home/pi/DeDrive/timers/modules.order := {   echo /home/pi/DeDrive/timers/timers.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/timers/modules.order
