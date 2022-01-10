cmd_/home/pi/DeDrive/wait_queue/static/modules.order := {   echo /home/pi/DeDrive/wait_queue/static/driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/wait_queue/static/modules.order
