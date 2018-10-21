#pragma NEXMON targetregion "patch"

#include <firmware_version.h>
#include <patcher.h>
#include <wrapper.h>
#include "stm32.h"

int
hook_get_steps() {
    int steps = *((int *) 0x20005DC8);
    steps = steps * 100;
    return steps;
}

__attribute__((at(0x801E22C, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BPatch(hook_get_steps, hook_get_steps);
