################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/STM32F103C6_gpio_driver.c 

OBJS += \
./STM32F103C6_Drivers/STM32F103C6_gpio_driver.o 

C_DEPS += \
./STM32F103C6_Drivers/STM32F103C6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/%.o STM32F103C6_Drivers/%.su STM32F103C6_Drivers/%.cyclo: ../STM32F103C6_Drivers/%.c STM32F103C6_Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/oussa/STM32CubeIDE/workspace_1.17.0/Drivers/STM32F103C6_Drivers/KEYPAD_driver" -I"C:/Users/oussa/STM32CubeIDE/workspace_1.17.0/Drivers/STM32F103C6_Drivers/LCD_DRIVER" -I"C:/Users/oussa/STM32CubeIDE/workspace_1.17.0/Drivers/STM32F103C6_Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers

clean-STM32F103C6_Drivers:
	-$(RM) ./STM32F103C6_Drivers/STM32F103C6_gpio_driver.cyclo ./STM32F103C6_Drivers/STM32F103C6_gpio_driver.d ./STM32F103C6_Drivers/STM32F103C6_gpio_driver.o ./STM32F103C6_Drivers/STM32F103C6_gpio_driver.su

.PHONY: clean-STM32F103C6_Drivers

