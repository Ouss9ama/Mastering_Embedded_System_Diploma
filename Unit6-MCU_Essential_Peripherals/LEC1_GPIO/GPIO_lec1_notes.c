**************Push-Pull Mode*************
Write 1: PMOS connects output to Vcc (logic high).
Write 0: NMOS connects output to GND (logic low).
**************Open-Drain Mode*****************
Write 1: NMOS turns off, output is high-impedance (reliant on external pull-up resistor to pull it high).
Write 0: NMOS turns on, output is connected to GND (logic low).
-------------------------------------------------------
LAB1:
When the pushbutton connected to Pin A1 is pressed:

Pin 1 on Port A reads low (0).

The condition ((GPIOPA_IDR & (1<<1)) >> 1) == 0 evaluates to true.

The state of Pin 1 on Port B is toggled:

If it was high (1), it becomes low (0), and the LED turns on.

If it was low (0), it becomes high (1), and the LED turns off.

When the pushbutton is not pressed:

Pin 1 on Port A reads high (1).

The condition ((GPIOPA_IDR & (1<<1)) >> 1) == 0 evaluates to false.

The state of Pin 1 on Port B remains unchanged.

-First Toggle:

LED changes from off to on.

Second Toggle:

LED changes from on to off.

Third Toggle:

LED changes from off to on.
---------------------------------------------------
section.notes
Example Code for ATmega GPIO:
Here’s an example of configuring and using GPIO pins on an ATmega microcontroller:

1. Push-Pull Output:
 
DDRB |= (1 << PB0); // Set PB0 as output
PORTB |= (1 << PB0); // Set PB0 high
PORTB &= ~(1 << PB0); // Set PB0 low
2. Floating Input:
 
DDRB &= ~(1 << PB0); // Set PB0 as input
PORTB &= ~(1 << PB0); // Disable pull-up resistor (floating input)
3. Input with Pull-Up Resistor:
 
DDRB &= ~(1 << PB0); // Set PB0 as input
PORTB |= (1 << PB0); // Enable pull-up resistor on PB0
4. Emulating Open-Drain:
 
DDRB |= (1 << PB0); // Set PB0 as output (drives low)
PORTB &= ~(1 << PB0); // Drive PB0 low
DDRB &= ~(1 << PB0); // Set PB0 as input (floats high)
