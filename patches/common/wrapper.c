/***************************************************************************
 *                                                                         *
 *          ###########   ###########   ##########    ##########           *
 *         ############  ############  ############  ############          *
 *         ##            ##            ##   ##   ##  ##        ##          *
 *         ##            ##            ##   ##   ##  ##        ##          *
 *         ###########   ####  ######  ##   ##   ##  ##    ######          *
 *          ###########  ####  #       ##   ##   ##  ##    #    #          *
 *                   ##  ##    ######  ##   ##   ##  ##    #    #          *
 *                   ##  ##    #       ##   ##   ##  ##    #    #          *
 *         ############  ##### ######  ##   ##   ##  ##### ######          *
 *         ###########    ###########  ##   ##   ##   ##########           *
 *                                                                         *
 *            S E C U R E   M O B I L E   N E T W O R K I N G              *
 *                                                                         *
 * This file is part of NexMon.                                            *
 *                                                                         *
 * Copyright (c) 2016 NexMon Team                                          *
 *                                                                         *
 * NexMon is free software: you can redistribute it and/or modify          *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * NexMon is distributed in the hope that it will be useful,               *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with NexMon. If not, see <http://www.gnu.org/licenses/>.          *
 *                                                                         *
 **************************************************************************/

#ifndef WRAPPER_C
#define WRAPPER_C

#include <firmware_version.h>
#include <structs.h>

#ifndef WRAPPER_H
    // if this file is not included in the wrapper.h file, create dummy functions
    #define VOID_DUMMY { ; }
    #define RETURN_DUMMY { ; return 0; }

    #define AT(CHIPVER, FWVER, ADDR) __attribute__((at(ADDR, "dummy", CHIPVER, FWVER)))
#else
    // if this file is included in the wrapper.h file, create prototypes
    #define VOID_DUMMY ;
    #define RETURN_DUMMY ;
    #define AT(CHIPVER, FWVER, ADDR)
#endif

AT(CHIP_VER_FITBIT, FW_VER_FITBIT, 0x801a5e8)
int
blinkenlights(int a1, int a2, int a3, int a4)
RETURN_DUMMY

AT(CHIP_VER_FITBIT, FW_VER_FITBIT, 0x800C62C)
int
app_parse_command(int start, unsigned int length, int bluetooth_process2, int response_type)
RETURN_DUMMY

AT(CHIP_VER_FITBIT, FW_VER_FITBIT, 0x800EF10)
int
bt_send_live_mode(int a1, int a2, int a3, int a4, int a5, int a6)
RETURN_DUMMY

AT(CHIP_VER_FITBIT, FW_VER_FITBIT, 0x80222B0)
int 
print_string(const char *format, ...) 
RETURN_DUMMY

AT(CHIP_VER_FITBIT, FW_VER_FITBIT, 0x802241C)
void
open_command_prompt_loop()
VOID_DUMMY

AT(CHIP_VER_FITBIT, FW_VER_FITBIT, 0x800A37E)
int
app_check_crypto_required(char situation)
RETURN_DUMMY

#undef VOID_DUMMY
#undef RETURN_DUMMY
#undef AT

#endif /*WRAPPER_C*/
