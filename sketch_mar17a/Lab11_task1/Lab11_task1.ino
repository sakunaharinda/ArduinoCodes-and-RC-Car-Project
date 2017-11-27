int redpin=8;
int yellowpin=9;
int greenpin=10;

void setup() {
  pinMode(redpin,OUTPUT);
  pinMode(yellowpin,OUTPUT);
  pinMode(greenpin,OUTPUT);

}

void loop() {
  digitalWrite(redpin,HIGH);
  delay(1000);
  digitalWrite(yellowpin,HIGH);
  delay(500);
  digitalWrite(redpin,LOW);
  digitalWrite(yellowpin,LOW);
  digitalWrite(greenpin,HIGH);
  delay(1000);
  digitalWrite(greenpin,LOW);
}
