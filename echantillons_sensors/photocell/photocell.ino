/* 
Ks0028 keyestudio Photocell Sensor
_________________________________
|  SETUP                          | 
|Sensor pin  ::    Particle pin   |
|   +        ::        3.3v       |
|   -        ::        GND        |
|   S        ::        A0         |
|_________________________________|
SPECIFICATIONS:
analog sensor
max value: 4096
https://learn.adafruit.com/photocells/measuring-light
src: https://wiki.keyestudio.com/Ks0028_keyestudio_Photocell_Sensor
*/

#define sensorPin A4 
int value = 0; 
void setup() 
{
 Serial.begin(9600); } 
void loop() 
{
 value = analogRead(sensorPin); 
 
  Serial.println(value, DEC); 
 
  delay(1000); 
}
