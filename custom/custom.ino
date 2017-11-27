#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);

byte head1[8] = {
  0b00000,
  0b01000,
  0b01100,
  0b01110,
  0b01111,
  0b01110,
  0b01100,
  0b01000
  };
byte head2[8]={
  0b00000,
  0b00010,
  0b00110,
  0b01110,
  0b11110,
  0b01110,
  0b00110,
  0b00010,
  };

void setup() {
  lcd.init();
  lcd.backlight();
  
  lcd.createChar(1,head2);
  lcd.createChar(0,head1);
  lcd.begin(20,4);
}

void loop() {
  lcd.setCursor(0,2);
  for (int x=0;x<10;x++){
    lcd.setCursor(x,2);
    lcd.write(0);
    lcd.setCursor(19-x,2);
    lcd.write(1);
    delay(200);
    lcd.setCursor(x,2);
    lcd.print(" ");
    lcd.setCursor(19-x,2);
    lcd.print(" ");
    
  }

}
