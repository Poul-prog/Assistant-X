#include "encodeur.h"
#include "Arduino.h"

// Définition réelle de l'objet rotaryEncoder
AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(
    ROTARY_ENCODER_A_PIN, 
    ROTARY_ENCODER_B_PIN, 
    ROTARY_ENCODER_BUTTON_PIN, 
    ROTARY_ENCODER_VCC_PIN, 
    ROTARY_ENCODER_STEPS
);

// Fonction d'interruption (ISR) placée en RAM pour plus de rapidité
void IRAM_ATTR readEncoderISR() {
    rotaryEncoder.readEncoder_ISR();
}

// Fonction d'initialisation (à appeler dans le setup principal)
void setupEncodeur() {

    pinMode(ROTARY_ENCODER_BUTTON_PIN, INPUT_PULLDOWN); // Configure le bouton avec une résistance de tirage interne
    rotaryEncoder.begin();
    rotaryEncoder.setup(readEncoderISR);
    
    bool circleValues = false;
    rotaryEncoder.setBoundaries(0, 1000, circleValues); 
    rotaryEncoder.setAcceleration(250); 
}

// Gestion du clic sur le bouton
void rotary_onButtonClick() {
    /*static unsigned long lastTimePressed = 0; // Anti-rebond logiciel
    if (millis() - lastTimePressed < 500) {
        return;
    }
    lastTimePressed = millis();*/
    Serial.print("button pressed ");
    /*Serial.print(millis());
    Serial.println(" milliseconds after restart");*/
}

// Boucle de surveillance de l'encodeur (à appeler dans le loop principal)
void rotary_loop() {
    if (rotaryEncoder.encoderChanged()) {
        Serial.print("Value: ");
        Serial.println(rotaryEncoder.readEncoder());
    }
    if (rotaryEncoder.isEncoderButtonClicked()) {
        rotary_onButtonClick();
    }
}