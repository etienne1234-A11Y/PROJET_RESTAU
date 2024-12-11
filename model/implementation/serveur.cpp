//
// Created by TRIPLE K on 08/12/2024.
//

#include "../declaration/serveur.h"

serveur::serveur(QWidget *parent) : QWidget(parent) {

}

void serveur::afficherserveur(QWidget *leftPanel) {
    // Créer un QLabel pour afficher l'image du serveur
    QPixmap pixmap3("E:/Gpush/images/serveurmovingdown.png");

    QLabel *label31 = new QLabel(leftPanel);  // Utiliser 'leftPanel' comme parent
    label31->setPixmap(pixmap3);
    label31->setScaledContents(true);

    // Positionner correctement l'image dans 'leftPanel'
    label31->setGeometry(400, 20, 15, 30);

    // S'assurer que le label est visible et au premier plan
    label31->raise();
    label31->show();

    QPixmap pixmap4("F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/serveurmovingdown.png");

    QLabel *label32 = new QLabel(leftPanel);  // Utiliser 'leftPanel' comme parent
    label32->setPixmap(pixmap4);
    label32->setScaledContents(true);

    // Positionner correctement l'image dans 'leftPanel'
    label32->setGeometry(450, 450, 15, 30);

    // S'assurer que le label est visible et au premier plan
    label32->raise();
    label32->show();
}