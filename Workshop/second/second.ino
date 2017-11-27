int led =13;
int switch1 = 15;
int value;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(switch1,INPUT);
  Serial.begin(9600);

}

void loop() {
  value = analogRead(switch1);
  Serial.println(value);
  analogWrite(led,map(value,100,800,0,255));
    

}
