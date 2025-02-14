################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/KEYPAD_driver/keypad.c 

OBJS += \
./STM32F103C6_Drivers/KEYPAD_driver/keypad.o 

C_DEPS += \
./STM32F103C6_Drivers/KEYPAD_driver/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/KEYPAD_driver/%.o STM32F103C6_Drivers/KEYPAD_driver/%.su STM32F103C6_Drivers/KEYPAD_driver/%.cyclo: ../STM32F103C6_Drivers/KEYPAD_driver/%.c STM32F103C6_Drivers/KEYPAD_driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"C:/Users/oussa/STM32CubeIDE/workspace_1.17.0/Drivers/STM32F103C6_Drivers/INCLUDES" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers-2f-KEYPAD_driver

clean-STM32F103C6_Drivers-2f-KEYPAD_driver:
	-$(RM) ./STM32F103C6_Drivers/KEYPAD_driver/keypad.cyclo ./STM32F103C6_Drivers/KEYPAD_driver/keypad.d ./STM32F103C6_Drivers/KEYPAD_driver/keypad.o ./STM32F103C6_Drivers/KEYPAD_driver/keypad.su

.PHONY: clean-STM32F103C6_Drivers-2f-KEYPAD_driver

