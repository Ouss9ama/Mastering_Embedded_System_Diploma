#include <stdint.h>
#include <stdio.h>
#include "driver.h"
#include "pressure_sensor_driver.h"
#include "monitor_alarm.h"

int main (){

	GPIO_INITIALIZATION();
	
	while (1)
	{
		 set_Pressure_State();
		 set_Alarm_state();
	}

}
