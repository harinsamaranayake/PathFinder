int l3=2;
int l2=3;
int l1=4;
int m0=5;
int r1=6;
int r2=7;
int r3=8;

void setup() {
  pinMode(l3,INPUT);
  pinMode(l2,INPUT);
  pinMode(l1,INPUT);
  pinMode(m0,INPUT);
  pinMode(r1,INPUT);
  pinMode(r2,INPUT);
  pinMode(r3,INPUT);

  Serial.begin(9600);
}

void loop() {  
  //Serial.print(getReading(l3)); 
  printAll(); 
  delay(50);
}

int getReading(int irPin){
  int reading=digitalRead(irPin);
  return reading;
}

void printAll(){
  Serial.print(getReading(l3));
  Serial.print(getReading(l2));  
  Serial.print(getReading(l1));
  Serial.print(getReading(m0)); 
  Serial.print(getReading(r1)); 
  Serial.print(getReading(r2)); 
  Serial.println (getReading(r3));  
}
