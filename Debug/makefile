################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include VL53/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include DecodeGPS/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := VL53L0X_Test1
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
VL53L0X_Test1.elf \

MAP_FILES += \
VL53L0X_Test1.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
VL53L0X_Test1.list \

OBJCOPY_HEX += \
VL53L0X_Test1.hex \

OBJCOPY_BIN += \
VL53L0X_Test1.bin \

OBJCOPY_VERILOG += \
VL53L0X_Test1.verilog \

OBJCOPY_SREC += \
VL53L0X_Test1.srec \

OBJCOPY_SYMBOLSREC += \
VL53L0X_Test1.symbolsrec \


# All Target
all: main-build

# Main-build Target
main-build: VL53L0X_Test1.elf secondary-outputs

# Tool invocations
VL53L0X_Test1.elf VL53L0X_Test1.map: $(OBJS) $(USER_OBJS) F:\Workspace\21_EmbeddedSystem\VL53L0X_Test1\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "VL53L0X_Test1.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\Workspace\21_EmbeddedSystem\VL53L0X_Test1\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="VL53L0X_Test1.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

VL53L0X_Test1.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "VL53L0X_Test1.list"
	@echo 'Finished building: $@'
	@echo ' '

VL53L0X_Test1.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "VL53L0X_Test1.hex"
	@echo 'Finished building: $@'
	@echo ' '

VL53L0X_Test1.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "VL53L0X_Test1.bin"
	@echo 'Finished building: $@'
	@echo ' '

VL53L0X_Test1.verilog: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O verilog $(EXECUTABLES) "VL53L0X_Test1.verilog"
	@echo 'Finished building: $@'
	@echo ' '

VL53L0X_Test1.srec: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O srec $(EXECUTABLES) "VL53L0X_Test1.srec"
	@echo 'Finished building: $@'
	@echo ' '

VL53L0X_Test1.symbolsrec: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O symbolsrec $(EXECUTABLES) "VL53L0X_Test1.symbolsrec"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) VL53L0X_Test1.bin VL53L0X_Test1.elf VL53L0X_Test1.hex VL53L0X_Test1.list VL53L0X_Test1.map VL53L0X_Test1.srec VL53L0X_Test1.symbolsrec VL53L0X_Test1.verilog default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN) $(OBJCOPY_VERILOG) $(OBJCOPY_SREC) $(OBJCOPY_SYMBOLSREC)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
