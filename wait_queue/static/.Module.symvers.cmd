cmd_/home/pi/DeDrive/wait_queue/static/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/wait_queue/static/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/wait_queue/static/Module.symvers -e -i Module.symvers   -T -