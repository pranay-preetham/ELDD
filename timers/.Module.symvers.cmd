cmd_/home/pi/DeDrive/timers/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/timers/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/timers/Module.symvers -e -i Module.symvers   -T -
