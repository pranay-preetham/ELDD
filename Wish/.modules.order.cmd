cmd_/home/pi/DeDrive/Wish/modules.order := {   echo /home/pi/DeDrive/Wish/hello.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/Wish/modules.order
