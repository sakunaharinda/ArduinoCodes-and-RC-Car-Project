#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);
int input=A1;
float vout=0.0;
float vin=0.0;
float r1=27000.0;
float r2=7500.0;
int value;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(input,INPUT);
  lcd.setCursor(3,0);
  lcd.print("Voltage meter");
  lcd.setCursor(1,2);
  lcd.print("Voltage :      V");
  //Serial.begin(9600);

}

void loop() {
  lcd.setCursor(11,2);
  value=analogRead(input);
  vout=(value*5.0)/1024.0;
  vin=vout/(r2/(r1+r2));
  lcd.print(vin);

  //Serial.print("Voltage: ");
  //Serial.println(vin,2);
  delay(500);
}
