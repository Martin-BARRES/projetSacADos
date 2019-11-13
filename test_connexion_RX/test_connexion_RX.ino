/**
 * Exemple de code pour la bibliothèque VirtualWire – Télécommande DIY (récepteur)
 */

#include <VirtualWire.h>

/** Broches pour les LEDs */
const byte PIN_LED_A = 2;
const byte PIN_LED_B = 3;
const byte PIN_LED_C = 4;

/** Différents messages de commande */
const char* CMD_BUTTON_A = "BPA";
const char* CMD_BUTTON_B = "BPB";
const char* CMD_BUTTON_C = "BPC";

void setup() {
  Serial.begin(9600);
  
  /* Met les broches des LEDs en sortie et à LOW */
  pinMode(PIN_LED_A, OUTPUT);
  digitalWrite(PIN_LED_A, LOW);
  pinMode(PIN_LED_B, OUTPUT);
  digitalWrite(PIN_LED_B, LOW);
  pinMode(PIN_LED_C, OUTPUT);
  digitalWrite(PIN_LED_C, LOW);
  
  // Initialisation de la bibliothèque VirtualWire
  // Vous pouvez changez les broches RX/TX/PTT avant vw_setup() si nécessaire
  vw_setup(1000);
  vw_rx_start(); // On peut maintenant recevoir des messages

  Serial.println("Go !"); 
}

void loop() {
  byte message[VW_MAX_MESSAGE_LEN];
  byte taille_message = VW_MAX_MESSAGE_LEN;
  // N.B. La constante VW_MAX_MESSAGE_LEN est fournie par la lib VirtualWire

  /* 
   La variable "taille_message" doit impérativement être remise à 
   la taille du buffer avant de pouvoir recevoir un message. 
   Le plus simple est d'utiliser une variable locale pour ne pas
   avoir à réassigner la valeur à chaque début de loop().
   */

  // On attend de recevoir un message
  vw_wait_rx();

  if (vw_get_message(message, &taille_message)) {
    // On copie le message, qu'il soit corrompu ou non

    if (strcmp((char*) message, CMD_BUTTON_A) == 0) {
      //digitalWrite(PIN_LED_A, !digitalRead(PIN_LED_A));
      Serial.println("TOGGLE LED A");
      digitalWrite(PIN_LED_A,HIGH);
      delay(500);
      digitalWrite(PIN_LED_A,LOW);
      delay(500);
      digitalWrite(PIN_LED_A,HIGH);
      delay(500);
      digitalWrite(PIN_LED_A,LOW);
      delay(500);
      digitalWrite(PIN_LED_A,HIGH);
      delay(500);
      digitalWrite(PIN_LED_A,LOW);
      delay(500);
      digitalWrite(PIN_LED_A,HIGH);
      delay(500);
      digitalWrite(PIN_LED_A,LOW);
      delay(500);
      digitalWrite(PIN_LED_A,HIGH);
      delay(500);
      digitalWrite(PIN_LED_A,LOW);
      delay(500);
      digitalWrite(PIN_LED_A,HIGH);
      delay(500);
      digitalWrite(PIN_LED_A,LOW);
      delay(500);
      digitalWrite(PIN_LED_A,HIGH);
      delay(500);
      digitalWrite(PIN_LED_A,LOW);
      delay(500);
      
    } else if (strcmp((char*) message, CMD_BUTTON_B) == 0) {
      //digitalWrite(PIN_LED_B, !digitalRead(PIN_LED_B));
      Serial.println("TOGGLE LED B");
      digitalWrite(PIN_LED_B,HIGH);
      delay(500);
      digitalWrite(PIN_LED_B,LOW);
      delay(500);
      digitalWrite(PIN_LED_B,HIGH);
      delay(500);
      digitalWrite(PIN_LED_B,LOW);
      delay(500);
      digitalWrite(PIN_LED_B,HIGH);
      delay(500);
      digitalWrite(PIN_LED_B,LOW);
      delay(500);
      digitalWrite(PIN_LED_B,HIGH);
      delay(500);
      digitalWrite(PIN_LED_B,LOW);
      delay(500);
      digitalWrite(PIN_LED_B,HIGH);
      delay(500);
      digitalWrite(PIN_LED_B,LOW);
      delay(500);
      digitalWrite(PIN_LED_B,HIGH);
      delay(500);
      digitalWrite(PIN_LED_B,LOW);
      delay(500);
      digitalWrite(PIN_LED_B,HIGH);
      delay(500);
      digitalWrite(PIN_LED_B,LOW);
      delay(500);
    } 
    else if (strcmp((char*) message, CMD_BUTTON_C) == 0) {
      digitalWrite(PIN_LED_C, !digitalRead(PIN_LED_C));
      Serial.println("TOGGLE LED C");
    }
  }
}
