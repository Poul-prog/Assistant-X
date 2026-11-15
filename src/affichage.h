#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <Adafruit_SSD1306.h>

// Définition des dimensions de l'écran
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET -1 

// On indique aux autres fichiers que l'objet "display" existe dans le fichier .cpp
extern Adafruit_SSD1306 display;

// Prototypes des fonctions
void setupAffichage();
void testscrolltext();

#endif