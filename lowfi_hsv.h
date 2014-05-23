
/*
  Lowfi HSV was written by Aeva Palecek, and the code is available to
  you via CC0.  Have a lovely day!
 */

#ifndef LOWFIHSV_h
#define LOWFIHSV_h


#include "Arduino.h"


void hsv(byte h, byte s, byte v, byte &r, byte &g, byte &b);

void hue_to_rgb(byte h, byte &r, byte &g, byte &b);


#endif
