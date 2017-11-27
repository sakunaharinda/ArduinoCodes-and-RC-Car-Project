#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);

byte heart1[8] = {
  0b00110,
  0b01001,
  0b01000,
  0b01000,
  0b00100,
  0b00010,
  0b00001,
  0b00000
};

byte heart2[8] = {
  0b01100,
  0b10010,
  0b00010,
  0b00010,
  0b00100,
  0b01000,
  0b10000,
  0b00000
};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,heart1);
  lcd.createChar(1,heart2);
  lcd.begin(20,4);
  lcd.setCursor(6,2);
  lcd.write(0);
  lcd.write(1);
  

}

void loop() {
  

}
