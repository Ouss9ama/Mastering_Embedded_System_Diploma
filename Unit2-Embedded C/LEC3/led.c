#include <stdint.h>

#define RCC_BASE 0x40021000
#define PortA_base 0x40010800

#define RCC_APBE2ENR *((volatile uint32_t *)((volatile uint32_t)RCC_BASE + 0X18))
#define GPIOA_ODR *((volatile uint32_t *)((volatile uint32_t*)PortA_base + 0x0C))
#define GPIO_CRH *((volatile uint32_t *)((volatile uint32_t*)PortA_base + 0x04))

int main(void)
{

RCC_APBE2ENR |= 1<<2 ;
GPIO_CRH &=0xff0fffff;
GPIO_CRH |=0x00200000;

while(1)
{

	GPIOA_ODR |= 1<<13;
	for(volatile int i=0;i<60000;i++);
	GPIOA_ODR &= ~(1<<13);
	for(volatile int i=0;i<60000;i++);
}

	return 0;
}