int incomingByte = 0; // for incoming serial data
int led = 10;
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
// initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}
void loop() {
// send data only when you receive data:
  if (Serial.available() > 0) {
// read the incoming byte:
    incomingByte = Serial.parseInt();
// check what you got:
    analogWrite(led,incomingByte);
}
}
