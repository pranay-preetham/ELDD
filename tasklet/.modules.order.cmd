cmd_/home/pi/DeDrive/tasklet/modules.order := {   echo /home/pi/DeDrive/tasklet/example.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/tasklet/modules.order
