/*
 * main.c
 *
 *  Created on: Mar 9, 2025
 *      Author: oussa
 */


#include "CA.h"

void setup()
{
	//init all the drivers, irq .....

	CA_state = CA_Waiting_State;
}

int main()
{

	setup();

	while(1)
	{
		CA_state();
	}
	return 0;
}
