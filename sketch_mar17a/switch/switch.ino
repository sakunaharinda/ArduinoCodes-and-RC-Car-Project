int push=2;
int led=10;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(push,INPUT);
  

}

void loop() {
  if (digitalRead(push)==HIGH){
    digitalWrite(led,HIGH);
    }
   else if (digitalRead(push)==LOW){
    digitalWrite(led,HIGH);
    }

}
