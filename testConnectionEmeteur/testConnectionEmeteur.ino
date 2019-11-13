/**
 * Exemple de code pour la bibliothèque VirtualWire – Télécommande DIY (émetteur)
 */
 
#include <VirtualWire.h>

/** Broches pour les boutons */
const byte PIN_BUTTON_A = 2;
const byte PIN_BUTTON_B = 3;
const byte PIN_BUTTON_C = 4;

/** Différents messages de commande */
const char* CMD_BUTTON_A = "BPA";
const char* CMD_BUTTON_B = "BPB";
const char* CMD_BUTTON_C = "BPC";

void setup() {
  Serial.begin(9600);
  
  /* Met les broches des boutons en entrées avec pull-up */
  pinMode(PIN_BUTTON_A, INPUT_PULLUP);
  pinMode(PIN_BUTTON_B, INPUT_PULLUP);
  pinMode(PIN_BUTTON_C, INPUT_PULLUP);

  // Initialisation de la bibliothèque VirtualWire
  // Vous pouvez changez les broches RX/TX/PTT avant vw_setup() si nécessaire
  vw_setup(1000);
  
  Serial.println("Go !"); 
}
 
void loop() {
  byte message[VW_MAX_MESSAGE_LEN]; 
  // N.B. La constante VW_MAX_MESSAGE_LEN est fournie par la lib VirtualWire
  
  /* Envoi la commande adéquate */
  if (digitalRead(PIN_BUTTON_A) == LOW ) {

    Serial.println("A");

    vw_send((byte*) CMD_BUTTON_A, strlen(CMD_BUTTON_A) + 1); // On envoie le message
    vw_wait_tx(); // On attend la fin de l'envoi

    Serial.println("envoyé A");
    
    delay(50); // Attend que le bouton soit relâché
    while(digitalRead(PIN_BUTTON_A) == LOW);
    delay(50);
    
  } else if (digitalRead(PIN_BUTTON_B) == LOW) {

    Serial.println("B");
    
    vw_send((byte*) CMD_BUTTON_B, strlen(CMD_BUTTON_B) + 1); // On envoie le message
    vw_wait_tx(); // On attend la fin de l'envoi
    
    delay(50); // Attend que le bouton soit relâché
    while(digitalRead(PIN_BUTTON_B) == LOW);
    delay(50);
  }

  else if (digitalRead(PIN_BUTTON_C) == LOW) {

    Serial.println("C");
    
    vw_send((byte*) CMD_BUTTON_C, strlen(CMD_BUTTON_C) + 1); // On envoie le message
    vw_wait_tx(); // On attend la fin de l'envoi
    
    delay(50); // Attend que le bouton soit relâché
    while(digitalRead(PIN_BUTTON_C) == LOW);
    delay(50);
  }
} 
