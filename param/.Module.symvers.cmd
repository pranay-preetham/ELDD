cmd_/home/pi/DeDrive/param/Module.symvers := sed 's/ko$$/o/' /home/pi/DeDrive/param/modules.order | scripts/mod/modpost -m -a   -o /home/pi/DeDrive/param/Module.symvers -e -i Module.symvers   -T -
