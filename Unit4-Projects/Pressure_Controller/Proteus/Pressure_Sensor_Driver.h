#ifndef PRESSURE_SENSOR_DRIVER_H
#define PRESSURE_SENSOR_DRIVER_H

extern void (*set_Pressure_State)();

void Pressure_Sensor_init();
void Reading_Pressure_Val_State();
void Waiting_State();

#endif
