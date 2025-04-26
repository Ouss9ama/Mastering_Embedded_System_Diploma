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


enum CA_States CA_State_ID;
//State pointer to function
void(*CA_state)();


void Ultrasonic_get_dis(int distance){
	CA_distance = distance;
	CA_state = (CA_distance <= CA_threshold) ? CA_Waiting_State : CA_Driving_State;
	printf("Ultrasonic Sensor-----Distance=%d---> CA",distance);
}

void CA_Waiting_State(){

	//state
	CA_State_ID = CA_waiting;
	printf("CA_Waiting_State: Distance = %d  Speed = %d \n", CA_distance, CA_speed);

	//action
	//DC_Motor_set_speed(CA_speed)
	CA_speed = 0;
	DC_Motor_set_speed(CA_speed);

}

void CA_Driving_State(){

	//state
	CA_State_ID = CA_driving;
	printf("CA_Driving_State: Distance = %d  Speed = %d \n", CA_distance, CA_speed);

	//action
	//DC_Motor(CA_speed)
	CA_speed = 30;
	DC_Motor_set_speed(CA_speed);




}


