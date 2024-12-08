//
// Created by TRIPLE K on 08/12/2024.
//

#include "cuisinier.h"

cuisinier::cuisinier(QWidget *parent) : QWidget(parent) {

}

void cuisinier::affichercuisinier(QWidget *rightPanel) {
    // Créer un QLabel pour afficher l'image du serveur
    QPixmap pixmap4("F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/MasterChefDown.png");


QLabel *label33 = new QLabel(rightPanel);  // Utiliser 'leftPanel' comme parent
label33->setPixmap(pixmap4);
label33->setScaledContents(true);

// Positionner correctement l'image dans 'leftPanel'
label33->setGeometry(350, 71, 15, 30);

// S'assurer que le label est visible et au premier plan
label33->raise();
label33->show();
}
