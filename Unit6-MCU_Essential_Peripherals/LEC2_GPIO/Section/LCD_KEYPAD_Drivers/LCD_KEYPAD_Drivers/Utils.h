/*
 * Utils.h
 *
 * Created: 2/6/2025 10:01:58 PM
 *  Author: oussa
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg,bit) (reg |= (1<<bit))
#define ClearBit(reg,bit) (reg &= ~(1<<bit))
#define Togglebit(reg,bit) (reg ^= (1<<bit))
#define ReadBit(reg,bit) ((reg>>bit) & 1)





#endif /* UTILS_H_ */