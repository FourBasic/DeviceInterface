#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H
#define TYPE_K 0
#include <Arduino.h>

class Thermocouple {
  public:		
	  Thermocouple();
    void setup(uint8_t _type, uint8_t _decimal);
    int update(int _in);
  private:
    int type;
    int decimal;
    int uVolt;
    float tempC;
    const int uv_per_10C[25] = {397,798,1203,1612,2023,2436,2851,3267,3682,4096,4509,4920,5328,5735,6138,6540,6941,7340,7739,8138,8539,8940,9343,9747,10153};
};
#endif;