#include <OneWire.h>
#include <DallasTemperature.h>
#ifndef temperature_h
#define temperature_h

#include <WString.h>



typedef struct RGB {
  int red;
  int green;
  int blue; 
} rgb;

typedef struct Thermometer {
  String label;
  DeviceAddress address;
  float current_temp;
  RGB temp_color;
} thermometer;

typedef struct LedRGB {
  int red_pin;
  int green_pin;
  int blue_pin;
} led_rgb;

#endif
