cmd_/home/pi/DeDrive/work_queue/modules.order := {   echo /home/pi/DeDrive/work_queue/work_queue.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/work_queue/modules.order
