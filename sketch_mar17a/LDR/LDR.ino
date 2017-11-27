int ledpin=10;
int ldrpin=A0;
int reading=0;
void setup() {
  pinMode(ledpin,OUTPUT);
  pinMode(ldrpin,INPUT);
  Serial.begin(9600);
}

void loop() {
  reading=(analogRead(ldrpin)-284)/2.807843;
  analogWrite(ledpin,reading);
  
}
