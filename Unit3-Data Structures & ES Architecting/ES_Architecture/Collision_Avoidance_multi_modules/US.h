/*
 * US.h
 *
 *  Created on: Mar 9, 2025
 *      Author: oussa
 */

#ifndef US_H_
#define US_H_

#include "stdio.h"
#include "stdlib.h"
#include "Connection.h"
//define states

enum US_States{
	US_busy,
};

extern enum US_States US_State_ID;

//APIs
void US_busy_State();

extern void(*US_state)();
void US_init();

#endif /* US_H_ */
