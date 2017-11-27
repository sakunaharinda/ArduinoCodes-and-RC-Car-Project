int ldrpin=A0;
int reading=0;
void setup() {
  pinMode(ldrpin,INPUT);
  Serial.begin(9600);

}

void loop() {
  
    reading=analogRead(ldrpin);
    Serial.println(reading);
    
}
