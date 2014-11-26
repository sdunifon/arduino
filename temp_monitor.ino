#include <OneWire.h>
#include <DallasTemperature.h>
#include "temperature.h"
#include "temp_sensor.h"
// Data wire is plugged into pin 3 on the Arduino
#define ONE_WIRE_BUS 3
#define FLASH_PIN 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature tempSensors(&oneWire);






//uint8_t dd = {0x28, 0xFF, 0x98, 0x55, 0x73, 0x04, 0x00, 0xA8};
DeviceAddress tempSensor1Address =  {0x28, 0xFF, 0x98, 0x55, 0x73, 0x04, 0x00, 0xA8};
DeviceAddress tempSensor2Address = {0x28, 0xFF, 0xF6, 0x56, 0x77, 0x04, 0x00, 0x0D};


DallasTemperature sensors(&oneWire);
void setup(void)
{

  // start serial port
  Serial.begin(9600);
  // Start up the library
  sensors.begin();
  // set the resolution to 10 bit (good enough?)
  sensors.setResolution(tempSensor1Address, 10);
  sensors.setResolution(tempSensor2Address, 10);
  
  pinMode(FLASH_PIN, OUTPUT);     

}

void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  if (tempC == -127.00) {
    Serial.print("Error getting temperature");
  } else {
    Serial.print("C: ");
    Serial.print(tempC);
    Serial.print(" F: ");
    Serial.print(DallasTemperature::toFahrenheit(tempC));
  }
}

void loop(void)
{ 
  delay(250);
  Serial.print("Getting temperatures...\n\r");
  sensors.requestTemperatures();
  print_temperatures();
  String g = "the tempomb";
  TempSensor t(&tempSensor1Address,g );
  t.report();
  if(false){
    buzz();
    flash();
  }
}

void print_temperatures(){
  Serial.print("Temp Sensor 1 is: ");
  printTemperature(tempSensor1Address);
  Serial.print("\n\r");
  Serial.print("Temp Sensor 2 is: ");
  printTemperature(tempSensor2Address);
  Serial.print("\n\r\n\r");

}

void buzz(){
  int buzz_duration = 10;
  tone(6,1000,buzz_duration);
  delay(buzz_duration);

}

void flash(){
  digitalWrite(FLASH_PIN, HIGH);
  delay(100);
  digitalWrite(FLASH_PIN, LOW);
}
