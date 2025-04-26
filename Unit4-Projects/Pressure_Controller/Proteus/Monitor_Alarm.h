#ifndef MONITOR_ALARM_H
#define MONITOR_ALARM_H

typedef enum {
    ALARM_OFF,
    ALARM_ON
} Alarm_State;

extern Alarm_State current_state;

extern void (*set_Alarm_state)();

void Alarm_Active();
void Alarm_idle();
void High_Pressure_Detected();

#endif
