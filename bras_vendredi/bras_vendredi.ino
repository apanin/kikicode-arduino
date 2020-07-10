#include <Servo.h>
#define bouton1 A0
#define bouton2 A1
#define bouton3 A2

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;

bool dir1 = true;
bool dir2 = true;
bool dir3 = true;

Servo moteur1;
Servo moteur2;
Servo moteur3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bouton1, INPUT);
  pinMode(bouton2, INPUT);
  pinMode(bouton3, INPUT);

moteur1.attach(9);
moteur1.write(pos1);

moteur2.attach(8);
moteur2.write(pos2);

moteur3.attach(7);
moteur3.write(pos3);

}

void loop() {
  // put your main code here, to run repeatedly:
lireBouton(1);
delay(500);
}

void lireBouton(int bouton){
  if (bouton == 1 && analogRead(bouton1) > 1000){
  Serial.println("bouton 1 pese");
  bougermoteur(1);
  }
  
  if (bouton == 2 && analogRead(bouton2) > 1000){
    Serial.println("bouton 2 pese");
    bougermoteur(2);
  }
  if (bouton == 3 && analogRead(bouton3) > 1000){
     Serial.println("bouton 3 pese");
     bougermoteur(3);
  }
  }

  void bougermoteur(int moteur){
    if (moteur == 1){
      balayage1();
      moteur1.write(pos1);
   
    }
  if (moteur == 2){
    //balayage(pos1, dir2);
    moteur2.write(pos2);
  
  }
  if (moteur == 3){
    //balayage(pos3, dir3);
    moteur3.write(pos3);
  }
  }
  
void balayage1(){
  if (pos1 == 0 || pos1 == 180 ){
    dir1 = !dir1;
  }
  if (dir1 == true){
    pos1 -=5;
  }
  else pos1 +=5;
}
