
#define trigR 2
#define echoR 3

#define trigL 2
#define echoL 3

#define trigU 2
#define echoU 3

#define trigD 2
#define echoD 3

long duration;
float distance;

float dR=0,dL=0,dU=0,dD=0,X=0,Y=0;



void setup() {
  //declaration of echo and trig pins
  char trig[4]={trigD,trigL,trigR,trigU};
  char echo[4]={echoD,echoL,echoR,echoU};

  for(int i=0 ;i<4;i++){
    pinMode(trig[i],OUTPUT);
    pinMode(echo[i], INPUT);

  }

}

void loop() {
  dR=ultrasoncDown();
  dD=ultrasoncDown();
  dL=ultrasoncLeft();
  dU=ultrasoncUp();
  
 // since we don't have the accuracy of each sensor so we eil use normal averaging to enhance the reading for the position of cookie
 if(dR+dL!=5){
   float avergWidth=abs(5-(dL+dR))/2;
   X= dL+avergWidth;
 }
 else{
   X=dL;
 }
 if(dD+dU!=6){
   float avergHeight=abs(6-(dU+dD))/2;
   Y= dD+avergHeight;
 }
 else{
   Y=dD;
 }
  Serial.print("(");
  Serial.print(X);
  Serial.print(",");
  Serial.print(Y);
  Serial.print(")");




  // put your main code here, to run repeatedly:

}
