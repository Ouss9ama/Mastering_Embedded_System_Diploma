#include "pressure_sensor_driver.h"
#include "signals.h"
#include "driver.h" // for getPressureVal() and Delay()

int P_Val = 0;
void (*set_Pressure_State)() = Pressure_Sensor_init;

void Pressure_Sensor_init() {
     
    set_Pressure_State = Reading_Pressure_Val_State;
}

void Reading_Pressure_Val_State() {
    P_Val = getPressureVal();
    set_Pressure_val(P_Val); // Signal to Algorithm
    set_Pressure_State = Waiting_State;
}

void Waiting_State() {
    Delay(1000);
    set_Pressure_State = Reading_Pressure_Val_State;
}
