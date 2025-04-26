1. UART Data Framing: Start Bit
In UART communication, data is transmitted in frames , which consist of:
-A start bit (always 0),
-The actual data bits (usually 5 to 9 bits),
-An optional parity bit ,
-One or more stop bits (always 1).
>>Start Bit Behavior:
-The start bit signals the beginning of a new data frame.
-Before transmission begins, the communication line is typically held at a high voltage level (1) , which represents the idle state .
-When the sender wants to transmit data, it pulls the line low (0) to indicate the start of a frame.
-This transition from high (1) to low (0) is what the receiver detects as the start bit .
-Once the receiver detects this falling edge (from high to low), it knows that a new frame is starting and begins sampling the incoming bits.

2. The Use of Parity
*The parity bit is an optional feature in UART communication used for error detection . It helps the receiver verify 
whether the received data has been corrupted during transmission.
>>How Parity Works:
The sender calculates the parity bit based on the number of 1s in the data bits. There are two types of parity:
  -Even Parity :
The parity bit is set such that the total number of 1s in the data bits (including the parity bit) is even .
**For example:
If the data bits are 1011 (three 1s), the parity bit will be 1 to make the total number of 1s even (10111).
  -Odd Parity :
The parity bit is set such that the total number of 1s in the data bits (including the parity bit) is odd .
**For example:
If the data bits are 1011 (three 1s), the parity bit will be 0 because the total number of 1s is already odd (10110).
==========================================================================================================================================
>> When to Use UART vs. USART?
* UART :
- Use when you only need simple, asynchronous serial communication.
- Suitable for applications like communicating with sensors, debugging via a serial terminal, or interfacing with devices like GPS modules.
* USART :
- Use when you need both asynchronous and synchronous communication capabilities.
- Ideal for systems that must interface with a variety of devices, such as SPI peripherals, RS-232 devices, or custom synchronous protocols.
>>Practical Example
* UART :
A microcontroller uses a UART to send debug messages to a computer via a USB-to-UART converter. The communication is asynchronous,
 with no clock signal.
* USART :
A microcontroller uses its USART in asynchronous mode to communicate with a GPS module (like UART) and switches to
 synchronous mode to communicate with an SPI-based display driver.
==========================================================================================================================================
>>for ATMEGA32:
- UCSRA focuses on status flags and real-time information. (e.g., data received, transmission complete).
- UCSRB focuses on enabling/disabling features.(e.g., transmitter, receiver, interrupts).
- UCSRC focuses on configuring the frame format. (e.g., data bits, stop bits, parity).
>> Steps to Initialize a UART

1-Set the Baud Rate :
-Configure the baud rate generator to match the desired communication speed.
-Calculate the value for the UBRR (USART Baud Rate Register) based on the system clock frequency (F_CPU) and the desired baud rate.
-Write the calculated value to the UBRRH (high byte) and UBRRL (low byte) registers.
2-Enable the Transmitter and Receiver :
-Set the TXEN bit in the UCSRB register to enable the transmitter.
-Set the RXEN bit in the UCSRB register to enable the receiver.
3-Configure the Frame Format :
-Use the UCSRC register to configure the data frame format:
Data Bits : Set the number of data bits (e.g., 5, 6, 7, 8, or 9 bits) using the UCSZ bits.
Stop Bits : Set the number of stop bits (1 or 2) using the USBS bit.
Parity : Configure parity (none, even, or odd) using the UPM bits.
4-Select the USART Mode :
-If using asynchronous mode (most common), ensure the UMSEL bit in the UCSRC register is cleared (default).
-If using synchronous mode, set the UMSEL bit and configure the clock polarity (UCPOL).
5-Enable Interrupts (Optional) :
-If using interrupts for UART communication:
Enable the relevant interrupt flags in the UCSRB register:
RXCIE: Enables the Receive Complete interrupt.
TXCIE: Enables the Transmit Complete interrupt.
UDRIE: Enables the Data Register Empty interrupt.
-Enable global interrupts by setting the I bit in the Status Register (SREG).
6-Check for Initialization Flags (Optional) :
Verify that the UART is ready for communication by checking status flags in the UCSRA register:
-UDRE: Indicates that the transmit buffer is empty and ready to accept new data.
-RXC: Indicates that data has been received and is ready to be read.
7-Test Communication :
-Send a test character using the UDR (USART Data Register) to verify that the transmitter is working.
-Read a test character from the UDR register to verify that the receiver is working.
======================================================================================================================
lab1:(section)
1-Transmission:
-When UART_Send('O') is called, the character 'O' is written to the UDR register.
-The UART hardware converts this byte into a serial signal and transmits it over the TX pin.
2-Reception:
-When data is received on the RX pin, the UART hardware stores it in the UDR register.
-The UART_Recieve() function waits for the RXC flag to be set, then reads the data from UDR.
3-Simulation in Proteus:
-In Proteus, you likely connected the TX pin of one ATmega32 to the RX pin of another (or to a virtual terminal).
-When you send characters ('O', 'S', 'S'), they appear on the receiving end (e.g., in a virtual terminal or another microcontroller)