/*========= Arrosage-Servo-Distrib V1 - 23/06/20 ========= */
/*================== marcdesc.com ================= */

#include <Servo.h> 
Servo myservo;  // créer un objet appelé myservo à partir du moule 

// CONSTANTES&VARIABLES
// =========
// Initialisation des constantes :
const int pompePin = 12;   // Broche de la pompe


//Test constant pour pauses longues
const unsigned long SECOND = 1000;
const unsigned long HOUR = 3600*SECOND;
const unsigned long Day = 24*HOUR;


// Initialisation des variables:
int tempsArrosage=5;           // temps necessaire a l'arrosage en secondes: de base 40s tt les 3jours
/*ici on a une pompe péristaltique 6V precise mais lente il faut 1min20 à 5V pour pomper Xml */



int pos = 0;    // variable pour stocker la position courante du servomoteur

/*ici arrossage deux fois par semaine = une variable 3jours et une variable 4jours 
int tI1= 3 * 864; //*100000;          // temps de mise en pause 3jours
int tI2= 4 * 864; //*100000;          // temps de mise en pause 4jours
*/

// SETUP
// =========
// le code dans cette fonction est exécuté une fois au début

void setup() {
  // initialiser pin pompePin comme sortie
  pinMode(pompePin, OUTPUT);
  myservo.attach(9);  // attacher notre objet myservo au servomoteur branché sur la broche 9 
}


// BOUCLE
// =========


void loop() {
  
  //PLante 1
  myservo.write(pos);              // aller à la position stocké dans 'pos'
  //delay(10*SECOND);   //for testing
  digitalWrite(pompePin, HIGH);   // allumer la pompe
  delay(tempsArrosage*SECOND);    // temps de l'arrosage
  digitalWrite(pompePin, LOW);    // eteindre la pompe
  delay(1000);                     //pause goute

  //PLante2
    for(pos = 0; pos < 45; pos += 1)  // aller de 0° à 45°
  {                                  // une étape à la fois
    myservo.write(pos);              // aller à la position stocké dans 'pos'
    delay(15);                       // attendre 15ms que le servomoteur se rende à 'pos'    
  } 
   digitalWrite(pompePin, HIGH);   // allumer la pompe
    delay(tempsArrosage*SECOND);    // temps de l'arrosage
    digitalWrite(pompePin, LOW);    // eteindre la pompe
    delay(1000);                     //pause goute
     
    //PLante3
    for(pos = 45; pos < 90; pos += 1)  // aller de 45° à 90°
  {                                  // une étape à la fois
    myservo.write(pos);              // aller à la position stocké dans 'pos'
    delay(15);                       // attendre 15ms que le servomoteur se rende à 'pos'    
  } 
    digitalWrite(pompePin, HIGH);   // allumer la pompe
    delay(tempsArrosage*SECOND);           // temps de l'arrosage
    digitalWrite(pompePin, LOW);    // eteindre la pompe
    delay(1000);                     //pause goute
    
      //PLante4
    for(pos = 90; pos < 135; pos += 1)  // aller de 90° à 135°
  {                                  // une étape à la fois
    myservo.write(pos);              // aller à la position stocké dans 'pos'
    delay(15);                       // attendre 15ms que le servomoteur se rende à 'pos'
     } 
    digitalWrite(pompePin, HIGH);   // allumer la pompe
    delay(tempsArrosage*SECOND);           // temps de l'arrosage
    digitalWrite(pompePin, LOW);    // eteindre la pompe
    delay(1000);                     //pause goute
        
        //PLante5
    for(pos = 135; pos < 180; pos += 1)  // aller de 135° à 179°
  {                                  // une étape à la fois
    myservo.write(pos);              // aller à la position stocké dans 'pos'
    delay(15);                       // attendre 15ms que le servomoteur se rende à 'pos'
    } 
    digitalWrite(pompePin, HIGH);   // allumer la pompe
    delay(tempsArrosage*SECOND);           // temps de l'arrosage
    digitalWrite(pompePin, LOW);    // eteindre la pompe
    delay(1000);                     //pause goute

  // Retour départ
  for(pos = 180; pos>=0; pos-=1)     /// aller de 180° à 0°
  {                                
    myservo.write(pos);              // aller à la position stocké dans 'pos'
    delay(15);                       // attendre 15ms que le servomoteur se rende à 'pos'
  } 

  delay(12*HOUR);                    // attendre 12 h
}
