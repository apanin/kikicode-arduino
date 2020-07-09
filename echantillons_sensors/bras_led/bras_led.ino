#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin
#define LEDPin 13          // Onboard LED

long duration, distance;

void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT);
}

void loop() {
  getDistance();
}

void getDistance(){
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);

 duration = pulseIn(echoPin, HIGH);
 distance = duration/58.2;
 Serial.println(distance);
 delay(500);
}
