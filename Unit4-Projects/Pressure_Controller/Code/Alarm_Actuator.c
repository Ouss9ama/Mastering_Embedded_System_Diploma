#include "alarm_actuator.h"
#include "driver.h"

void Start_Alarm() {
    Set_Alarm_actuator(0);
}

void Stop_Alarm() {
    Set_Alarm_actuator(1);
}
