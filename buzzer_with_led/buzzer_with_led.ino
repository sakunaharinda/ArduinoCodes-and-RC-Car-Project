int led = 6;
float sinVal;
int toneVal;
int buzzer=8;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(buzzer,INPUT);
}

void loop() {
  for (int x=0;x<180;x++){
    sinVal=sin(x*(3.1412/180));
    toneVal=2000 + int(sinVal*1000);
    tone(buzzer,toneVal);
    analogWrite(led,((toneVal-2000)*255)/1000);
    delay(5);
    analogWrite(led,0);
  }
}
