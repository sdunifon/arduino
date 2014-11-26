#include "temp_sensor.h"

TempSensor::TempSensor(DeviceAddress* address_param, String name_param){
  //address =  address_param;
  b = &address_param;
  name = name_param;  
}
void TempSensor::report()
{

  Serial.print("------You got me girl--------:" + name );
  Serial.print(name + ":");
  Serial.print(tempF());
  Serial.print("\n\r");

}


float TempSensor:: tempF(){
  return DallasTemperature::toFahrenheit(tempC()); 
}
float TempSensor::tempC(){
  return sensors.getTempC(b);
}
