#include <OneWire.h>
#include <DallasTemperature.h>
#ifndef temp_sensor_h
#define temp_sensor_h

#include <WString.h>


class TempSensor
{
  public:
    TempSensor(DeviceAddress* d_address, String name);
    void report();
    float tempC();
    float tempF();    
  private:
    uint8_t address;
    String name;
    DeviceAddress b;
};

#endif
