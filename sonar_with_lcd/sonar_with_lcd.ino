#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);

#define trig 2
#define echo 4
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Distance Finder");
  lcd.setCursor(0,2);
  lcd.print("Distance(in.): ");
  lcd.setCursor(0,3);
  lcd.print("Distance(cm): ");
  //Serial.begin(9600);

}

void loop() {
  digitalWrite(trig , LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long t=pulseIn(echo,HIGH);
  long inch = t/74/2;
  long cm=t/29/2;
  for(int x=15;x<20;x++){
    lcd.setCursor(x,2);
    lcd.print(" ");
    lcd.setCursor(x,3);
    lcd.print(" ");
    
  }
  lcd.setCursor(15,2);
  lcd.print(inch);
  lcd.setCursor(15,3);
  lcd.print(cm);
  //Serial.print(inch);
  //Serial.print(" in\t");
  //Serial.print(cm);
  //Serial.println("cm");
  delay(500);
}
