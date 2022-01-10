cmd_/home/pi/DeDrive/start_clean/modules.order := {   echo /home/pi/DeDrive/start_clean/final.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/start_clean/modules.order
