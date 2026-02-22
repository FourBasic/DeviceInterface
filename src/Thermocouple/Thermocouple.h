#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H
#define TYPE_K 0
#include <Arduino.h>

class Thermocouple {
  public:		
	  Thermocouple();
    setup(uint8_t _type);
    int update(int _in);
  private:
    int type
};
#endif