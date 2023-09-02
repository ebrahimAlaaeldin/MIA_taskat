#include <Wire.h>
#define led 5
int state=-1; //initialize the state of two push buttons


void setup() {
  // initialize serila communication
  Wire.begin();
  Serial.begin(9600);
  pinMode(led,OUTPUT);// set the pin to output

  
}



void loop() {
  
  Wire.requestFrom(10,2); //request from  salve whose adress id 10 2 bits
  if(Wire.available()){
    state=Wire.read(); // read the data and store it in state
    Serial.println(state);

  } 
  

  if(state==0){  //state = 0 means p1=0 , p2=0
    Serial.println("No message");
    analogWrite(led,0);
  }
  else if(state==1){ // state = 1 means p1=1 , p2=0
    Serial.println("Vector focused");
    analogWrite( led,255/2);
  }
  else if(state==2){//state = 2 means p1=0 , p2=1
    Serial.println("Vector distracted");
    analogWrite(led,192);
  }
  else if(state==3){ ////state = 3 means p1=1 , p2=1
    Serial.println("Glitch");
    analogWrite(led,255);
  }


}

