

int led=13;
char val;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()){
    val=Serial.read();
    Serial.println(val);
  }
  if (val=='1'){
    digitalWrite(led,HIGH);
  }
  else if(val=='2'){
    digitalWrite(led,LOW);
  }
  delay(1000); 

}
