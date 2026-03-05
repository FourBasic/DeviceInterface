#ifndef SENSOR555_H
#define SENSOR555_H
#define SENSOR_FAULT_HIGH_LIMIT 1
#define SENSOR_FAULT_LOW_LIMIT 2
#include <Arduino.h>

class Sensor555 {
  public:		
	  Sensor555();
    void setup(uint16_t _timeout, int _faultLimit_L, int _faultLimit_H);
    float update();
    bool checkLimits();
    int getFaultCode();
  private:
    float val;
    int faultLimit_L, faultLimit_H;
    int faultCode;
    uint16_t timeout;
}
#endif