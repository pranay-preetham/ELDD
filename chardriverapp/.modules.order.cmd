cmd_/home/pi/DeDrive/chardriverapp/modules.order := {   echo /home/pi/DeDrive/chardriverapp/testchardriver.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/chardriverapp/modules.order
