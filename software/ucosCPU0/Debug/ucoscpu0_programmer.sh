#!/bin/sh
#
# This file was automatically generated by the Nios II IDE Flash Programmer.
#
# It will be overwritten when the flash programmer options change.
#

cd E:/MyProject/My_project/Altera/Q11MultiCore/software/ucosCPU0/Debug

# Creating .flash file for the project
"$SOPC_KIT_NIOS2/bin/elf2flash" --base=0x00000000 --end=0x3fffff --reset=0x0 --input="ucosCPU0.elf" --output="cfi.flash" --boot="D:/altera/11.0/ip/altera/nios2_ip/altera_nios2/boot_loader_cfi.srec"

# Programming flash with the project
"$SOPC_KIT_NIOS2/bin/nios2-flash-programmer" --base=0x00000000 --sidp=0x00401050 --id=11 --timestamp=1448615026 --instance=1 "cfi.flash"

