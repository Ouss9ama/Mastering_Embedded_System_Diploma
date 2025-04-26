/*
 * US.c
 *
 *  Created on: Mar 9, 2025
 *      Author: oussa
 */

#include "US.h"


int US_distance = 0;


int Ultrasonic_get_dis_random(int l, int r, int count);
enum US_States US_State_ID;
//State pointer to function
void(*US_state)();

void US_init(){
	printf("US driver init\n");
}

void US_busy_State(){

	//state
	US_State_ID = US_busy;

	//action
	US_distance = Ultrasonic_get_dis_random(45,55,1);

	printf("US_busy_State: Distance = %d \n", US_distance);
	Ultrasonic_get_dis(US_distance);
	US_state = US_busy_State;
}


int Ultrasonic_get_dis_random(int l, int r, int count)
{
	int i;
	for( i=0;  i < count;i++){
		int rand_nb = (rand() % (r -l + 1)) + l;
		return rand_nb;
	}
}
