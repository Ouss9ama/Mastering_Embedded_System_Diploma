/*
 * Lab2_Atmega32_Interrupt.c
 *
 * Created: 1/29/2025 10:48:59 PM
 * Author : oussa
 */ 
 #define F_CPU 1000000UL
 #include <avr/io.h> //Includes register definitions
 #include <util/delay.h>
 #include <avr/interrupt.h>//Includes the IRQ (interrupt handler)

 //#define SET_BIT(ADDRESS,BIT) ADDRESS |= (1<<BIT)
 //#define CLEAR_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
 //#define TOGGLE_BIT(ADDRESS,BIT) ADDRESS ^= (1<<BIT)

 void init_interrupts(void);


 int main(void)
 {
	 //configure PD5 as an output (LED0)
	 DDRD |= (1<<PD5);
	 //configure PD6 as an output (LED1)
	 DDRD |= (1<<PD6);
	 //configure PD7 as an output (LED2)
	 DDRD |= (1<<PD7);
	 // Configure PD2 as input (INT0)
	 DDRD &= ~(1 << PD2);
	 // Configure PD3 as input (INT1)
	 DDRD &= ~(1 << PD3);
	 // Configure PB2 as input (INT2)
	 DDRB &= ~(1 << PB2);
	 
	 //initialize the external interrupts
	 init_interrupts();
	 
	 //ENABLE GLOBALE INERRUPT
	 sei(); //SREG |= (1 << 7);
	 
	 while (1)
	 {
		 PORTD &= ~(1<<PD5);// turn off LED0 by default
		 PORTD &= ~(1<<PD6);//turn off LED1 by default
		 PORTD &= ~(1<<PD7);//turn off LED2 by default
	 }
 }

 //initialize the external interrupts
 void init_interrupts(void){
	 // Configure INT0 (PD2): Trigger on any logical change
	 MCUCR |= (1<<ISC00);// Set ISC00 bit any logical change
	 GICR |= (1<<INT0);//Enable INT0 interrupt
	 
	 // Configure INT1 (PD3): Trigger on rising edge
	 MCUCR |= (1<<ISC10); //(rising edge)
	 MCUCR |= (1<<ISC11);
	 GICR |= (1 << INT1); // Enable INT1 interrupt
	 
	 // Configure INT2 (PB2): Trigger on falling edge
	 MCUCSR &= ~(1 << ISC2); // Clear ISC2 bit (falling edge)
	 GICR |= (1 << INT2);    // Enable INT2 interrupt
 }

 //ISR for INT0 (PD2): Any logical change
 ISR(INT0_vect){
	 //when called turn the LED0 (PD5)
	 PORTD |= (1<<PD5); //turn on
	 _delay_ms(1000); //wait for 1 second
	 PORTD &= ~(1<<PD5);//turn off
 }

 //ISR for INT1 (PD3): Trigger on rising edge
 ISR(INT1_vect){
	 //when called turn the LED1 (PD6)
	 PORTD |= (1<<PD6); //turn on
	 _delay_ms(1000); //wait for 1 second
	 PORTD &= ~(1<<PD6);//turn off
 }

 //ISR for INT2 (PB2): Falling edge
 ISR(INT2_vect){
	 //when called turn the LED2 (PD7)
	 PORTD |= (1<<PD7); //turn on
	 _delay_ms(1000); //wait for 1 second
	 PORTD &= ~(1<<PD7);//turn off
 }

