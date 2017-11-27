float sinVal;
int toneVal;
int buzzer=8;

void setup() {
  pinMode(buzzer,OUTPUT);

}

void loop() {
  for(int x;x<180;x++){
    sinVal=sin(x*(3.1412/180));
    toneVal = 2000 + (int(sinVal*1000));
    tone(buzzer,toneVal,1000000);
    delay(2);
  }

}
