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
Une fois que le sensor est bien fonctionnel, notez la valeur du sol quand il est sec. Elle vous servira comme valeur de seuil darrosage plus tard. Une fois que cette valeur est notée, vous pouvez experimenter et faire observer les changement de mesure quand le sol est humide..

## définir une fonction pour détecter l'humidité
Dans notre cas particulier,on cherche a définir quand le sol doit être arrosé par la pompe et combien de temps la pompe doit etre activée, ces variables sont situées au début du code. Vous pouvez définir la variable seuilDeSecheresse comme étant la valeur notée dans l'étape précédante. 
<div class="text-white bg-blue mb-2">
	La fonction activer pompe sera définie plus tard.
</div>


```c
#define DetecteurHumidite A2

+int seuilDeSecheresse;

void setup() {
	Serial.begin(9600);
	pinMode(DetecteurHumidite, INPUT);
}

void loop() {
	verifierHumidite();
	delay(2000);
}

+void verifierHumidite(){
	+//définir la fonction
+}

void activerPompe(){
}
```

<details><summary>Voir la fonction </summary>
<p>

```c
void verifierHumidite(){
	humidite = analogRead(DetecteurHumidite);
	Serial.println(humidite);
	//si le sol est sec, activer la pompe
	if (humidite < seuilSecheresse ){
		activerPompe();
	}
}
```

</p>
</details>

## Définir la fonction pour activer la pompe

###Ajouter les élements nécéssaire au circuit 

Un relais est un interrupteur que l'on peut ouvrir et fermer à l'aide d'un signal electrique. Il permet a un element du circuit d'être alimenter par une source extérieur tout en étant activé par le microcontrolleur. Si vous vous interessez aux relais vous pouvez en lire plus [ici](https://diyi0t.com/relay-tutorial-for-arduino-and-esp8266/)


###Faire la fonction

Une fois le circuit completé, vous allez maintenant définir la fonction pour activer la pompe.

```c
#define DetecteurHumidite A2
+#define Relais 3

int seuilDeSecheresse;
+int tempDarrosage;
void setup() {
	Serial.begin(9600);
	pinMode(DetecteurHumidite, INPUT);
}

void loop() {
	verifierHumidite();
	delay(2000);
}

void verifierHumidite(){
	+//définir la fonction
}

+void activerPompe(){
	+//définir la fonction
+}
```

<details><summary>Voir la fonction </summary>
<p>

```c
void activerPompe(){
	digitalWrite(Relais, HIGH);
	delay(tempsDarrosage);
	digitalWrite(Relais, LOW);
}
```
</p>
</details>

Attention, ne testez pas la pompe a l'exterieur de l'eau