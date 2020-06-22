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
* batterie 9v
* prise micro usb b

* une plante
* un bocal d'eau
* un tuyau


## Detecteur d'humidité

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
	La fonction activer pompe sera définie plus tard.



```c
#define DetecteurHumidite A2

+ int seuilDeSecheresse;

+ float humidite;

void setup() {
	Serial.begin(9600);
	pinMode(DetecteurHumidite, INPUT);
}

void loop() {
	verifierHumidite();
	delay(2000);
}

+ void verifierHumidite(){
	+ //définir la fonction
+ }

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

### Ajouter les élements nécéssaire au circuit 

Un relais est un interrupteur que l'on peut ouvrir et fermer à l'aide d'un signal electrique. Il permet a un element du circuit d'être alimenter par une source extérieur tout en étant activé par le microcontrolleur. Si vous vous interessez aux relais vous pouvez en lire plus [ici](https://diyi0t.com/relay-tutorial-for-arduino-and-esp8266/)


### Faire la fonction

Une fois le circuit completé, vous allez maintenant définir la fonction pour activer la pompe.

```c
#define DetecteurHumidite A2
+#define Relais 3

int seuilDeSecheresse;
+ int tempDarrosage;
void setup() {
	Serial.begin(9600);
	pinMode(DetecteurHumidite, INPUT);
}

void loop() {
	verifierHumidite();
	delay(2000);
}

void verifierHumidite(){
  //définir la fonction
}

+ void activerPompe(){
	+ //définir la fonction
+ }
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

## Mettre le détecteur de niveau d'eau;

Ajoutez les élements suivants au circuit

Une fois que les elements sont ajoutés faites une fonction pour calculer le niveau d'eau.
Ouvrez un autre onglet et faites notez les valeurs en fonction de 3 niveaux d'eau différents (bas, moyen, haut). Ces valeurs serviront d'intervales pour la fonction de la prochaine étape.

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

Une fois que vous avez noté les resultats vous pouvez faire une fonction 
```c
#define DetecteurHumidite A2
#define Relais 3
#define DetecteurNiveauDeau A3

int seuilDeSecheresse = 700;
int tempDarrosage = 500;

float humidite;
float niveauDeau;

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

void activerPompe(){
	//définir la fonction
}

void verifierNiveauDeau(){
	void verifierNiveauDeau(){
		niveauDeau = analogRead(DetecteurNiveau);
		if (niveauDeau<=480){ 
			//rien pour l'instant
		}
		else if (niveauDeau>480 && niveauDeau<=705){ 
			// rien pour l'instant
		}
		else if (niveauDeau>705){ 
			// rien pour l'instant
		}
	}
```

## Detail sur la fonction activer pompe

maintenant que nous avons le niveau de l'eau et nous savons que si elle fonctionne sans eau elle se brise, modifiez la fonction verifierHumidité par celle ci.

```c
void verifierHumidite(){
	humidite = analogRead(DetecteurHumidite);
	Serial.println(humidite);
	//si le sol est sec, activer la pompe
	if (humidite < seuilSecheresse && niveauDeau > 480){
		activerPompe();
	}
}
```

## Ajouter les LEDS

Ajouter les neopixels au circuit


### Modification du code

définir des couleurs dans l'en-tête. Chaque couleur est définie en fonction de (rouge, vert, bleu),
chacune des valeurs est un int de 0 à 255.

```c
#define ROUGE pixels.Color(255, 0, 0)
#define JAUNE pixels.Color(255, 150, 0)
#define VERT pixels.Color(0, 255, 0)
#define BLEU pixels.Color(0, 0, 255)
```

vous pouvez utiliser les couleurs comme telles, mais vous pouvez aussi définir vos propres couleurs.

### ajouter les changements de couleur au code.

Modifiez verifierNiveauDeau() afin que les leds affichent rouge quand le niveau d'eau est bas, jaune quand il est moyen et rouge quand il est bas.

Modifiez activerPompe() pour que les leds affichent bleu quand la pompe est activée.

Pour changer les couleurs des neopixels, vous pouvez utiliser les lignes suivantes
```c
pixels.clear();
pixels.fill(COULEUR);
pixels.show();
```

## Résultar

<details><summary>Voir le code entier </summary>
<p>

```c
#include <Adafruit_NeoPixel.h>

#define Led A0
#define DetecteurHumidite A2
#define DetecteurNiveau A3
#define Relais 3

float humidite;
float niveauDeau;
int seuilSecheresse = 700;
int tempsDarrosage = 500;

#define ROUGE pixels.Color(255, 0, 0)
#define JAUNE pixels.Color(255, 150, 0)
#define VERT pixels.Color(0, 255, 0)
#define BLEU pixels.Color(0, 0, 255)

	
Adafruit_NeoPixel pixels(5, Led, NEO_GRB + NEO_KHZ800);

void setup() {
	Serial.begin(9600);
	//initializer les bandes de pixels
	pixels.begin();
	//definir les modes des pins
	pinMode(Relais, OUTPUT);
	pinMode(DetecteurHumidite, INPUT);
	pinMode(DetecteurNiveau, INPUT);
}

void loop() {
	verifierNiveauDeau();
	verifierHumidite();
	delay(500);
}

void verifierNiveauDeau(){
		pixels.clear();
		niveauDeau = analogRead(DetecteurNiveau);
		if (niveauDeau<=200){ 
			pixels.fill(ROUGE);
		}
		else if (niveauDeau>200 && niveauDeau<=400){ 
			pixels.fill(JAUNE);
		}
		else if (niveauDeau>400){ 
			pixels.fill(VERT);
		}
		pixels.show();
		delay(5000);
}


void verifierHumidite(){
	humidite = analogRead(DetecteurHumidite);

	//si le sol est sec, activer la pompe
	if (humidite < seuilSecheresse ){
		activerPompe();
	}
}

void activerPompe(){
	digitalWrite(Relais, HIGH);
	pixels.clear();
	pixels.fill(BLEU);
	pixels.show();
	delay(tempsDarrosage);
	digitalWrite(Relais, LOW);
}
```
</p>
</details>