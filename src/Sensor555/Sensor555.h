#ifndef SENSOR555_H
#define SENSOR555_H
#include <Arduino.h>
#include "TimerOnDelay.h"

class Sensor555 {
  public:		
	  Sensor555();
    void setup(uint16_t _timeoutMsec, float _unitPerMsec, float _offset, int safeVal);
    float update(int pinState);
    uint16_t getPulseLength();
  private:
    float val;
    uint16_t pulseLength;
    int safeVal;
    bool timeout;
    uint16_t timeoutMsec;    
    TimerOnDelay timer;
    float unitPerMsec, offset;
};
#endif