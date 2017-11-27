#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.print("Hi");

}

void loop() {
  // put your main code here, to run repeatedly:

}
