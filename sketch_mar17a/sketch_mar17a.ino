int ldr = 10;  

void setup() {
  pinMode(ldr,INPUT);
  Serial.begin(9600);
}

void loop() {
  
  Serial.println(analogRead(ldr));
  
}
