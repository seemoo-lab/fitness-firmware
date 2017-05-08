#pragma NEXMON targetregion "patch"

#include <firmware_version.h>
#include <patcher.h>
#include <wrapper.h>
#include "stm32.h"



void
reset_swd_pins() {
    // enable clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // clear bits for GPIO mode
    GPIOA->MODER &= ~(GPIO_MODER_MODER14 | GPIO_MODER_MODER13);

    // set bits for port 13 (SWDIO) and port 14 (SWCLK)
    GPIOA->MODER |= (GPIO_MODER_MODER14_1 | GPIO_MODER_MODER13_1);

    // clear pull up / pull down bits
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR13 | GPIO_PUPDR_PUPDR14);
}

void
open_command_prompt_loop_hook() {
    reset_swd_pins();
    open_command_prompt_loop();
}

__attribute__((at(0x8026020, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
GenericPatch4(command_promt_addr, open_command_prompt_loop_hook+1);

int
hook_app_parse_command(int start, unsigned int length, int bluetooth_process2, int response_type) {
    //char command = *((char *)start + 1);

    //this is our custom command
    //if(command == 2) {
    //    reset_swd_pins();
    //    print_string("GPIOA->MODER: %x#", (GPIOA->MODER));
    //    return 1;
    //} else {
    //    return app_parse_command(start, length, bluetooth_process2, response_type);
    //}
    return app_parse_command(start, length, bluetooth_process2, response_type);
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

int
hook_app_check_crypto_required(char situation) {
    return 0;
}

__attribute__((at(0x800A42E, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BLPatch(hook_app_check_crypto_required1, hook_app_check_crypto_required);
__attribute__((at(0x800A500, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BLPatch(hook_app_check_crypto_required2, hook_app_check_crypto_required);
__attribute__((at(0x800A958, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BLPatch(hook_app_check_crypto_required3, hook_app_check_crypto_required);
__attribute__((at(0x800B8A0, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BLPatch(hook_app_check_crypto_required4, hook_app_check_crypto_required);
__attribute__((at(0x800C030, "", CHIP_VER_FITBIT, FW_VER_FITBIT)))
BLPatch(hook_app_check_crypto_required5, hook_app_check_crypto_required);
