//nema
const int stepPinR = 10; 
const int dirPinR = 11;
const int stepPinL = 12; 
const int dirPinL = 13;

//sonar
const int trigPinL = 22;
const int echoPinL = 24;
const int trigPinM = 26;
const int echoPinM = 28;
const int trigPinR = 30;
const int echoPinR = 32;
 
void setup() {
  //nema
  pinMode(stepPinR,OUTPUT);   
  pinMode(dirPinR,OUTPUT);  
  pinMode(stepPinL,OUTPUT);  
  pinMode(dirPinL,OUTPUT);

  //sonar
  pinMode(trigPinL, OUTPUT); 
  pinMode(echoPinL, INPUT); 
  pinMode(trigPinM, OUTPUT); 
  pinMode(echoPinM, INPUT); 
  pinMode(trigPinR, OUTPUT); 
  pinMode(echoPinR, INPUT); 
  
  delay(1000);
  //Serial.begin(9600);
}

void loop() {
//  if(getDistance(trigPinM,echoPinM)<=10){
//    //turn 360
//     turnNemaBoth(2.2,HIGH,LOW);    
//  }else{
//    //go straight
//     turnNemaBoth(0.5,HIGH,HIGH);
//  }

//    int curDistance=getDistance(trigPinL,echoPinL);
//    
//    if(5<=curDistance && curDistance<=10){
//      //straight
//      turnNemaBoth(0.01,HIGH,HIGH);    
//    }else if(curDistance<5){
//      //turn right
//      turnNemaBoth(0.01,HIGH,LOW);
//    }else if(curDistance>10){
//      //turn left
//      turnNemaBoth(0.01,LOW,HIGH);
//    }

  //Serial.println(getDistance(trigPinL,echoPinL)); 
  //turnNemaBoth(1,LOW,HIGH);
  //turnNemaBoth(0.05,HIGH,LOW);
  //delay(2000);
  //turnNemaBoth(2.2,LOW,HIGH);
  //delay(2000);
  turnNemaBoth(1,HIGH,HIGH);
}


//nema
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

void turnNemaBoth(double turns,int dirL,int dirR){
  digitalWrite(dirPinL,!dirL); 
  digitalWrite(dirPinR,dirR); 
  
  for(int x = 0; x < (200*turns); x++) {
    digitalWrite(stepPinL,HIGH);
    digitalWrite(stepPinR,HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPinL,LOW);
    digitalWrite(stepPinR,LOW);
    delayMicroseconds(2000);
  }
}

//sonar
int getDistance(int trig,int echo){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  double duration = pulseIn(echo, HIGH);

  int distance= duration*0.034/2;

  return distance;
}
