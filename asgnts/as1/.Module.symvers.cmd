cmd_/home/pi/DeDrive/asgnts/as1/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/asgnts/as1/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/asgnts/as1/Module.symvers -e -i Module.symvers   -T -
