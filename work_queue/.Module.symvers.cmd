cmd_/home/pi/DeDrive/work_queue/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/work_queue/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/work_queue/Module.symvers -e -i Module.symvers   -T -
