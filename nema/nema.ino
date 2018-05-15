const int stepPinR = 10; 
const int dirPinR = 11;
const int stepPinL = 12; 
const int dirPinL = 13;
 
void setup() {
  pinMode(stepPinR,OUTPUT);   
  pinMode(dirPinR,OUTPUT);  
  pinMode(stepPinL,OUTPUT);  
  pinMode(dirPinL,OUTPUT);
  delay(2000); 
}

void loop() {  
   //turnNema(stepPinL,dirPinL,1,HIGH);
   //turnNema(stepPinR,dirPinR,1,HIGH);
   turnNemaBoth(1,LOW,HIGH);
}

void turnNema(int stepPin,int dirPin,int turn,int dir){
  digitalWrite(dirPin,dir); 
    
  for(int x = 0; x < (200*turn); x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1000);
  }
  
  delay(1000);
}

void turnNemaBoth(int turns,int dirL,int dirR){
  digitalWrite(dirPinL,!dirL); 
  digitalWrite(dirPinR,dirR); 
  
  for(int x = 0; x < (200*turns); x++) {
    digitalWrite(stepPinL,HIGH);
    digitalWrite(stepPinR,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPinL,LOW);
    digitalWrite(stepPinR,LOW);
    delayMicroseconds(1000);
  }
}
