/*
 * rcc_driver.h
 *
 *  Created on: Feb 21, 2025
 *      Author: oussa
 */

#ifndef MCAL_INCLUDE_RCC_DRIVER_H_
#define MCAL_INCLUDE_RCC_DRIVER_H_

#include "STM32F103x6.h"
#include "gpio_driver.h"

#define HSE_CLK										(uint32_t)16000000
#define HSI_RC_CLK 									(uint32_t)8000000


uint32_t MCAL_RCC_get_SYSCLK_FREQUENCY(void);
uint32_t MCAL_RCC_get_HCLK_FREQUENCY(void);
uint32_t MCAL_RCC_get_PCLK1_FREQUENCY(void);
uint32_t MCAL_RCC_get_PCLK2_FREQUENCY(void);

#endif /* MCAL_INCLUDE_RCC_DRIVER_H_ */
