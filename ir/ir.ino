int irPin=2;

void setup() {
  pinMode(irPin,INPUT); 
  
  Serial.begin(9600);
}

void loop() {
  int reading=getReading(irPin);  
  Serial.print(reading); 
    
  delay(1000);
}

int getReading(int irPin){
  int reading=digitalRead(irPin);
  return reading;
}
