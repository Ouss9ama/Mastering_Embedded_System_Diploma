################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/MCAL/I2C_DRIVER/i2c_driver.c 

OBJS += \
./STM32F103C6_Drivers/MCAL/I2C_DRIVER/i2c_driver.o 

C_DEPS += \
./STM32F103C6_Drivers/MCAL/I2C_DRIVER/i2c_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/MCAL/I2C_DRIVER/%.o STM32F103C6_Drivers/MCAL/I2C_DRIVER/%.su STM32F103C6_Drivers/MCAL/I2C_DRIVER/%.cyclo: ../STM32F103C6_Drivers/MCAL/I2C_DRIVER/%.c STM32F103C6_Drivers/MCAL/I2C_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"C:/Users/oussa/STM32CubeIDE/workspace_1.17.0/Drivers/STM32F103C6_Drivers/HAL/INCLUDE" -I"C:/Users/oussa/STM32CubeIDE/workspace_1.17.0/Drivers/STM32F103C6_Drivers/MCAL/INCLUDE" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers-2f-MCAL-2f-I2C_DRIVER

clean-STM32F103C6_Drivers-2f-MCAL-2f-I2C_DRIVER:
	-$(RM) ./STM32F103C6_Drivers/MCAL/I2C_DRIVER/i2c_driver.cyclo ./STM32F103C6_Drivers/MCAL/I2C_DRIVER/i2c_driver.d ./STM32F103C6_Drivers/MCAL/I2C_DRIVER/i2c_driver.o ./STM32F103C6_Drivers/MCAL/I2C_DRIVER/i2c_driver.su

.PHONY: clean-STM32F103C6_Drivers-2f-MCAL-2f-I2C_DRIVER

