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
