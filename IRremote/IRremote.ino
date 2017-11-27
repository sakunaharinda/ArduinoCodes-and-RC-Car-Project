#include <IRremote.h>

IRrecv Sakuna(11);
decode_results results;
void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  Sakuna.enableIRIn();

}

void loop() {
  if (Sakuna.decode(&results)){
    Serial.println(results.value,DEC);
    Sakuna.resume();
  }
  delay(100);

  long val = results.value;
  

}
