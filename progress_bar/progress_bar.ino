#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);

#define lenght 20.0

double percent=100.0;
unsigned char b;
unsigned int peace;

// custom charaters

byte p1[8] = {
  0x10,
  0x10,
  0x10,
  0x10,
  0x10,
  0x10,
  0x10,
  0x10};

byte p2[8] = {
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18};

byte p3[8] = {
  0x1C,
  0x1C,
  0x1C,
  0x1C,
  0x1C,
  0x1C,
  0x1C,
  0x1C};

byte p4[8] = {
  0x1E,
  0x1E,
  0x1E,
  0x1E,
  0x1E,
  0x1E,
  0x1E,
  0x1E};

byte p5[8] = {
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F};

void setup()   {
  lcd.init();
  lcd.backlight();
  delay(100);
  lcd.createChar(0, p1);
  lcd.createChar(1, p2);
  lcd.createChar(2, p3);
  lcd.createChar(3, p4);
  lcd.createChar(4, p5);

  lcd.begin(20,4);
  lcd.setCursor(2,0);
  lcd.print("ELECTRONIC LIFE");
  lcd.setCursor(6,1);
  lcd.print("Loading ...");
  lcd.setCursor(2,3);
  lcd.print("Progress:     %");
  lcd.setCursor(0,1);
  for (int i =0;i<20;i++){
    for(int j=0;j<5;j++){
      lcd.setCursor(i,2);
      lcd.write(j);
      lcd.setCursor(12,3);
      int percent= j+1+(5*i) ;
      lcd.print(percent);
      delay(500);
    }
  }
  lcd.clear();
  
  
}

void loop()
{
    
}
