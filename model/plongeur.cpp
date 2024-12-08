//
// Created by TRIPLE K on 08/12/2024.
//

#include "plongeur.h"





plongeur::plongeur(QWidget *parent) : QWidget(parent) {

}

void plongeur::afficherplongeur(QWidget *rightPanel) {
    // Créer un QLabel pour afficher l'image du serveur
    QPixmap pixmap5("F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/plongeurmovingdown.png");


    QLabel *label35 = new QLabel(rightPanel);  // Utiliser 'leftPanel' comme parent
    label35->setPixmap(pixmap5);
    label35->setScaledContents(true);

    // Positionner correctement l'image dans 'leftPanel'
    label35->setGeometry(385, 450, 15, 30);

    // S'assurer que le label est visible et au premier plan
    label35->raise();
    label35->show();
}

