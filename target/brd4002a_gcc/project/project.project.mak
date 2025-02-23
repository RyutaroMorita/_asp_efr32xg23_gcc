####################################################################
# Automatically-generated file. Do not edit!                       #
# Makefile Version 16                                              #
####################################################################

BASE_SDK_PATH = C:/Users/RyutarouMorita/SimplicityStudio/SDKs/simplicity_sdk
BASE_PKG_PATH = C:/Users/RyutarouMorita/.silabs/slt/installs
UNAME:=$(shell $(POSIX_TOOL_PATH)uname -s | $(POSIX_TOOL_PATH)sed -e 's/^\(CYGWIN\).*/\1/' | $(POSIX_TOOL_PATH)sed -e 's/^\(MINGW\).*/\1/')
ifeq ($(UNAME),MINGW)
# Translate "C:/super" into "/C/super" for MinGW make.
SDK_PATH := /$(shell $(POSIX_TOOL_PATH)echo $(BASE_SDK_PATH) | sed s/://)
PKG_PATH := /$(shell $(POSIX_TOOL_PATH)echo $(BASE_PKG_PATH) | sed s/://)
endif
SDK_PATH ?= $(BASE_SDK_PATH)
PKG_PATH ?= $(BASE_PKG_PATH)
COPIED_SDK_PATH ?= simplicity_sdk_2024.6.2

# This uses the explicit build rules below
PROJECT_SOURCE_FILES =

C_SOURCE_FILES   += $(filter %.c, $(PROJECT_SOURCE_FILES))
CXX_SOURCE_FILES += $(filter %.cpp, $(PROJECT_SOURCE_FILES))
CXX_SOURCE_FILES += $(filter %.cc, $(PROJECT_SOURCE_FILES))
ASM_SOURCE_FILES += $(filter %.s, $(PROJECT_SOURCE_FILES))
ASM_SOURCE_FILES += $(filter %.S, $(PROJECT_SOURCE_FILES))
LIB_FILES        += $(filter %.a, $(PROJECT_SOURCE_FILES))

C_DEFS += \
 '-DDEBUG_EFM=1' \
 '-DEFR32ZG23B020F512IM48=1' \
 '-DSL_BOARD_NAME="BRD4210A"' \
 '-DSL_BOARD_REV="A01"' \
 '-DHARDWARE_BOARD_DEFAULT_RF_BAND_868=1' \
 '-DHARDWARE_BOARD_SUPPORTS_2_RF_BANDS=1' \
 '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_868=1' \
 '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_915=1' \
 '-DHFXO_FREQ=39000000' \
 '-DSL_COMPONENT_CATALOG_PRESENT=1' \
 '-DSL_CODE_COMPONENT_PERIPHERAL_SYSRTC=hal_sysrtc' \
 '-DCMSIS_NVIC_VIRTUAL=1' \
 '-DCMSIS_NVIC_VIRTUAL_HEADER_FILE="cmsis_nvic_virtual.h"' \
 '-DSL_CODE_COMPONENT_CORE=core' \
 '-DSL_CODE_COMPONENT_SLEEPTIMER=sleeptimer'

ASM_DEFS += \
 '-DDEBUG_EFM=1' \
 '-DEFR32ZG23B020F512IM48=1' \
 '-DSL_BOARD_NAME="BRD4210A"' \
 '-DSL_BOARD_REV="A01"' \
 '-DHARDWARE_BOARD_DEFAULT_RF_BAND_868=1' \
 '-DHARDWARE_BOARD_SUPPORTS_2_RF_BANDS=1' \
 '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_868=1' \
 '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_915=1' \
 '-DHFXO_FREQ=39000000' \
 '-DSL_COMPONENT_CATALOG_PRESENT=1' \
 '-DSL_CODE_COMPONENT_PERIPHERAL_SYSRTC=hal_sysrtc' \
 '-DCMSIS_NVIC_VIRTUAL=1' \
 '-DCMSIS_NVIC_VIRTUAL_HEADER_FILE="cmsis_nvic_virtual.h"' \
 '-DSL_CODE_COMPONENT_CORE=core' \
 '-DSL_CODE_COMPONENT_SLEEPTIMER=sleeptimer'

INCLUDES += \
 -Iconfig \
 -Iautogen \
 -I. \
 -I$(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFR32ZG23/Include \
 -I$(COPIED_SDK_PATH)/platform/common/inc \
 -I$(COPIED_SDK_PATH)/hardware/board/inc \
 -I$(COPIED_SDK_PATH)/platform/driver/button/inc \
 -I$(COPIED_SDK_PATH)/platform/service/clock_manager/inc \
 -I$(COPIED_SDK_PATH)/platform/service/clock_manager/src \
 -I$(COPIED_SDK_PATH)/platform/CMSIS/Core/Include \
 -I$(COPIED_SDK_PATH)/hardware/driver/configuration_over_swo/inc \
 -I$(COPIED_SDK_PATH)/platform/driver/debug/inc \
 -I$(COPIED_SDK_PATH)/platform/service/device_manager/inc \
 -I$(COPIED_SDK_PATH)/platform/service/device_init/inc \
 -I$(COPIED_SDK_PATH)/platform/emdrv/dmadrv/inc \
 -I$(COPIED_SDK_PATH)/platform/emdrv/dmadrv/inc/s2_signals \
 -I$(COPIED_SDK_PATH)/platform/emdrv/common/inc \
 -I$(COPIED_SDK_PATH)/platform/emlib/inc \
 -I$(COPIED_SDK_PATH)/platform/emdrv/gpiointerrupt/inc \
 -I$(COPIED_SDK_PATH)/platform/peripheral/inc \
 -I$(COPIED_SDK_PATH)/platform/service/interrupt_manager/inc \
 -I$(COPIED_SDK_PATH)/platform/service/interrupt_manager/inc/arm \
 -I$(COPIED_SDK_PATH)/platform/driver/leddrv/inc \
 -I$(COPIED_SDK_PATH)/platform/service/memory_manager/inc \
 -I$(COPIED_SDK_PATH)/hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart \
 -I$(COPIED_SDK_PATH)/platform/common/toolchain/inc \
 -I$(COPIED_SDK_PATH)/platform/service/system/inc \
 -I$(COPIED_SDK_PATH)/platform/service/sleeptimer/inc \
 -I$(COPIED_SDK_PATH)/platform/emdrv/uartdrv/inc \
 -I$(COPIED_SDK_PATH)/platform/service/udelay/inc

GROUP_START =-Wl,--start-group
GROUP_END =-Wl,--end-group

PROJECT_LIBS = \
 -lgcc \
 -lc \
 -lm \
 -lnosys

LIBS += $(GROUP_START) $(PROJECT_LIBS) $(GROUP_END)

LIB_FILES += $(filter %.a, $(PROJECT_LIBS))

C_FLAGS += \
 -mcpu=cortex-m33 \
 -mthumb \
 -mfpu=fpv5-sp-d16 \
 -mfloat-abi=hard \
 -std=c18 \
 -Wall \
 -Wextra \
 -Os \
 -fdata-sections \
 -ffunction-sections \
 -fomit-frame-pointer \
 -imacros sl_gcc_preinclude.h \
 -mcmse \
 --specs=nano.specs \
 -g

CXX_FLAGS += \
 -mcpu=cortex-m33 \
 -mthumb \
 -mfpu=fpv5-sp-d16 \
 -mfloat-abi=hard \
 -std=c++17 \
 -fno-rtti \
 -fno-exceptions \
 -Wall \
 -Wextra \
 -Os \
 -fdata-sections \
 -ffunction-sections \
 -fomit-frame-pointer \
 -imacros sl_gcc_preinclude.h \
 -mcmse \
 --specs=nano.specs \
 -g

ASM_FLAGS += \
 -mcpu=cortex-m33 \
 -mthumb \
 -mfpu=fpv5-sp-d16 \
 -mfloat-abi=hard \
 -imacros sl_gcc_preinclude.h \
 -x assembler-with-cpp

LD_FLAGS += \
 -mcpu=cortex-m33 \
 -mthumb \
 -mfpu=fpv5-sp-d16 \
 -mfloat-abi=hard \
 -T"autogen/linkerfile.ld" \
 --specs=nano.specs \
 -Xlinker -Map=$(OUTPUT_DIR)/$(PROJECTNAME).map \
 -Wl,--gc-sections \
 -Wl,--no-warn-rwx-segments


####################################################################
# Pre/Post Build Rules                                             #
####################################################################
pre-build:
	# No pre-build defined

post-build: $(OUTPUT_DIR)/$(PROJECTNAME).out
	# No post-build defined

####################################################################
# SDK Build Rules                                                  #
####################################################################
$(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_control_gpio.o: $(COPIED_SDK_PATH)/hardware/board/src/sl_board_control_gpio.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/hardware/board/src/sl_board_control_gpio.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/hardware/board/src/sl_board_control_gpio.c
CDEPS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_control_gpio.d
OBJS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_control_gpio.o

$(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_init.o: $(COPIED_SDK_PATH)/hardware/board/src/sl_board_init.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/hardware/board/src/sl_board_init.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/hardware/board/src/sl_board_init.c
CDEPS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_init.d
OBJS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_init.o

$(OUTPUT_DIR)/sdk/hardware/driver/configuration_over_swo/src/sl_cos.o: $(COPIED_SDK_PATH)/hardware/driver/configuration_over_swo/src/sl_cos.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/hardware/driver/configuration_over_swo/src/sl_cos.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/hardware/driver/configuration_over_swo/src/sl_cos.c
CDEPS += $(OUTPUT_DIR)/sdk/hardware/driver/configuration_over_swo/src/sl_cos.d
OBJS += $(OUTPUT_DIR)/sdk/hardware/driver/configuration_over_swo/src/sl_cos.o

$(OUTPUT_DIR)/sdk/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o: $(COPIED_SDK_PATH)/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.c
CDEPS += $(OUTPUT_DIR)/sdk/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.d
OBJS += $(OUTPUT_DIR)/sdk/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o

$(OUTPUT_DIR)/sdk/platform/common/src/sl_assert.o: $(COPIED_SDK_PATH)/platform/common/src/sl_assert.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/common/src/sl_assert.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/common/src/sl_assert.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_assert.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_assert.o

$(OUTPUT_DIR)/sdk/platform/common/src/sl_core_cortexm.o: $(COPIED_SDK_PATH)/platform/common/src/sl_core_cortexm.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/common/src/sl_core_cortexm.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/common/src/sl_core_cortexm.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_core_cortexm.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_core_cortexm.o

$(OUTPUT_DIR)/sdk/platform/common/src/sl_syscalls.o: $(COPIED_SDK_PATH)/platform/common/src/sl_syscalls.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/common/src/sl_syscalls.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/common/src/sl_syscalls.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_syscalls.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_syscalls.o

$(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32ZG23/Source/startup_efr32zg23.o: $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFR32ZG23/Source/startup_efr32zg23.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFR32ZG23/Source/startup_efr32zg23.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFR32ZG23/Source/startup_efr32zg23.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32ZG23/Source/startup_efr32zg23.d
OBJS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32ZG23/Source/startup_efr32zg23.o

$(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32ZG23/Source/system_efr32zg23.o: $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFR32ZG23/Source/system_efr32zg23.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFR32ZG23/Source/system_efr32zg23.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFR32ZG23/Source/system_efr32zg23.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32ZG23/Source/system_efr32zg23.d
OBJS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32ZG23/Source/system_efr32zg23.o

$(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_button.o: $(COPIED_SDK_PATH)/platform/driver/button/src/sl_button.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/driver/button/src/sl_button.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/driver/button/src/sl_button.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_button.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_button.o

$(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_simple_button.o: $(COPIED_SDK_PATH)/platform/driver/button/src/sl_simple_button.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/driver/button/src/sl_simple_button.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/driver/button/src/sl_simple_button.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_simple_button.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_simple_button.o

$(OUTPUT_DIR)/sdk/platform/driver/debug/src/sl_debug_swo.o: $(COPIED_SDK_PATH)/platform/driver/debug/src/sl_debug_swo.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/driver/debug/src/sl_debug_swo.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/driver/debug/src/sl_debug_swo.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/debug/src/sl_debug_swo.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/debug/src/sl_debug_swo.o

$(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_led.o: $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_led.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_led.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_led.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_led.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_led.o

$(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_simple_led.o: $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_simple_led.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_simple_led.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_simple_led.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_simple_led.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_simple_led.o

$(OUTPUT_DIR)/sdk/platform/emdrv/dmadrv/src/dmadrv.o: $(COPIED_SDK_PATH)/platform/emdrv/dmadrv/src/dmadrv.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emdrv/dmadrv/src/dmadrv.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emdrv/dmadrv/src/dmadrv.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/dmadrv/src/dmadrv.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/dmadrv/src/dmadrv.o

$(OUTPUT_DIR)/sdk/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o: $(COPIED_SDK_PATH)/platform/emdrv/gpiointerrupt/src/gpiointerrupt.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emdrv/gpiointerrupt/src/gpiointerrupt.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emdrv/gpiointerrupt/src/gpiointerrupt.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/gpiointerrupt/src/gpiointerrupt.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o

$(OUTPUT_DIR)/sdk/platform/emdrv/uartdrv/src/uartdrv.o: $(COPIED_SDK_PATH)/platform/emdrv/uartdrv/src/uartdrv.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emdrv/uartdrv/src/uartdrv.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emdrv/uartdrv/src/uartdrv.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/uartdrv/src/uartdrv.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/uartdrv/src/uartdrv.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_burtc.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_burtc.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_burtc.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_burtc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_burtc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_burtc.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_cmu.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_cmu.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_cmu.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_cmu.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_cmu.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_cmu.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_core.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_core.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_core.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_core.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_core.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_core.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_emu.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_emu.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_emu.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_emu.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_emu.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_emu.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_eusart.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_eusart.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_eusart.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_eusart.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_eusart.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_eusart.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_gpio.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_gpio.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_gpio.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_gpio.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_gpio.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_gpio.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_ldma.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_ldma.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_ldma.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_ldma.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_ldma.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_ldma.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_msc.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_msc.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_msc.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_msc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_msc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_msc.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_prs.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_prs.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_prs.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_prs.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_prs.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_prs.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_system.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_system.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_system.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_system.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_system.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_system.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_timer.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_timer.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_timer.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_timer.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_timer.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_timer.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_usart.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_usart.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_usart.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_usart.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_usart.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_usart.o

$(OUTPUT_DIR)/sdk/platform/peripheral/src/sl_hal_sysrtc.o: $(COPIED_SDK_PATH)/platform/peripheral/src/sl_hal_sysrtc.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/peripheral/src/sl_hal_sysrtc.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/peripheral/src/sl_hal_sysrtc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/peripheral/src/sl_hal_sysrtc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/peripheral/src/sl_hal_sysrtc.o

$(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager.o: $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager.o

$(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager_hal_s2.o: $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager_hal_s2.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager_hal_s2.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager_hal_s2.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager_hal_s2.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager_hal_s2.o

$(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager_init.o: $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager_init.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager_init.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager_init.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager_init.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager_init.o

$(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager_init_hal_s2.o: $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager_init_hal_s2.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager_init_hal_s2.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/clock_manager/src/sl_clock_manager_init_hal_s2.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager_init_hal_s2.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/clock_manager/src/sl_clock_manager_init_hal_s2.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_dcdc_s2.o: $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_dcdc_s2.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_dcdc_s2.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_dcdc_s2.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_dcdc_s2.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_dcdc_s2.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_emu_s2.o: $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_emu_s2.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_emu_s2.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_emu_s2.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_emu_s2.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_emu_s2.o

$(OUTPUT_DIR)/sdk/platform/service/device_manager/clocks/sl_device_clock_efr32xg23.o: $(COPIED_SDK_PATH)/platform/service/device_manager/clocks/sl_device_clock_efr32xg23.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/device_manager/clocks/sl_device_clock_efr32xg23.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/device_manager/clocks/sl_device_clock_efr32xg23.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_manager/clocks/sl_device_clock_efr32xg23.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_manager/clocks/sl_device_clock_efr32xg23.o

$(OUTPUT_DIR)/sdk/platform/service/device_manager/devices/sl_device_peripheral_hal_efr32xg23.o: $(COPIED_SDK_PATH)/platform/service/device_manager/devices/sl_device_peripheral_hal_efr32xg23.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/device_manager/devices/sl_device_peripheral_hal_efr32xg23.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/device_manager/devices/sl_device_peripheral_hal_efr32xg23.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_manager/devices/sl_device_peripheral_hal_efr32xg23.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_manager/devices/sl_device_peripheral_hal_efr32xg23.o

$(OUTPUT_DIR)/sdk/platform/service/device_manager/src/sl_device_clock.o: $(COPIED_SDK_PATH)/platform/service/device_manager/src/sl_device_clock.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/device_manager/src/sl_device_clock.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/device_manager/src/sl_device_clock.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_manager/src/sl_device_clock.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_manager/src/sl_device_clock.o

$(OUTPUT_DIR)/sdk/platform/service/device_manager/src/sl_device_peripheral.o: $(COPIED_SDK_PATH)/platform/service/device_manager/src/sl_device_peripheral.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/device_manager/src/sl_device_peripheral.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/device_manager/src/sl_device_peripheral.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_manager/src/sl_device_peripheral.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_manager/src/sl_device_peripheral.o

$(OUTPUT_DIR)/sdk/platform/service/interrupt_manager/src/sl_interrupt_manager_cortexm.o: $(COPIED_SDK_PATH)/platform/service/interrupt_manager/src/sl_interrupt_manager_cortexm.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/interrupt_manager/src/sl_interrupt_manager_cortexm.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/interrupt_manager/src/sl_interrupt_manager_cortexm.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/interrupt_manager/src/sl_interrupt_manager_cortexm.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/interrupt_manager/src/sl_interrupt_manager_cortexm.o

$(OUTPUT_DIR)/sdk/platform/service/memory_manager/src/sl_memory_manager_region.o: $(COPIED_SDK_PATH)/platform/service/memory_manager/src/sl_memory_manager_region.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/memory_manager/src/sl_memory_manager_region.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/memory_manager/src/sl_memory_manager_region.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/memory_manager/src/sl_memory_manager_region.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/memory_manager/src/sl_memory_manager_region.o

$(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer.o: $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer.o

$(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.o: $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.o

$(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.o: $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.o

$(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.o: $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.o

$(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_init.o: $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_init.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_init.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_init.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_init.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_init.o

$(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_process_action.o: $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_process_action.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_process_action.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_process_action.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_process_action.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_process_action.o

$(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay.o: $(COPIED_SDK_PATH)/platform/service/udelay/src/sl_udelay.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/udelay/src/sl_udelay.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/udelay/src/sl_udelay.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay.o

$(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay_armv6m_gcc.o: $(COPIED_SDK_PATH)/platform/service/udelay/src/sl_udelay_armv6m_gcc.S
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/udelay/src/sl_udelay_armv6m_gcc.S'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(ASMFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/udelay/src/sl_udelay_armv6m_gcc.S
ASMDEPS_S += $(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay_armv6m_gcc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay_armv6m_gcc.o

$(OUTPUT_DIR)/project/app.o: app.c
	@$(POSIX_TOOL_PATH)echo 'Building app.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ app.c
CDEPS += $(OUTPUT_DIR)/project/app.d
OBJS += $(OUTPUT_DIR)/project/app.o

$(OUTPUT_DIR)/project/autogen/sl_board_default_init.o: autogen/sl_board_default_init.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_board_default_init.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_board_default_init.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_board_default_init.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_board_default_init.o

$(OUTPUT_DIR)/project/autogen/sl_event_handler.o: autogen/sl_event_handler.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_event_handler.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_event_handler.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_event_handler.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_event_handler.o

$(OUTPUT_DIR)/project/autogen/sl_simple_button_instances.o: autogen/sl_simple_button_instances.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_simple_button_instances.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_simple_button_instances.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_simple_button_instances.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_simple_button_instances.o

$(OUTPUT_DIR)/project/autogen/sl_simple_led_instances.o: autogen/sl_simple_led_instances.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_simple_led_instances.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_simple_led_instances.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_simple_led_instances.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_simple_led_instances.o

$(OUTPUT_DIR)/project/autogen/sl_uartdrv_init.o: autogen/sl_uartdrv_init.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_uartdrv_init.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_uartdrv_init.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_uartdrv_init.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_uartdrv_init.o

$(OUTPUT_DIR)/project/main.o: main.c
	@$(POSIX_TOOL_PATH)echo 'Building main.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ main.c
CDEPS += $(OUTPUT_DIR)/project/main.d
OBJS += $(OUTPUT_DIR)/project/main.o

# Automatically-generated Simplicity Studio Metadata
# Please do not edit or delete these lines!
# SIMPLICITY_STUDIO_METADATA=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=END_SIMPLICITY_STUDIO_METADATA
# END OF METADATA