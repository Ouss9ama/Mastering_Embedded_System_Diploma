#ifndef SIGNALS_H
#define SIGNALS_H

// Sent from Pressure Sensor to Algorithm
void set_Pressure_val(int P_Val);

// Sent from Algorithm to Monitor Alarm
void High_Pressure_Detected(void);

#endif