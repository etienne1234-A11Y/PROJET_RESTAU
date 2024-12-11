//
// Created by TRIPLE K on 08/12/2024.
//

#include "../declaration/commis.h"


commis::commis(QWidget *parent) : QWidget(parent) {

}

void commis::affichercommis(QWidget *rightPanel) {
    // Créer un QLabel pour afficher l'image du serveur
    QPixmap pixmap5("E:/Gpush/images/commiscuisinedown.png");


    QLabel *label34 = new QLabel(rightPanel);  // Utiliser 'leftPanel' comme parent
    label34->setPixmap(pixmap5);
    label34->setScaledContents(true);

    // Positionner correctement l'image dans 'leftPanel'
    label34->setGeometry(320, 100, 15, 30);

    // S'assurer que le label est visible et au premier plan
    label34->raise();
    label34->show();
}

