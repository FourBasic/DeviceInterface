#ifndef HMC5883L_H
#define HMC5883L_H
#include <Arduino.h>
#include "lib/HMC5883Llib.h"

class Compass {
  public:		
	  Compass();
    int setup();
    int update();
    int get360();
    int get180();
  private:
    Magnetometer mag;
    bool fail;
    int heading360, heading180;
};
#endif