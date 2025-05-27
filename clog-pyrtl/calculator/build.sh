# all thanks for this script
# and helper files / harness
# to  [zach](https://github.com/zsisco)
# and [violet](https://github.com/untypedhue)

#!/bin/bash
NAME=calculator
set -e
../my-venv/bin/python3 $NAME.py
../my-venv/bin/yowasp-yosys -DPVT $NAME.v -p synth_ice40 -o $NAME.json
../my-venv/bin/yowasp-nextpnr-ice40 --up5k --package uwg30 --pcf fomu-pvt.pcf --json $NAME.json --asc $NAME.asc
../my-venv/bin/yowasp-icepack $NAME.asc $NAME.bit
openFPGALoader --Version || \
  (printf '\nerror: openFPGALoader not found, please install it\n\n' && exit 1)
openFPGALoader -b fomu $NAME.bit --verify || \
  (printf '\nerror: failed to upload, replug the USB, wait for it to register, and try again\nif on linux: https://workshop.fomu.im/en/latest/requirements/drivers.html\n\n' && exit 1)
