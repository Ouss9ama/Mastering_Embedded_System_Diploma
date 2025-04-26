/*
 * DC.h
 *
 *  Created on: Mar 9, 2025
 *      Author: oussa
 */

#ifndef DC_H_
#define DC_H_
#include "stdio.h"
#include "stdlib.h"
#include "Connection.h"

//define states

enum DC_States{
	DC_idle,
	DC_busy
};

extern enum DC_States DC_State_ID;

//APIs
void DC_idle_State();
void DC_busy_State();
extern void(*DC_state)();
void DC_init();
#endif /* DC_H_ */
