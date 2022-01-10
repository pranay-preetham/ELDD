cmd_/home/pi/DeDrive/spinlock/modules.order := {   echo /home/pi/DeDrive/spinlock/example.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/spinlock/modules.order
