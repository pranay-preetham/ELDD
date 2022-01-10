cmd_/home/pi/DeDrive/wait_queue/dynamic/modules.order := {   echo /home/pi/DeDrive/wait_queue/dynamic/driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/wait_queue/dynamic/modules.order
