#ifndef ENCODEUR_H
#define ENCODEUR_H

#include "AiEsp32RotaryEncoder.h"

#define ROTARY_ENCODER_A_PIN 33
#define ROTARY_ENCODER_B_PIN 35
#define ROTARY_ENCODER_BUTTON_PIN 32
#define ROTARY_ENCODER_VCC_PIN -1
#define ROTARY_ENCODER_STEPS 4

// On indique aux autres fichiers que cet objet existe dans le fichier .cpp
extern AiEsp32RotaryEncoder rotaryEncoder;

// Prototypes des fonctions
void setupEncodeur();
void rotary_loop();
void rotary_onButtonClick();

#endif