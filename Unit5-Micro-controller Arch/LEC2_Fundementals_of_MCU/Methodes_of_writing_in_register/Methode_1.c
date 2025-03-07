 #include <stdio.h>
#include <stdint.h>

uint32_t G_GPIO_ODR_variable = 0;
#define GPIO_ODR_ADDRESS & G_GPIO_ODR_variable
#define GPIO_ODR  (*((volatile uint32_t *) GPIO_ODR_ADDRESS))



int main()
{
    GPIO_ODR |= 1UL<<16 ;
    printf(" G_GPIO_ODR_variable = 0x%X .\n",G_GPIO_ODR_variable);
    
     return 0;
}