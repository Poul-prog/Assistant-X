#include "gestion_sd.h"
#include "Arduino.h"

// Fonction d'initialisation de la carte SD
bool setupSD() {
    Serial.println("Initialisation de la carte SD...");

    // On tente de démarrer la carte SD avec sa broche CS
    if (!SD.begin(SD_CS_PIN)) {
        Serial.println("Échec du montage de la carte SD !");
        return false;
    }

    // Vérification du type de carte (optionnel mais utile pour le debug)
    uint8_t cardType = SD.cardType();
    if (cardType == CARD_NONE) {
        Serial.println("Aucune carte SD trouvée.");
        return false;
    }

    Serial.println("Carte SD initialisée avec succès.");
    return true;
}