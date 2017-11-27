#include<LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F,20,4);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print(char(223));
  lcd.setCursor(1,0);
  lcd.print("C");

}

void loop() {
  // put your main code here, to run repeatedly:

}
