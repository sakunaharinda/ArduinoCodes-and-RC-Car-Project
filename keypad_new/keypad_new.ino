#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <EEPROM.h>

byte rowpins[4] = {9,8,7,6};
byte colpins[4] = {5,4,3,2};

char password[4]; // stores entered password
char pass[4],pass1[4]; // stores initial password and changed password
char key=0; // stores keypad input
char keys[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };

int i=0; 
int gLed = 13;
int yLed =12;
int rLed =11;
int buzzer = 10;
int toneVal;

float sinVal;

Keypad pad=Keypad(makeKeymap(keys),rowpins,colpins,4,4);
LiquidCrystal_I2C lcd (0x3F,20,4);
void setup() {
  pinMode(gLed,OUTPUT);
  pinMode(yLed,OUTPUT);
  pinMode(rLed,OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(5,1);
  lcd.print("ELECTRONIC");
  lcd.setCursor(6,2);
  lcd.print("Door-Lock");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter your password: ");
  lcd.setCursor(3,1);
  for (int x=0;x<4;x++){
    EEPROM.write(x+50,x); // set the initial password "1234"
  }
  for (int y=0 ; y<4 ;y++){
    pass[y]=EEPROM.read(y);  // get the initial password to pass array
  }

}

void loop() {
  digitalWrite(rLed,HIGH);  // Initially red light on
  key = pad.getKey();
  if (key == '#')
    change();
  if (key){
    password[i++]=key;
    lcd.print(key);
    siren();
  }
  if (i==4){
    delay(200);
    for (int x=0;x<4;x++){
      pass[x]=EEPROM.read(x);
  }
    if (!(strncmp(password,pass,4))){
      blinkLed(rLed);
      blinkLed(gLed);
      digitalWrite(gLed,HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Password Accepted ");
      lcd.setCursor(0,1);
      lcd.print("Door Opened");
      delay(2000);
      enter();
      i=0;
    }else{
      blinkLed(rLed);
      // buzzer
      lcd.clear();
      lcd.print("Access Denied...");
      delay(2000);
      enter();
      i=0;
      //buzzer off
    }
  }
}

// Function to set the leds Blink
void blinkLed(int pin){
  for(int x=0 ; x <5 ;x++){
    digitalWrite(pin,HIGH);
    delay(100);
    digitalWrite(pin,LOW);
    delay(100);
  }
}

// Function to beep

void siren(){
  tone(buzzer,2500);
  delay(50);
  noTone(buzzer);
  delay(50);  
}
// Function to enter
void enter(){
  lcd.setCursor(0,0);
  lcd.print("Press # to change");
  delay(2000);
  lcd.clear();
  lcd.print("Enter your password: ");
  digitalWrite(gLed,LOW);
  digitalWrite(rLed,HIGH);
  lcd.setCursor(3,1);
}

// Function to change
void change(){
  digitalWrite(rLed,LOW);
  digitalWrite(gLed,LOW);
  blinkLed(yLed);
  digitalWrite(rLed,HIGH);
  int j=0;
  lcd.clear();
  lcd.print("Your current Password :");
  lcd.setCursor(1,1);
  while (j<4){
    char key1 = pad.getKey();
    if(key1){
      pass1[j++]=key1;
      lcd.print(key1);
      siren();
    }
    key1=0;
  }
  delay(500);
  if (strncmp(pass1,pass,4)){
    lcd.clear();
    lcd.print("Wrong Password ...");
    blinkLed(rLed);
    lcd.setCursor(0,1);
    lcd.print("Try Again ...");
    delay(1000);
  }else{
    j=0;
    lcd.clear();
    lcd.print("Enter New Password:");
    lcd.setCursor(1,1);
    while (j<4){
      char key1=pad.getKey();
      if (key1){
        pass[j++] = key1;
        lcd.print(key1);
        EEPROM.write(j,key1);
        siren();
      }
    }
    blinkLed(yLed);
    digitalWrite(gLed,HIGH);
    lcd.setCursor(0,2);
    lcd.print("Done ! Good to go");
    delay(1000);
  }
  enter();
  key=0;
  i=0;
}

  


