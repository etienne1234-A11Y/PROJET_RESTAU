#include "chefrang.h"
#include <QLabel>
#include <QPixmap>
#include <QWidget>

chefrang::chefrang(QWidget *parent) : QWidget(parent) {

}

void chefrang::afficherchefrang(QWidget *leftPanel) {
    // Créer un QLabel pour afficher l'image du serveur
    QPixmap pixmap("F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/RangeChief.png");

    QLabel *label28 = new QLabel(leftPanel);  // Utiliser 'leftPanel' comme parent
    label28->setPixmap(pixmap);
    label28->setScaledContents(true);

    // Positionner correctement l'image dans 'leftPanel'
    label28->setGeometry(200, 230, 15, 30);

    // S'assurer que le label est visible et au premier plan
    label28->raise();
    label28->show();

    QPixmap pixmap1("F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/RangeChief.png");

    QLabel *label29 = new QLabel(leftPanel);  // Utiliser 'leftPanel' comme parent
    label29->setPixmap(pixmap1);
    label29->setScaledContents(true);

    // Positionner correctement l'image dans 'leftPanel'
    label29->setGeometry(200, 350, 15, 30);

    // S'assurer que le label est visible et au premier plan
    label29->raise();
    label29->show();

}
