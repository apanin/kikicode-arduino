# Plante intelligente

https://diyi0t.com/relay-tutorial-for-arduino-and-esp8266/


## Brief
Le but de ce projet est de créer une plante qui détecte quand l'humidité de son sol est faible et peu s'arroser
à l'aide d'une pompe dans un bocal d'eau. De plus, le bocal d'eau sera connecté a un detecteur de niveau d'eau qui sera affiché par des neopixels.
Si le niveau d'eau est trop bas, la pompe ne s'activera pas.

## Matériel
* Arduino nano
* Pompe 5v
* detecteur d'humidité
* detecteur de niveau d'eau
* bande led 5v
* relais
* breadboard

* une plante
* un bocal d'eau
* un tuyau


## Étape 1
#detecteur d'humidité

La première étape sera d'installer le détecteur d'humidité
Commencer par tester les données obtenues par un detecteur d'humidite.
Verser un peu d'eau sur la plante pour voir la difference quand le sol est sec vs quand le sol est humide.

```c
#define DetecteurHumidite A2

void setup() {
	Serial.begin(9600);
	pinMode(DetecteurHumidite, INPUT);
}

void loop() {
	Serial.println(analogRead(DetecteurHumidite);
	delay(2000);	
}
```

Telechargez ce code sur l'arduino.
Une fois que le sensor est bien fonctionnel, saturez la plante d'eau et notez le niveau d'humidité sur un papier.
Cette valeur vous servira plus tard dans le code.

<details>
	<summary>Voir le code</summary>
	</p>
	
	```c
	void verifierHumidite(){
		humidite = analogRead(DetecteurHumidite);
		Serial.println(humidite);
		//si le sol est sec, activer la pompe
		if (humidite < seuilSecheresse && niveauDeau > 0){
			Serial.println('x');
			digitalWrite(Relais, HIGH);
			delay(tempsDarrosage);
			digitalWrite(Relais, LOW);
		}
	}
	```

</details>