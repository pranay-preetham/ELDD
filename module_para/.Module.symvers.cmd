cmd_/home/pi/DeDrive/module_para/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/module_para/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/module_para/Module.symvers -e -i Module.symvers   -T -