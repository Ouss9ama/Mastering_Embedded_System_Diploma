/*
 * CA.h
 *
 *  Created on: Mar 9, 2025
 *      Author: oussa
 */

#ifndef CA_H_
#define CA_H_
#include "stdio.h"
#include "stdlib.h"

//define states

enum CA_States{
	CA_waiting,
	CA_driving
};

extern enum CA_States CA_State_ID;

//APIs
void CA_Waiting_State();
void CA_Driving_State();
extern void(*CA_state)();
#endif /* CA_H_ */
