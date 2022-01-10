cmd_/home/pi/DeDrive/module_para/modules.order := {   echo /home/pi/DeDrive/module_para/module_para.ko; :; } | awk '!x[$$0]++' - > /home/pi/DeDrive/module_para/modules.order
