#include "Thermocouple.h"
#include <Arduino.h>

Thermocouple::Thermocouple() { }

void Thermocouple::setup(uint8_t _type, uint8_t _decimal) {    
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
            case TYPE_K:      
                m = (10.0 + (element * 10.0)) / (uv_per_10C_K[element]);
                tempC = uVolt * m;
                break;

            default:
                tempC = 9999.9;
                break;
        }
    }
    
    return int(tempC * (1 + decimal));
}