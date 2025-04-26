#include "algorithm.h"
#include "signals.h"

const int PRESSURE_THRESHOLD = 20;
 

void Algorithm_Pressure_Detection(int P_Val) {
    if (P_Val > PRESSURE_THRESHOLD) {
        High_Pressure_Detected(); // Signal to Monitor      
    }
     
}

void set_Pressure_val(int P_Val) {
    Algorithm_Pressure_Detection(P_Val);
}
