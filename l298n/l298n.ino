void setup() {
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

}

void loop() {
   digitalWrite(7,HIGH);
   delay(1000);
   digitalWrite(7,LOW);
   digitalWrite(6,HIGH);
   delay(1000);
   digitalWrite(6,LOW);

}
