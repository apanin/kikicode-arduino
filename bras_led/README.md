# Bras robotisé avec LED

<img src="https://github.com/apanin/kikicode-arduino/blob/master/bras_led/hookup.jpg" width="50%" height="50%" />


## LES DÉTECTEUR ULTRASON
1. Connecte le capteur ultrason comme sur le schéma.
Vcc : 5v
echo: D2
trig: D3
gnd: gnd
 
2. Crée un nouveau fichier arduino

3. Déclare les valeurs suivantes au début du code:

```c
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
	// put your main code here, to run repeatedly:

}
```

4. Copie-colle la fonction suivante à la fin du code.
(C'est la fonction qui détecte la proximité)

```c
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
```

5. Apelle la fonction dans la fonction loop()

```c
void loop() {
	getDistance();
}
```

À la fin de tous ses étapes, roule le code, regarde les distances.

<details><summary>Normalement ton code devrait avoir l'air de ceci</summary>
<p>

```c
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
```

</p>
</details>
