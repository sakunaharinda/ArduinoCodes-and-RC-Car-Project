#define outA 6
#define outB 7

int counter=0;
int aState;
int aLastState;

void setup() {
  pinMode(outA,INPUT);
  pinMode(outB,INPUT);

  Serial.begin(9600);
  aLastState=digitalRead(outA);
}

void loop() {
  aState=digitalRead(outA); 
  if (aState !=aLastState){
    if (digitalRead(outB)!= aState){
      counter++;
    }else{
      counter--;
    }
    Serial.print("position: ");
    Serial.println(counter);
  }
  aLastState=aState;
  
}
