/*
 * MemoryMap.h
 *
 * Created: 2/5/2025 1:36:27 AM
 *  Author: oussa
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

#define DDRA *((volatile unsigned char *)(0x3A))
#define PORTA *((volatile unsigned char *)(0x3B))
#define PINA *((volatile unsigned char *)(0x39))

#define DDRC *((volatile unsigned char *)(0x34))
#define PORTC *((volatile unsigned char *)(0x35))
#define PINC *((volatile unsigned char *)(0x33))



#endif /* MEMORYMAP_H_ */