//
// Created by TRIPLE K on 08/12/2024.
//

#include "maitrehotel.h"
#include <QLabel>
#include <QPixmap>
#include <QWidget>

maitrehotel::maitrehotel(QWidget *parent) : QWidget(parent) {

}

void maitrehotel::affichermaitrehotel(QWidget *leftPanel) {
    // Créer un QLabel pour afficher l'image du serveur
    QPixmap pixmap2("F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/maitrehoteldown.png");

    QLabel *label30 = new QLabel(leftPanel);  // Utiliser 'leftPanel' comme parent
    label30->setPixmap(pixmap2);
    label30->setScaledContents(true);

    // Positionner correctement l'image dans 'leftPanel'
    label30->setGeometry(130, 80, 15, 30);

    // S'assurer que le label est visible et au premier plan
    label30->raise();
    label30->show();
}
