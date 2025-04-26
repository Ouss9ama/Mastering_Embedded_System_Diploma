==IN mcu header .h file:
>>1: writing the base adress of USART registers (USART1-USART2-USART3).
>>2: writing the peripheral registers structures.
>>3: writing instants of USART (macros of pointer to base address of USARTx with typedef layout).
>>4: writing IRQ interrupt handler of USART (USARTx_IRQ).
>>5: writing macro to enable/disable interrupt handlers in NVIC.
>>6: WRITING MACRO to enable/disable the clock for the USART registers.

-making a driver for rcc to configure the baudrate 

(*The RCC->CFGR register contains configuration bits for the clock system.
 *Bits 10:8 in RCC->CFGR control the APB1 prescaler . These bits determine how much the HCLK is divided to produce PCLK1.
 *(RCC->CFGR >> 8) shifts the register right by 8 bits to align the prescaler bits with the least significant bits.
 *& 0b111 masks out all but the last 3 bits, isolating the prescaler value.)