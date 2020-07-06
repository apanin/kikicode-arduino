#define sensorPin A4
#define LED A0

int value = 0;    //set value to 0
void setup() 
{
 Serial.begin(9600); //set the baud rate to 9600
 pinMode(sensorPin, INPUT);
 pinMode(LED, OUTPUT);
}  
void loop() 
{
value = analogRead(sensorPin);  //set the value as the value read from A0
Serial.println(value, DEC);  //print the value and line wrap
delay(300);  //delay 0.2S

if (value > 40){
  analogWrite(LED, 255);
}

else analogWrite(LED, 0);
delay(500);
} 
