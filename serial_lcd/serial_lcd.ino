#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd (0x3F,20,4);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("My Second Project");
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()){
    lcd.clear();
    lcd.setCursor(5,2);
    while (Serial.available()>0){
      lcd.write(Serial.read());
      
    }
    
  }

}
