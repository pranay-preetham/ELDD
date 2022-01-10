cmd_/home/pi/DeDrive/string/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/string/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/string/Module.symvers -e -i Module.symvers   -T -
