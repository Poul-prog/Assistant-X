#include "affichage.h"
#include <Wire.h>

// Définition réelle de l'objet display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Fonction d'initialisation sécurisée de l'écran
void setupAffichage() {
    // Petit délai pour laisser l'écran s'allumer électriquement
    delay(250); 

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        // Si l'allocation échoue, on attend 1 seconde et on réessaie
        delay(1000);
        if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
            for(;;); // Bloque ici si l'écran est vraiment débranché/mal câblé
        }
    }

    display.clearDisplay();
    display.display();
}

// Ta fonction personnalisée pour afficher le texte
void testscrolltext() {
    display.clearDisplay();
    display.setTextSize(1); 
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("Coucou coquinouille");
    display.display();      
}