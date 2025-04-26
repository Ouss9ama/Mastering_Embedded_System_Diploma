/*
 * i2c_driver.h
 *
 *  Created on: Feb 28, 2025
 *      Author: oussa
 */

#ifndef MCAL_INCLUDE_I2C_DRIVER_H_
#define MCAL_INCLUDE_I2C_DRIVER_H_

/********************************************************************************************************************************************/
/*INCLUDES*/
/********************************************************************************************************************************************/
#include "STM32F103x6.h"
#include "gpio_driver.h"
#include "rcc_driver.h"


/********************************************************************************************************************************************/
/*CONFIG STRUCTURES*/
/********************************************************************************************************************************************/
struct S_I2C_DEVICE_ADDRESS
{
	uint16_t Enable_DUAL_Address;
	uint16_t Primary_Slave_Address;
	uint16_t Secondary_Slave_Address;
	uint32_t Addressing_Slave_Mode;  //@ref Addressing_Slave_Mode
};

typedef struct
{
	uint32_t                 I2C_CLlock_speed; // @ref I2C_SCLK
	uint32_t				 Strect_Mode; // @ref I2C_stretch_Mode
	uint32_t				 I2C_Mode; //_@ref I2C_Mode
	struct S_I2C_DEVICE_ADDRESS;
}I2C_init_typeDef;






/********************************************************************************************************************************************/
/*MACROS CONFIG REFERENCE*/
/********************************************************************************************************************************************/

/**************@ref I2C_SCLK******************/

//* I2C Clock Speed Configuration (Standard and Fast Mode).
//*
//* - **Standard Mode (SM):** Supports 50 kHz and 100 kHz.
//* - **Fast Mode (FM):** Supports up to 400 kHz (Not supported here).
//*
//* @note The clock frequency is set in **I2C_CR2->FREQ[5:0]** before enabling I2C.
//*       The speed value is configured in **I2C_CCR**.
//*/

#define I2C_SCLK_SM_50K    						(0x50000U)  /**< I2C_CCR: Standard Mode, 50 kHz */
#define I2C_SCLK_SM_100K  					    (0x100000U) /**< I2C_CCR: Standard Mode, 100 kHz */
#define I2C_SCLK_FM_200K   						(0x200000U) /**< I2C_CCR: Fast Mode, 200 kHz (Not supported) */
#define I2C_SCLK_FM_400K   						(0x400000U) /**< I2C_CCR: Fast Mode, 400 kHz (Not supported) */


/**************@ref I2C_stretch_Mode******************/
/**
 * Configures I2C Clock Stretching Mode.
 *
 * - **Register:** I2C_CR1
 * - **Bit 7 (NOSTRETCH):** Controls clock stretching.
 *   - `0`: Clock stretching **enabled** (default).
 *   - `1`: Clock stretching **disabled**.
 */

#define I2C_Stretch_Mode_Enable  				 0x00000000U  /**< I2C_CR1: Enable clock stretching (Bit 7 = 0) */
#define I2C_Stretch_Mode_Disable 				 I2C_CR1_NOSTRETCH  /**< I2C_CR1: Disable clock stretching (Bit 7 = 1) */

/************** @ref I2C_Mode ******************/
/**
 * @brief Configures the I2C mode.
 *
 * - **Register:** I2C_CR1
 * - **Bit 1 (SMBUS):** Selects between I2C and SMBus mode.
 *   - `0`: **I2C Mode** (Standard I2C communication).
 *   - `1`: **SMBus Mode** (System Management Bus communication).
 */

#define I2C_Mode_I2C    						 0                /**< I2C_CR1: Standard I2C Mode (Bit 1 = 0) */
#define I2C_Mode_SMBUS   						 I2C_CR1_SMBUS    /**< I2C_CR1: SMBus Mode (Bit 1 = 1) */

/**************@ref Addressing_Slave_Mod******************/
//Bit 15 ADDMODE Addressing mode (slave mode)
//0: 7-bit slave address (10-bit address not acknowledged)
//1: 10-bit slave address (7-bit address not acknowledged

#define I2C_Addressing_Slave_Mod2_7Bit			0x00000000U
#define I2C_Addressing_Slave_Mod2_10Bit			(uint16_t)(1<<15)

#endif /* MCAL_INCLUDE_I2C_DRIVER_H_ */

