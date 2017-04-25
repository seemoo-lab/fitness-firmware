#pragma NEXMON targetregion "patch"

#include <firmware_version.h>
#include <patcher.h>
#include <wrapper.h>

int
hook_check_auth() {
    return 1;
}

__attribute__((at(0x800C6C4, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BLPatch(hook_check_auth1, hook_check_auth);
__attribute__((at(0x800C704, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BLPatch(hook_check_auth2, hook_check_auth);
__attribute__((at(0x800CA50, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BLPatch(hook_check_auth3, hook_check_auth);
__attribute__((at(0x8013102, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BLPatch(hook_check_auth4, hook_check_auth);
