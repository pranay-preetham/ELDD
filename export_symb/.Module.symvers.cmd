cmd_/home/pi/DeDrive/export_symb/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/export_symb/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/export_symb/Module.symvers -e -i Module.symvers   -T -
