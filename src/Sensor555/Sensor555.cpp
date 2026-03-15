#include <Arduino.h>
#include "Sensor555.h"
#include "TimerOnDelay.h"

#define SENSOR555_NTC 0
#define SENSOR555_PTC 1

Sensor555::Sensor555() { }
void Sensor555::setup(uint16_t _timeoutMsec, float _unitPerMsec, float _offset, int safeVal) {
    timeoutMsec = _timeoutMsec;
    unitPerMsec = _unitPerMsec;
    offset = _offset;
    val = safeVal;
}

float Sensor555::update(int pinState) {
    // Pin went high-->low. Do calculate new value based on elapsed time ET
    if (timer.getTimerTiming() && !pinState) {
        pulseLength = timer.getTimerElapsedTime();
        //val = (pulseLength * unitPerMsec) + offset;
        long x;
        x = map(long(pulseLength), 1890, 1043, 23, 43);
        val = float(x);
    } else if (timer.getTimerDone()) {
        val = safeVal;
    }
    timer.update(pinState, timeoutMsec);
    return val;
    
}

uint16_t Sensor555::getPulseLength() {
    return pulseLength;
}