#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H
#define TC_TYPE_K 0
#define TC_FAULT_HIGH_LIMIT 1
#define TC_FAULT_LOW_LIMIT 2
#include <Arduino.h>

class Thermocouple {
  public:		
	  Thermocouple();
    void setup(uint8_t _type, uint8_t _decimal, int _faultLimit_L, int _faultLimit_H);
    int update(int _in);
    bool checkLimits();
    int getFaultCode();
  private:
    int type;
    int decimal;
    int uVolt;
    float tempC;
    int faultLimit_L, faultLimit_H;
    int faultCode;
    const int uv_per_10C_K[25] = {397,798,1203,1612,2023,2436,2851,3267,3682,4096,4509,4920,5328,5735,6138,6540,6941,7340,7739,8138,8539,8940,9343,9747,10153};
};
#endif