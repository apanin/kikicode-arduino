int Index;

void setup() 
{
  Serial.begin(115200);
  pinMode(6, OUTPUT); //Enable
  pinMode(5, OUTPUT); //Step
  pinMode(4, OUTPUT); //Direction

  digitalWrite(6,LOW);
}

void loop() 
{
  Serial.println('x');
  digitalWrite(4,HIGH);

  for(Index = 0; Index < 2000; Index++)
  {
    digitalWrite(5,HIGH);
    delayMicroseconds(500);
    digitalWrite(5,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

  digitalWrite(4,LOW);

  for(Index = 0; Index < 2000; Index++)
  {
    digitalWrite(5,HIGH);
    delayMicroseconds(500);
    digitalWrite(5,LOW);
    delayMicroseconds(500);
  }
  delay(1000);
}
