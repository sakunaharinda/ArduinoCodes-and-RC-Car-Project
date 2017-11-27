
#include <LCD5110_Graph.h>

LCD5110 lcd(8,9,10,11,12); //create lcd variable and specify pins

extern uint8_t SmallFont[];

 
void setup() {
 
Serial.begin(9600); //turn on serial communication at 9600 bps
 
Serial.print("type what you want to display on nokia 5110 display caution it shouldnt be a number");  //guidance text to display on serial monitor
 
lcd.InitLCD();//initialize the lcd
 
lcd.setFont(SmallFont);//set the font
}
void loop() {
  if (Serial.available()){
 
    lcd.print(Serial.read(),0,0);//if data is available, read it and send it to display buffer
 
}
 
lcd.update();//copy the data from display buffer to the screen
 
}

