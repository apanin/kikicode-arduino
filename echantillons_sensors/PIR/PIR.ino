/* 
Ks0052 keyestudio PIR Motion Sensor
_________________________________
|  SETUP                          | 
|Sensor pin  ::    Particle pin   |
|   +        ::        3.3v       |
|   -        ::        GND        |
|   S        ::        D0         |
|_________________________________|
SPECIFICATIONS:
range of 3-4m
slow response speed (3-4s)
may have false positives
src: https://wiki.keyestudio.com/Ks0052_keyestudio_PIR_Motion_Sensor
*/

#define sensorPin A4
#define ledPin 13

void setup()
{
  pinMode(sensorPin,INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  byte state = digitalRead(sensorPin);
  digitalWrite(ledPin,state);
  delay(100);
}
