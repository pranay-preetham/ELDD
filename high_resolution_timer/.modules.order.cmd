cmd_/home/pi/DeDrive/high_resolution_timer/modules.order := {   echo /home/pi/DeDrive/high_resolution_timer/timer_driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/high_resolution_timer/modules.order
