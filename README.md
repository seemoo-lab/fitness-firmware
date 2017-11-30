# Steps:

* `source setup.env.sh`
* Maybe: `cd buildutils/` and `make`
* Edit: `patches/common/wrapper.c` to add more firmware functions (see *blinkenlights*)
* Edit: `patches/<device>/<fw-version>/demo/src/patch.c` to add new code to your firmware
* Edit: `firmwares/<device>/<fw-version>/definitions.mk` to define where new patches have to go
