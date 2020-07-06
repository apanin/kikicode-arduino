#define LED 13
#define SENSOR A0

bool toggle;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);

  Serial.begin(9600);
  
  toggle = false;
}

void loop() {
  
  if (digitalRead(SENSOR)){
    toggle = !toggle;
    Serial.println(toggle);
  }
  
  if (toggle){
    digitalWrite(LED, HIGH);
  }
  else if (!toggle){
    digitalWrite(LED, LOW);
  }
  delay(500);
}
