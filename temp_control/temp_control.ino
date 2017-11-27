
#include <OneWire.h>
#include <DallasTemperature.h>
#include<LiquidCrystal_I2C.h>
#include <Wire.h>

#define DATA_PIN 3
#define SENSOR_RESOLUTION 9
#define SENSOR_INDEX 0

LiquidCrystal_I2C lcd(0x3F,20,4);
OneWire oneWire(DATA_PIN);
DallasTemperature sensors(&oneWire);
DeviceAddress sensorDeviceAddress;

void setup() {
  //Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  sensors.begin();
  sensors.getAddress(sensorDeviceAddress,0);
  sensors.setResolution(sensorDeviceAddress,SENSOR_RESOLUTION);
  

}

void loop() {
  sensors.requestTemperatures();
  float tempinc = sensors.getTempCByIndex(SENSOR_INDEX);
  float tempinf = sensors.getTempFByIndex(SENSOR_INDEX);

  lcd.setCursor(13,1);
  //Serial.print("Temperature: ");
  lcd.print(tempinc,2);
  lcd.print(char(223));
  lcd.print("C");
  lcd.setCursor(13,2);
  lcd.print(tempinf,2);
  lcd.print(char(223));
  lcd.print("F");
  delay(1000);

}
