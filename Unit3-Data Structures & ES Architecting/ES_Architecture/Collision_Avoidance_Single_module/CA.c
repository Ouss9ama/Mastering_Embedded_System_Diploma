/*
 * CA.c
 *
 *  Created on: Mar 9, 2025
 *      Author: oussa
 */

#include "CA.h"

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

int Ultrasonic_get_dis_random(int l, int r, int count);
enum CA_States CA_State_ID;
//State pointer to function
void(*CA_state)();


void CA_Waiting_State(){

	//state
	CA_State_ID = CA_waiting;

	//action
	//DC_Motor_set_speed(CA_speed)
	CA_speed = 0;

	//Event check
	//Ultrasonic_get_dis(CA_distance)
	CA_distance = Ultrasonic_get_dis_random(45,55,1);
	CA_state = (CA_distance <= CA_threshold) ? CA_Waiting_State : CA_Driving_State;			;

	printf("CA_Waiting_State: Distance = %d  Speed = %d \n", CA_distance, CA_speed);
}

void CA_Driving_State(){

	//state
	CA_State_ID = CA_driving;

	//action
	//DC_Motor(CA_speed)
	CA_speed = 30;

	//Event check
	//Ultrasonic_get_dis(CA_distance)
	CA_distance = Ultrasonic_get_dis_random(45,55,1);
	CA_state = (CA_distance <= CA_threshold)? CA_Waiting_State : CA_Driving_State;

	printf("CA_Driving_State: Distance = %d  Speed = %d \n", CA_distance, CA_speed);

}

int Ultrasonic_get_dis_random(int l, int r, int count)
{
	int i;
	for( i=0;  i < count;i++){
		int rand_nb = (rand() % (r -l + 1)) + l;
		return rand_nb;
	}
}
