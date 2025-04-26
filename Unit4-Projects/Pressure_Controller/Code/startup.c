#include "stdint.h"
extern int main(void);
void Reset_Handler();

void Default_Handler(){
	Reset_Handler();
}
 
void NMI() __attribute__ ((weak, alias ("Default_Handler")));;
void Hard_Fault()  __attribute__ ((weak, alias ("Default_Handler")));
void MM_fault() __attribute__ ((weak, alias ("Default_Handler")));
void Bus_Fault() __attribute__ ((weak, alias ("Default_Handler")));


extern unsigned int _stack_top;

uint32_t vectors[] __attribute__((section(".vectors"))) = { //using attributes to define a section called .vectors

(uint32_t) &_stack_top,
(uint32_t) &Reset_Handler,
(uint32_t) &NMI,
(uint32_t) &Hard_Fault,
(uint32_t) &MM_fault,
(uint32_t) &Bus_Fault,

};
extern unsigned int _E_text;//they are extern symbole, already defined in the linkerscript
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
void Reset_Handler() {
	//copy .data section from flash to sram
	unsigned int data_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA; //symbole is not a variable, it has no value, its just a name for the adress
	unsigned char* P_src = (unsigned char*)&_E_text; //ptr to source
	unsigned char* P_dst = (unsigned char*)&_S_DATA; //ptr to destination
	for (int i=0 ; i<data_size;i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	//init .bss section in sram by 0
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss; 
	for (int i=0;i<bss_size;i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}
	//jumps to main
	main();
}