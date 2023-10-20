################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DecodeGPS/decodeGPS.c 

C_DEPS += \
./DecodeGPS/decodeGPS.d 

OBJS += \
./DecodeGPS/decodeGPS.o 


# Each subdirectory must supply rules for building sources it contributes
DecodeGPS/%.o DecodeGPS/%.su DecodeGPS/%.cyclo: ../DecodeGPS/%.c DecodeGPS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"F:/Workspace/21_EmbeddedSystem/VL53L0X_Test1/Library/VL53" -I"F:/Workspace/21_EmbeddedSystem/VL53L0X_Test1/DecodeGPS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DecodeGPS

clean-DecodeGPS:
	-$(RM) ./DecodeGPS/decodeGPS.cyclo ./DecodeGPS/decodeGPS.d ./DecodeGPS/decodeGPS.o ./DecodeGPS/decodeGPS.su

.PHONY: clean-DecodeGPS

