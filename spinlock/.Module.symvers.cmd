cmd_/home/pi/DeDrive/spinlock/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/spinlock/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/spinlock/Module.symvers -e -i Module.symvers   -T -