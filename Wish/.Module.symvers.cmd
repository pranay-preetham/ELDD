cmd_/home/pi/DeDrive/Wish/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/Wish/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/Wish/Module.symvers -e -i Module.symvers   -T -
