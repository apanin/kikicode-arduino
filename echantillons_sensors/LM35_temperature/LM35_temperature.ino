#define sensorPin A4
int data = 0;

void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
    pinMode(sensorPin, OUTPUT);
}
 void loop()
{   unsigned int val;
    float dat;

    val=analogRead(sensorPin);//Connect LM35 on Analog 0
    dat=(500 * val) /1023;;
    Serial.print("Temp:"); //Display the temperature on Serial monitor
    Serial.print(dat);
    Serial.println("C");
    delay(5000);
}
