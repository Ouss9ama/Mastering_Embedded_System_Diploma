/*
 * main.c
 *
 *  Created on: Mar 9, 2025
 *      Author: oussa
 */


#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	//init all the drivers, irq .....
	US_init();
	DC_init();
	CA_state = CA_Waiting_State;
	US_state = US_busy_State();
	DC_state = DC_idle_State();

}

int main()
{

	setup();

	while(1)
	{
		US_state();
		CA_state();
		DC_state();

		for(int d = 0 ; d <= 1000; d++);

	}
	return 0;
}
