#include "Sensor555.h"
#include <Arduino.h>

Sensor555::Sensor555() { }

void Sensor555::setup(uint16_t _timeout, int _faultLimit_L, int _faultLimit_H) {    

}

float Sensor555::update() {
    
    
    checkLimits();
    return val;
}

bool Sensor555::checkLimits() {
    if (tempC > faultLimit_H) { 
        faultCode = TC_FAULT_HIGH_LIMIT;
        return false;
    } else if (tempC < faultLimit_L) {
        faultCode = TC_FAULT_LOW_LIMIT;
        return false;
    } else if (faultCode == TC_FAULT_HIGH_LIMIT || faultCode == TC_FAULT_LOW_LIMIT) {
        faultCode = 0;
    }
    return true;
}

int Sensor555::getFaultCode() { 
    return faultCode;
}