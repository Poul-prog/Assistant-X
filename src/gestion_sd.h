#ifndef GESTION_SD_H
#define GESTION_SD_H

#include "FS.h"
#include "SD.h"
#include <SPI.h>

// Définition de la broche CS (Chip Select) pour la carte SD sur l'ESP32
// Note : Modifie le numéro 5 si ton lecteur SD utilise une autre broche (ex: 13, 4, etc.)
#define SD_CS_PIN 5

// Prototype de la fonction d'initialisation
bool setupSD();

#endif