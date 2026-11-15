#include <Arduino.h>
#include "encodeur.h"  // Module 1 : Encodeur rotatif
#include "affichage.h" // Module 2 : Écran OLED
#include "gestion_sd.h" // Module 3 : Carte SD

void setup() {
    Serial.begin(115200);
    setupAffichage();
    testscrolltext(); // Petit coucou sur l'écran

    // 2. Initialisation de l'encodeur
    setupEncodeur();

    // 3. Initialisation de la carte SD
    if (setupSD()) {
        // Optionnel : Tu peux afficher un message sur l'OLED si la SD est OK
        display.setCursor(10, 20);
        display.fillRect(8, 18, display.width()-40, display.height()-48, INVERSE);
        display.setTextColor(SSD1306_INVERSE);
        display.println("SD: OUAICHE");
        display.display();
    } else {
        display.setCursor(10, 20);
        display.setTextColor(SSD1306_INVERSE);
        display.println("SD: ERREUR");
        display.display();
    }

    delay(2000); 
}

void loop() {
    // Surveillance constante de l'encodeur
    rotary_loop();
    
    delay(50); 
}