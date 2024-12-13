//
// Created by TRIPLE K on 08/12/2024.
//

#include "commis.h"


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
    human *hum = new human(rightPanel);

    // Position de départ (position initiale du cuisinier)
    QPoint startPos(320, 100);

    // Position de destination (par exemple, vers une autre partie du panel)
    QPoint endPos(350, 100);  // Exemple de destination

    // Durée du mouvement (en millisecondes)
    int duration = 4000;

    // Déplacer le cuisinier avec l'animation et l'effet de marche
    hum->moveLoop(label34, startPos, endPos, duration);
}


