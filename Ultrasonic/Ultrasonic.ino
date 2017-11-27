#define trig 2
#define echo 4

//int red=12;
//int green=13;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
 // pinMode(red,OUTPUT);
 // pinMode(green,OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long t = pulseIn(echo,HIGH);

  long inches= t/74/2;
  long cm = t/29/2;

  //Serial.print(inches);
  //Serial.print("in \t ");
  //Serial.print(cm);
  //Serial.println("cm");
  //delay(100);

  //if (cm<10){
    //digitalWrite(red,HIGH);
    //digitalWrite(green,LOW);
    
  //}else {
    //digitalWrite(red,LOW);
    //digitalWrite(green,HIGH);
  //}

  
  
}
