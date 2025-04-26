#include "monitor_alarm.h"
#include "alarm_actuator.h"
#include "driver.h"
#include "signals.h"

void (*set_Alarm_state)() = Alarm_idle;

Alarm_State current_state = ALARM_OFF;

int Alarm_triggered_Flag = 0;

 void Alarm_idle()
 {
    if(Alarm_triggered_Flag)
    {
        set_Alarm_state = Alarm_Active;
        Alarm_triggered_Flag = 0;
    }
 }

 void Alarm_Active()
 {
    Start_Alarm();
    Delay(100);
    Stop_Alarm();
    set_Alarm_state = Alarm_idle;
 }

 void High_Pressure_Detected()
 {
    Alarm_triggered_Flag = 1;
 }