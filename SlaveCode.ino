//

//include i2c library

#include<Wire.h>
#define push1 7
#define push2 8

int p1=0, p2=0;




void setup() {
 //initialize i2c communication
  Wire.begin(10);
  Wire.onRequest(pushButtonState);
   // initialize serila communication
  Serial.begin(9600);
  pinMode(push1, INPUT_PULLUP);
  pinMode(push2, INPUT_PULLUP);

  // initialize i2c communication protocole
  

  
  
}




void loop() {
  delay(50);
   // make a delay to get the actual read from the push button
}
void pushButtonState (){
  p1 = digitalRead(push1);
  delay(50);  // make a delay to get the actual read from the push button
  p2 = digitalRead(push2);
  delay(50); 
 
 
  if (p1==0 && p2==0){
    Wire.write(0);// 0 means p1=0,p2=0
  
  }
  else if(p1==1 && p2 ==0){
    Wire.write(1); //means p1=1,p2=0
    

  }
  else if(p1==0 && p2 == 1){
    Wire.write(2);//means p1=0, p2=1
    
  }
  else{
    Wire.write(3); //means p1=1,p2=1
  }
}
