#pragma NEXMON targetregion "patch"

#include <firmware_version.h>
#include <patcher.h>
#include <wrapper.h>

void *
main() {
    blinkenlights(1, 0, 0, 5);
    return 0;
}

__attribute__((at(0x8027A60, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BPatch(main, main);

// Hook the call to wlc_ucode_write in wlc_ucode_download
//__attribute__((at(0x44ED0, "", CHIP_VER_BCM43438, FW_VER_7_45_41_26_r640327)))
//BLPatch(wlc_ucode_write_compressed, wlc_ucode_write_compressed);

// Update the ucode length to become the length of the extracted ucode before compression
//__attribute__((at(0x4E9BC, "", CHIP_VER_BCM43438, FW_VER_7_45_41_26_r640327)))
//GenericPatch4(ucode_length, 0xCC28);

//__attribute__((at(0x2654, "", CHIP_VER_BCM43438, FW_VER_7_45_41_26_r640327)))
//GenericPatch4(hndrte_reclaim_0_end, 0x592a4);
