#include <Arduino.h>
#ifndef GLOBALS_
#define GLOBALS_

unsigned long previousMillis = millis();

enum { GETUPDATE, SHOWVALUES, WAIT } state;

struct sensordata {
  String update_date;
  int voltage;
  String update_clock;
  int temperature;
  int humidity;
};

sensordata mySensorData;

#endif
