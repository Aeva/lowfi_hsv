
/*
  Lowfi HSV was written by Aeva Palecek, and the code is available to
  you via CC0.  Have a lovely day!
 */
#include "lowfi_hsv.h"




void hsv(byte h, byte s, byte v, byte &r, byte &g, byte &b) {
  /*
    This function takes an arbitrary HSV value expressed as three
    bytes and calculates the RGB values.  The function is intended to
    be used in situations where memory is scare.
  */
  byte f = 0xff & (h*6);
  byte p = (255 - s) * v/255;
  byte q = (255 - f * s/255) * v/255;
  byte t = (255 - (255 - f) * s/255) * v/255;
  switch ((h*6/255)%6) {
     case 0: r = v, g = t, b = p; break;
     case 1: r = q, g = v, b = p; break;
     case 2: r = p, g = v, b = t; break;
     case 3: r = p, g = q, b = v; break;
     case 4: r = t, g = p, b = v; break;
     case 5: r = v, g = p, b = q; break;
  }
}




void hue_to_rgb(byte h, byte &r, byte &g, byte &b) {
  /*
    This function takes an arbitrary hue value expressed as a byte and
    calculates the RGB values.  The function is intended to be used in
    situations where memory is scare.
   */
  byte f = 0xff & (h*6);
  switch (((h*6)/255) % 6) {
     case 0: r = 255,   g = f,     b = 0; break;
     case 1: r = 255-f, g = 255,   b = 0; break;
     case 2: r = 0,     g = 255,   b = f; break;
     case 3: r = 0,     g = 255-f, b = 255; break;
     case 4: r = f,     g = 0,     b = 255; break;
     case 5: r = 255,   g = 0,     b = 255-f; break;
  }
}
