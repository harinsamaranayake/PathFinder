const int trigPin = 30;
const int echoPin = 32;

void setup() {
  //pin setup
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  
  Serial.begin(9600);
}

void loop() {
  double distance=getDistance(trigPin,echoPin);
  Serial.println(distance);
  
  delay(1000);
}

int getDistance(int trig,int echo){
  //clear channels
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  //send signal
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  double duration = pulseIn(echo, HIGH);
  
  int distance= duration*0.034/2;

  return distance;
}
