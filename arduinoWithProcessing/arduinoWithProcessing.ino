int led=13;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()>0){
    char state = Serial.read();
    if (state == '1'){
      digitalWrite(led,HIGH);
      
    }
    else if (state == '0'){
      digitalWrite(led,LOW);
      
    }
  }

}
