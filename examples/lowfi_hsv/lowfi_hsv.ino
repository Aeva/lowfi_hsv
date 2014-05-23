#include <lowfi_hsv.h>


// state stuff
byte hue = 255;
byte sat = 255;
byte val = 255;
byte red = 0;
byte grn = 0;
byte blu = 0;
byte durp = 157; // floor(255*phi)%255


void setup() {
  Serial.begin(57600);
  Serial.println("lean hsv debug");
}


void loop() {
  //hue_to_rgb(hue, red, grn, blu);
  hsv(hue, sat, val, red, grn, blu);
  print_hsv();
  hue += 20;
  sat += durp;
  val -= durp;
  delay(100);
}


void print_hsv() {
  /*
    The output here conforms to the following ranges:
    hue: 0-360
    sat: 0-100
    val: 0-111
    red: 0-255
    grn: 0-255
    blu: 0-255
   */

  Serial.print("hsv(");
  Serial.print(floor((float)(hue)/255.0*360), 0);
  Serial.print(", ");
  Serial.print(floor((float)(sat)/255.0*100), 0);
  Serial.print(", ");
  Serial.print(floor((float)(val)/255.0*100), 0);
  Serial.print(") --> rgb(");
  Serial.print(red);
  Serial.print(", ");
  Serial.print(grn);
  Serial.print(", ");
  Serial.print(blu);
  Serial.print(")\n");
}
