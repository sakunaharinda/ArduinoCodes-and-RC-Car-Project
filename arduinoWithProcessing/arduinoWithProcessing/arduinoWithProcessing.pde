import processing.serial.*;
Serial myPort; // create a serialobject
String myText="";

void setup(){
  size(300,300); // set the window resolution
  myPort = new Serial(this,"COM3",9600);  //Initialize the port
  myPort.bufferUntil('\n'); 

}

void SerialEvent(Serial myPort){
  myText = myPort.readStringUntil('\n');
  
}

void draw(){
  background(0,0,0); // set the background as Black
  text(myText,120,120); // print mytext in the coordinates 120,120 when button pressed
  myText =""; // print nothing when button released
  
  if (mousePressed && (mouseButton==LEFT)){
    myPort.write('1');
  }
  if (mousePressed && (mouseButton == RIGHT)){
    myPort.write('0');
  }
  
}