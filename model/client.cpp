//
// Created by TRIPLE K on 09/12/2024.
//

#include "client.h"

client::client(QWidget *parent) : QWidget(parent) {

}

void client::creerclient(QWidget *leftPanel) {
    // Créer un QLabel pour afficher l'image du serveur
    QPixmap pixmap10("F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/clientdown.png");


    QLabel *label40 = new QLabel(leftPanel);  // Utiliser 'leftPanel' comme parent
    label40->setPixmap(pixmap10);
    label40->setScaledContents(true);

    // Positionner correctement l'image dans 'leftPanel'
    label40->setGeometry(100, 200, 30, 30);

    // S'assurer que le label est visible et au premier plan
    label40->raise();
    label40->show();
}

