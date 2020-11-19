######################################
# target
######################################
TARGET = PlantBuddy


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
Src/main.c \
Src/BlueNRG1_it.c \
Src/sht2x.c \
Src/led.c \
Src/soilhum.c \
hal/src/clock.c \
hal/src/fifo.c \
hal/src/gp_timer.c \
hal/src/hal_radio.c \
hal/src/miscutil.c \
hal/src/osal.c \
hal/src/radio_ota.c \
hal/src/sleep.c \
hal/src/vtimer.c \
CMSIS/Device/ST/BlueNRG1/Source/system_bluenrg1.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_adc.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_dma.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_flash.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_gpio.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_i2c.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_mft.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_pka.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_radio.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_rng.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_rtc.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_spi.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_sysCtrl.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_timer.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_uart.c \
BlueNRG1_Periph_Driver/src/BlueNRG1_wdg.c \
BlueNRG1_Periph_Driver/src/misc.c \
FreeRTOS/Source/portable/GCC/ARM_CM0/port.c \
FreeRTOS/Source/portable/MemMang/heap_1.c \
FreeRTOS/Source/croutine.c \
FreeRTOS/Source/event_groups.c \
FreeRTOS/Source/list.c \
FreeRTOS/Source/queue.c \
FreeRTOS/Source/stream_buffer.c \
FreeRTOS/Source/tasks.c \
FreeRTOS/Source/timers.c 

# ASM sources
ASM_SOURCES = \
hal/src/context_switch.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m0

# fpu
FPU = 

# float-abi
FLOAT-ABI = 

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS = -DBLUENRG1_DEVICE


# AS includes
AS_INCLUDES =  

# C includes
C_INCLUDES =  \
-IInc \
-IBlueNRG1_Periph_Driver/inc \
-ICMSIS/Device/ST/BlueNRG1/Include \
-ICMSIS/Include \
-Ihal/inc \
-IFreeRTOS/Source/include \
-IFreeRTOS/Source/portable/GCC/ARM_CM0 


# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
else
# Release mode
CFLAGS += -Werror
endif

# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = BlueNRG1.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***