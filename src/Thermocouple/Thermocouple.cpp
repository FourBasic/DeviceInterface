#include "Thermocouple.h"
#include <Arduino.h>

Thermocouple::Thermocouple() { }

void Thermocouple::setup(uint8_t _type, uint8_t _decimal, int _faultLimit_L, int _faultLimit_H) {    
    type = _type;
    decimal = _decimal;
}

int Thermocouple::update(int _uVolt) {
    uVolt = _uVolt;
    
    int element = -1;
    for (int i=0; i<25; i++) {
        int diff;    
        diff = uVolt - uv_per_10C_K[i];
        if (diff < 0) { 
            element = i;
            break;
        }
    }

    if (element < 0 || element > 24) {
        tempC = 9999.9;
    } else {
        float m;
        switch (type) {
            case TC_TYPE_K:      
                m = (10.0 + (element * 10.0)) / (uv_per_10C_K[element]);
                tempC = uVolt * m;
                break;

            default:
                tempC = 9999.9;
                break;
        }
    }
    checkLimits();
    return int(tempC * (1 + decimal));
}

bool Thermocouple::checkLimits() { 
    if (tempC > faultLimit_H) { 
        faultCode = TC_FAULT_HIGH_LIMIT;
        return false;
    } else if (tempC < faultLimit_L) {
        faultCode = TC_FAULT_LOW_LIMIT;
        return false;
    } else if (faultCode == TC_FAULT_HIGH_LIMIT || faultCode == TC_FAULT_LOW_LIMIT) {
        faultCode = 0;
    } else { 
        return true;
    }  
}

int Thermocouple::getFaultCode() { 
    return faultCode;
}