#include "Thermocouple.h"
#include <Arduino.h>

Thermocouple::Thermocouple() { }

void Thermocouple::setup(uint8_t _type, uint8_t _decimal) {    
    type = _type;
    decimal = _decimal;
}

int Thermocouple::update(int _uVolt) {
    uVolt = _uVolt;
    tempC = uVolt * uv_per_10C[0];
}