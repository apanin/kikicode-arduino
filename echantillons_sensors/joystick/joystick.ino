/* 
Ks0008 keyestudio Joystick Module
_________________________________
|  SETUP                          | 
|Sensor pin  ::    Particle pin   |
|   +        ::        3.3v       |
|   -        ::        GND        |
|   B        ::        D0         |
|   X        ::        A0         |
|   Y        ::        A1         |
|_________________________________|
SPECIFICATIONS:
digital button + xy analog map
maps x and on from 0 to 4095
src: https://wiki.keyestudio.com/Ks0008_keyestudio_Joystick_Module
*/

#define JoyStick_X A4 //x
#define JoyStick_Y A5 //y
#define JoyStick_Z 4 //key
#define LED 13

int x,y,z;

void setup() 
{
//  pinMode(JoyStick_Z, INPUT); 
  Serial.begin(9600); // 9600 bps
}

void loop() 
{
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  z=digitalRead(JoyStick_Z);
  Serial.print("x: ");
  Serial.print(x ,DEC);
  Serial.print(", y:");
  Serial.print(y ,DEC);
  Serial.print(", z:");
  Serial.println(z ,DEC);

  readJoystick();
  
  delay(1000);
}


void readJoystick(){
  if (x <= 400){
    Serial.print("bas ");
  }
  else if (x >= 600){
    Serial.print("haut ");
  }
  else {
    Serial.print("centre ");
  }
  
  if (y <= 400){
    Serial.println("gauche ");
  }
  else if (y >= 600){
    Serial.println("droite ");
  }

  else Serial.println("centre ");
}
