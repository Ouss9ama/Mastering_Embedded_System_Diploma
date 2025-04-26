################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/HAL/LCD_DRIVER/lcd.c 

OBJS += \
./STM32F103C6_Drivers/HAL/LCD_DRIVER/lcd.o 

C_DEPS += \
./STM32F103C6_Drivers/HAL/LCD_DRIVER/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/HAL/LCD_DRIVER/%.o STM32F103C6_Drivers/HAL/LCD_DRIVER/%.su STM32F103C6_Drivers/HAL/LCD_DRIVER/%.cyclo: ../STM32F103C6_Drivers/HAL/LCD_DRIVER/%.c STM32F103C6_Drivers/HAL/LCD_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"C:/Users/oussa/OneDrive/Documents/ES/6-MCU_Essential_Peripherals/LEC4_EXTI_DRIVER/STM32_DRIVERS/Drivers/STM32F103C6_Drivers/HAL/INCLUDE" -I"C:/Users/oussa/OneDrive/Documents/ES/6-MCU_Essential_Peripherals/LEC4_EXTI_DRIVER/STM32_DRIVERS/Drivers/STM32F103C6_Drivers/MCAL/INCLUDE" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers-2f-HAL-2f-LCD_DRIVER

clean-STM32F103C6_Drivers-2f-HAL-2f-LCD_DRIVER:
	-$(RM) ./STM32F103C6_Drivers/HAL/LCD_DRIVER/lcd.cyclo ./STM32F103C6_Drivers/HAL/LCD_DRIVER/lcd.d ./STM32F103C6_Drivers/HAL/LCD_DRIVER/lcd.o ./STM32F103C6_Drivers/HAL/LCD_DRIVER/lcd.su

.PHONY: clean-STM32F103C6_Drivers-2f-HAL-2f-LCD_DRIVER

