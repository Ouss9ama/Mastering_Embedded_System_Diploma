/*
 * DC.c
 *
 *  Created on: Mar 9, 2025
 *      Author: oussa
 */

#include "DC.h"

int DC_speed = 0;
enum DC_States DC_State_ID;
//State pointer to function
void(*DC_state)();

void DC_init(){
	printf("DC_init \n");
}
void DC_Motor_set_speed(int speed){
	DC_speed = speed;
	DC_state = DC_busy_State;
	printf("CA-----Speed=%d---> DC",DC_speed);

}
void DC_idle_State(){

	//state
	DC_State_ID = DC_idle;

	printf("DC_idle_State: Speed = %d \n", DC_speed);
}

void DC_busy_State(){

	//state
	DC_State_ID = DC_busy;
	DC_state = DC_idle_State;
	printf("DC_busy_State: Speed = %d \n", DC_speed);
}

