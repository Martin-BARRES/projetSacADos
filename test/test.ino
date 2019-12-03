
#include <VirtualWire.h>

/** Broches pour les LEDs */
const byte PIN_LED_A = 2;
const byte PIN_LED_B = 3;
const byte PIN_LED_C = 4;

/** booléen pour contrôller les clignotants */
bool RIGHT = false;
bool LEFT = false;

/** Différents messages de commande */
const char* CMD_BUTTON_A = "BPA";
const char* CMD_BUTTON_B = "BPB";
const char* CMD_BUTTON_C = "BPC";

void setup() {
  Serial.begin(9600);
  
  /* Met les broches des LEDs en sortie et à LOW */
  pinMode(PIN_LED_A, OUTPUT);
  digitalWrite(PIN_LED_A, HIGH);
  pinMode(PIN_LED_B, OUTPUT);
  digitalWrite(PIN_LED_B, HIGH);
  pinMode(PIN_LED_C, OUTPUT);
  digitalWrite(PIN_LED_C, HIGH);
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  
  // Initialisation de la bibliothèque VirtualWire
  
  vw_setup(500);
  vw_rx_start(); // On peut maintenant recevoir des messages

  Serial.println("Go !"); 
}

void loop() {
  byte message[VW_MAX_MESSAGE_LEN];
  byte taille_message = VW_MAX_MESSAGE_LEN;
  // N.B. La constante VW_MAX_MESSAGE_LEN est fournie par la lib VirtualWire

 

  // On attend de recevoir un message

  if (vw_get_message(message, &taille_message)) {
    // On copie le message, qu'il soit corrompu ou non

    if (strcmp((char*) message, CMD_BUTTON_A) == 0) {
      //digitalWrite(PIN_LED_A, !digitalRead(PIN_LED_A));
      RIGHT = !RIGHT;
      LEFT = LEFT;
      Serial.println("TOGGLE LED A");
      
    } 
    else if (strcmp((char*) message, CMD_BUTTON_B) == 0) {
      //digitalWrite(PIN_LED_B, !digitalRead(PIN_LED_B));
      LEFT = !LEFT;
      Serial.println("TOGGLE LED B");
    } 
    else if (strcmp((char*) message, CMD_BUTTON_C) == 0) {
      digitalWrite(PIN_LED_C, !digitalRead(PIN_LED_C));
      Serial.println("TOGGLE LED C");
    }
  }

  if (RIGHT == true ){
      digitalWrite(PIN_LED_A,LOW);
    }
  if (LEFT == true){
      digitalWrite(PIN_LED_B,LOW);
    } 

  delay(500);
  digitalWrite(PIN_LED_A,HIGH);
  digitalWrite(PIN_LED_B,HIGH);
  delay(500);
  
}


void clignote(bool R, bool L) {
    if (R == true && L == false){
      digitalWrite(PIN_LED_A,HIGH);
      delay(500);
      digitalWrite(PIN_LED_A,LOW);
      delay(500);
    }

    else if (RIGHT == false && LEFT == true) {
      digitalWrite(PIN_LED_B,HIGH);
      delay(500);
      digitalWrite(PIN_LED_B,LOW);
      delay(500);
    }

    else if (RIGHT == true && LEFT == false) {
      digitalWrite(PIN_LED_A,HIGH);
      digitalWrite(PIN_LED_B,HIGH);
      delay(500);
      digitalWrite(PIN_LED_A,LOW);
      digitalWrite(PIN_LED_B,LOW);
      delay(500);
    }
  }
