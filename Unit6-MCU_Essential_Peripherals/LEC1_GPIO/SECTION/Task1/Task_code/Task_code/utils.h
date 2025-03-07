/*
 * utils.h
 *
 * Created: 2/5/2025 11:13:22 AM
 *  Author: oussa
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg,bit) (reg |= (1<<bit))
#define ClearBit(reg,bit) (reg &= ~(1<<bit))
#define Togglebit(reg,bit) (reg ^= (1<<bit))
#define ReadBit(reg,bit) ((reg>>bit) & 1)




#endif /* UTILS_H_ */