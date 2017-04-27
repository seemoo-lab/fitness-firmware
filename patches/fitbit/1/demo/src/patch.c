#pragma NEXMON targetregion "patch"

#include <firmware_version.h>
#include <patcher.h>
#include <wrapper.h>
#include "stm32.h"

int
hook_app_parse_command(int start, unsigned int length, int bluetooth_process2, int response_type) {
    char command = *((char *)start + 1);

    //this is our command, it gets ignored from the firmware
    //we can still continue to the original function
    if(command == 2) {

        // enable clock
        RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
        // TODO what about low power mode register?

        // clear bits for GPIO mode
        GPIOA->MODER &= ~(GPIO_MODER_MODER14 | GPIO_MODER_MODER13);
        // set bits for port 13 (SWDIO) and port 14 (SWCLK)
        GPIOA->MODER |= (GPIO_MODER_MODER14_1 | GPIO_MODER_MODER13_1);

        // clear pull up / pull down bits
        GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR13 | GPIO_PUPDR_PUPDR14);
        print_string("GPIOA->MODER: %x#", (GPIOA->MODER));
        return 1;
    } else {
        return app_parse_command(start, length, bluetooth_process2, response_type);
    }
}

__attribute__((at(0x800CE9E, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BLPatch(hook_app_parse_command, hook_app_parse_command);

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
