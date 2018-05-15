const int trigPin = 30;
const int echoPin = 32;
//22 24 | 26 28 | 30 32

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  Serial.println(getDistance(trigPin,echoPin));
  delay(1000);
}

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
