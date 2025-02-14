//Oussama sahraoui
//Lab3-TM4C123_ARM_CortexM4

#include "platform_type.h"

#define SYSCTL_RCCGG2_R *((vuint32_t*)((vuint32_t)(0x400FE000 + 0x108)))
#define GPIO_PORTF_DIR_R *((vuint32_t*)((vuint32_t)(0x40025000 + 0x400)))
#define GPIO_PORTF_DEN_R *((vuint32_t*)((vuint32_t)(0x40025000 + 0x51C)))
#define GPIO_PORTF_DATA_R *((vuint32_t*)((vuint32_t)(0x40025000 + 0x3FC)))

int main(){

	volatile uint32_t delay_count;
	SYSCTL_RCCGG2_R = 0x20 ;
	//use delay to make sure GPIOF is up
	for(delay_count =0; delay_count < 200; delay_count++);

	GPIO_PORTF_DIR_R |= 1<<3;// DIR is out for pin 3 port F
	GPIO_PORTF_DEN_R |= 1<<3;

	while(1){

		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_count =0 ; delay_count < 2000 ;delay_count++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_count =0 ; delay_count < 2000 ;delay_count++);

	}
	
	return 0;
}