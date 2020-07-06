/* 
KS0016 keye studio RGB LED
_________________________________
|  SETUP                          | 
|Sensor pin  ::    Particle pin   |
|   G        ::        D0       |
|   R        ::        D1         |
|   B        ::        D2         |
|   V        ::        5V         |
|_________________________________|
SPECIFICATIONS:
module emits rgb colorscheme
V serves as power
G R B serve as ground (for 3 different LEDS in one module)
Counter intuitively, you must insert current in the RGB pins in order to divert the current (255 = LOW)
src: https://wiki.keyestudio.com/Ks0068_keyestudio_37_in_1_Sensor_Kit_for_Arduino_Starters#Project_4:_RGB_LED
*/




#define greenpin 2
#define redpin 3
#define bluepin 4

int val;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
  }

void loop() {

  Serial.println("solo green");
  for(val=255; val>0; val--){
      analogWrite(greenpin, val);
      analogWrite(redpin, 255);
      analogWrite(bluepin, 255);
   delay(10); 
  }

  Serial.println("solo red");
  for(val=255; val>0; val--){
      analogWrite(greenpin, 255);
      analogWrite(redpin, val);
      analogWrite(bluepin, 255);
   delay(10); 
  }

    Serial.println("solo blue");
  for(val=255; val>0; val--){
      analogWrite(greenpin, 255);
      analogWrite(redpin, 255);
      analogWrite(bluepin, val);
   delay(10); 
  }

//color fluctuation from green
Serial.println("fluctuation from green/red");
  for(val=255; val>0; val--)
  {
   analogWrite(greenpin, val);
   analogWrite(redpin, 255-val);
   analogWrite(bluepin, 128-val);
   delay(10); 
  }
Serial.println("fluctuation from green/blue");
  for(val=255; val>0; val--)
  {analogWrite(greenpin, val);
   analogWrite(bluepin, 255-val);
   analogWrite(redpin, 128-val);
   delay(10); 
  }

//color fluctuation from red
Serial.println("fluctuation from red/green");
for(val=0; val<255; val++)
  {analogWrite(redpin, val);
   analogWrite(greenpin, 255-val);
   analogWrite(bluepin, 128-val);
   delay(10);  
  }
  Serial.println("fluctuation from red/green");
  for(val=0; val<255; val++)
  {analogWrite(redpin, val);
   analogWrite(bluepin, 255-val);
   analogWrite(greenpin, 128-val);
   delay(10);  
  }

//color fluctuation from blue
Serial.println("fluctuation from blue/red");
for(val=0; val<255; val++)
  {analogWrite(bluepin, val);
   analogWrite(redpin, 255-val);
   analogWrite(greenpin, 128-val);
   delay(10);  
  }
  Serial.println("fluctuation from blue/green");
for(val=0; val<255; val++)
  {analogWrite(bluepin, val);
   analogWrite(greenpin, 255-val);
   analogWrite(redpin, 128-val);
   delay(10);  
  }
}
