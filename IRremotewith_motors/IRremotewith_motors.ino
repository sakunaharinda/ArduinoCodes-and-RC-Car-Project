#include <IRremote.h>

IRrecv Car(11); //Create an object
decode_results(results);

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Car.enableIRIn();
}

void loop() {
  if (Car.decode(&results)){
    Serial.println(results.value,DEC);
    Car.resume();
  }
  delay (100);

  long val = results.value ;

  if (val == 16718055){
     // go forward
  digitalWrite(IN2,HIGH);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,LOW);
  }
  else if (val == 16730805){
    //go backward
  digitalWrite(IN1,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
  }

  else if (val == 16734885){
     //turn left

  digitalWrite(IN2,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,LOW);
  }
  else if (val ==  16716015){
    //turn right

  digitalWrite(IN2,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,LOW);
  }
  else if(val == 16726215){

    //stop
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,LOW);
  }



}
