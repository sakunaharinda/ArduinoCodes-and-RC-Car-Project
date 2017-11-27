#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);
char names[14]={'S','A','K','U','N','A',' ','H','A','R','I','N','D','A'};
void setup() {
  lcd.init();
  lcd.backlight();

}

void loop() {
  for (int x=0;x<14;x++){
    lcd.setCursor(x+3,2);
    lcd.print(names[x]);
    delay(50);
  }
  delay(1000);
  for (int x=0;x<14;x++){
    lcd.setCursor(x+3,2);
    lcd.print(" ");
    delay(50);
  }
  for (int x=3;x<17;x++){
    for (int y=0;y<3;y++){
      lcd.setCursor(x,y);
      lcd.print(names[x-3]);
      delay(50);
    }
    lcd.setCursor(x,0);
    lcd.print(" ");
    lcd.setCursor(x,1);
    lcd.print(" ");
  }
  delay(500);
  lcd.clear();
}
