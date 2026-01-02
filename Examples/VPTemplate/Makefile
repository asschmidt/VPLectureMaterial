#******************************************************************************
# @file main.c
#
# @author Andreas Schmidt (a.v.schmidt81@googlemail.com)
# @date   08.02.2025
#
# @copyright Copyright (c) 2025
#
#******************************************************************************
#
# @brief Main file for the VP Template project
#
#
#******************************************************************************

#
# Define the commands which should be used to build the files
# Cross-compilation commands
CC      = arm-none-eabi-gcc
AR      = arm-none-eabi-ar
AS		= arm-none-eabi-as
LD		= arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size


#
# Project specific options
#

# Directory Layout
SRC_DIR	  = src
OBJ_DIR   = obj
LIB_DIR	  = lib
BLD_DIR   = build

# Locate the main libraries
HAL = $(LIB_DIR)/HAL
HAL_SRC = $(HAL)/Src

# Set the linker file which should be used
LD_FILE = linker/VP.ld

# Pre-Processor defines to configure the HAL library
DEF	= -DSTM32G4xx -DSTM32G474xx -DUSE_HAL_DRIVER -DF_CPU=170000000L -DDEBUG_BUILD

#
# Flags for the Assembler, Compiler and Linker
#

# Assembler Flags
ASFLAGS = -g -mcpu=cortex-m4 -mthumb

# Compiler Flags
CFLAGS = -c -O0 -g -mcpu=cortex-m4 -mthumb
CFLAGS += -Wall -ffunction-sections -fdata-sections -fstack-usage
CFLAGS += -Wno-unused-function -nostdlib

# Linker Flags
LDFLAGS = -nostdlib -mcpu=cortex-m4 -mthumb --specs=nano.specs --specs=nosys.specs -Wl,--gc-sections -L$(OBJ_DIR) -Wl,--start-group -lc -lgcc -lm -lnosys -lstm32 -Wl,--end-group

# Set the include search directoties
CFLAGS += -I$(SRC_DIR)
# Include files for CMSIS
CFLAGS += -I$(LIB_DIR)/Core/Include
# Include files for HAL
CFLAGS += -I$(LIB_DIR)/HAL/Inc
# Include files for general STM32G4xx
CFLAGS += -I$(LIB_DIR)/STM32G4xx/Include

# Include files for App
CFLAGS += -I$(SRC_DIR)/App
# Include files for HAL
CFLAGS += -I$(SRC_DIR)/HAL
# Include files for OS
CFLAGS += -I$(SRC_DIR)/OS
# Include files for Service
CFLAGS += -I$(SRC_DIR)/Service
# Include files for Utils
CFLAGS += -I$(SRC_DIR)/Util


#
# Rules to setup the source and object filenames
#

# Project specific Assembler source files
SRC_ASM += $(wildcard $(SRC_DIR)/*.s)
SRC_ASM += $(wildcard $(SRC_DIR)/*.S)
FILENAMES_ASM = $(notdir $(SRC_ASM))
OBJFILENAMES_ASM = $(FILENAMES_ASM:.s=.o)
OBJS_ASM = $(addprefix $(OBJ_DIR)/, $(OBJFILENAMES_ASM:.S=.o))
vpath %.s $(dir $(SRC_ASM))
vpath %.S $(dir $(SRC_ASM))

# Project specific C-Source files
SRC_C += $(wildcard $(SRC_DIR)/*.c)
SRC_C += $(wildcard $(SRC_DIR)/App/*.c)
SRC_C += $(wildcard $(SRC_DIR)/HAL/*.c)
SRC_C += $(wildcard $(SRC_DIR)/OS/*.c)
SRC_C += $(wildcard $(SRC_DIR)/Service/*.c)
SRC_C += $(wildcard $(SRC_DIR)/Util/*.c)
SRC_C += $(wildcard $(SRC_DIR)/Util/Log/*.c)
SRC_C += $(wildcard $(SRC_DIR)/Util/Filter/*.c)
SRC_C += $(wildcard $(SRC_DIR)/Util/StateTable/*.c)
FILENAMES_C	= $(notdir $(SRC_C))
OBJS_C = $(addprefix $(OBJ_DIR)/, $(FILENAMES_C:.c=.o))
vpath %.c $(dir $(SRC_C))

# Source files for the HAL library
STM32LIB_SRC_C = $(wildcard $(HAL_SRC)/*.c)
STM32LIB_FILENAMES_C = $(notdir $(STM32LIB_SRC_C))
OBJS_STM32LIB = $(addprefix $(OBJ_DIR)/, $(STM32LIB_FILENAMES_C:.c=.o))
vpath %.c $(dir $(STM32LIB_SRC_C))

DEPS := $(OBJS_C:.o=.d)

all: $(BLD_DIR) $(OBJ_DIR) build/firmware.bin

# Rules
$(BLD_DIR):
	@echo "Creating Build Directory"
	@mkdir -p $(BLD_DIR)

$(OBJ_DIR):
	@echo "Creating Object Directory"
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.s
	@echo "  AS      $(notdir $@)"
	@$(AS) $(ASFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: %.S
	@echo "  AS      $(notdir $@)"
	@$(AS) $(ASFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: %.c
	@echo "  CC      $(notdir $@)"
	@$(CC) -c $(CFLAGS) $(DEF) -MP -MMD $< -o $@

$(OBJ_DIR)/libstm32.a: $(OBJS_STM32LIB)
	@echo "  AR      $(notdir $@)"
	@ar rcs $@ $(OBJS_STM32LIB)

$(BLD_DIR)/firmware.elf: $(OBJ_DIR)/libstm32.a $(OBJS_ASM) $(OBJS_C) | $(LD_FILE)
	@echo "  LD      $(notdir $@)"
	@$(LD) $^ $(LDFLAGS) $(INC) -T$(LD_FILE) -Wl,-Map $(BLD_DIR)/firmware.map -o $@

$(BLD_DIR)/%.bin: $(BLD_DIR)/%.elf
	@echo "  OBJCOPY $(notdir $@)"
	@arm-none-eabi-objcopy $< -O binary $@

clean:
	rm -f $(BLD_DIR)/*.elf
	rm -f $(BLD_DIR)/*.bin
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJ_DIR)/*.a
	rm -f $(OBJ_DIR)/*.su
	rm -f $(OBJ_DIR)/*.d

.PHONY: all clean

-include $(DEPS)