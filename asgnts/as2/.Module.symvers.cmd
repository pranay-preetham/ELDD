cmd_/home/pi/DeDrive/asgnts/as2/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/asgnts/as2/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/asgnts/as2/Module.symvers -e -i Module.symvers   -T -