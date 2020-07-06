#define sensor A4

void setup()
{
  Serial.begin(9600);
  pinMode(sensor,INPUT);

}

void loop() 
{
  Serial.println(analogRead(sensor));
  delay(1000);
}
