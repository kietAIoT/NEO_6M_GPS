################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Library/VL53/VL53L0X.c 

C_DEPS += \
./VL53/VL53L0X.d 

OBJS += \
./VL53/VL53L0X.o 


# Each subdirectory must supply rules for building sources it contributes
VL53/VL53L0X.o: F:/Workspace/21_EmbeddedSystem/VL53L0X_Test1/Library/VL53/VL53L0X.c VL53/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"F:/Workspace/21_EmbeddedSystem/VL53L0X_Test1/Library/VL53" -I"F:/Workspace/21_EmbeddedSystem/VL53L0X_Test1/DecodeGPS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-VL53

clean-VL53:
	-$(RM) ./VL53/VL53L0X.cyclo ./VL53/VL53L0X.d ./VL53/VL53L0X.o ./VL53/VL53L0X.su

.PHONY: clean-VL53

