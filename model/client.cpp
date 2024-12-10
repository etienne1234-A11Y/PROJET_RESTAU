//
// Created by TRIPLE K on 09/12/2024.
//

#include "client.h"

client::client(QWidget *parent) : QWidget(parent) {

}

void client::creerclient(QWidget *leftPanel) {
    // Créer un QLabel pour afficher l'image du serveur
    QPixmap pixmap10("F:/X3/programmation concurrente/depot/images/clientdown.png");


    QLabel *label50 = new QLabel(leftPanel);  // Utiliser 'leftPanel' comme parent
    label50->setPixmap(pixmap10);
    label50->setScaledContents(true);

    // Positionner correctement l'image dans 'leftPanel'
    label50->setGeometry(100, 200, 15, 30);

    // S'assurer que le label est visible et au premier plan
    label50->raise();
    label50->show();

}

