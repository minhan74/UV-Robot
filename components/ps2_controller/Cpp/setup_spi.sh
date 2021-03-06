#!/bin/bash

set -eu -o pipefail # fail on error , debug all lines

if [ 'root' != $( whoami ) ] ; then
  echo "Please run as root! ( sudo ${0} )"
  exit 1;
fi

# load the SPI drivers into the kernel # https://www.raspberrypi.org/documentation/hardware/raspberrypi/spi/README.md
									   # http://wiringpi.com/reference/spi-library/
# uncomment "dtparam=spi=on" (already taken into account multiple leading # and whitespace) ref: https://stackoverflow.com/questions/24889346/how-to-uncomment-a-line-that-contains-a-specific-string-using-sed/24889374
sed -i '/dtparam=spi=on/s/^#*\s*//g' /boot/config.txt


echo
echo
echo "Please reboot to make SPI enable."

## (c) 2020 Minh-An Dao. All right reserved