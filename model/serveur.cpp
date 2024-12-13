//
// Created by TRIPLE K on 08/12/2024.
//

#include "serveur.h"
#include "human.h"
#include "TableManger.h"

serveur::serveur(QWidget *parent) : QWidget(parent) {
    label31 = nullptr;
}

void serveur::afficherserveur(QWidget *leftPanel) {
    // Charger l'image du serveur
    QPixmap pixmap3("E:/Gpush/images/serveurmovingdown.png");

    // Serveur 1
    label31 = new QLabel(leftPanel);  // Mémoriser ce label comme membre
    label31->setPixmap(pixmap3);
    label31->setScaledContents(true);
    label31->setGeometry(400, 20, 15, 30);  // Position initiale
    label31->raise();
    label31->show();

    // Serveur 2
    QLabel *label32 = new QLabel(leftPanel);
    label32->setPixmap(pixmap3);
    label32->setScaledContents(true);
    label32->setGeometry(450, 450, 15, 30);  // Position initiale
    label32->raise();
    label32->show();
}

void serveur::deplacerserveurcuisine(QWidget *leftPanel) {
    if (label31) {
        human hum(leftPanel);

        QPoint startPos(400, 20);       // Position actuelle
        QPoint endPos(1100, 20);       // Destination : cuisine
        int duration = 4000;           // Durée de déplacement

        hum.moveOnce(label31, startPos, endPos, duration);
    }
}

void serveur::deplacerserveurclient(QWidget *leftPanel, int tableIndex) {
    if (label31) {
        human hum(leftPanel);
        TableManger manager;

        QPoint startPos(1100, 20);                     // Position actuelle : cuisine
        QPoint endPos = hum.getTablePosition(tableIndex, manager);  // Position de la table
        int duration = 4000;                           // Durée de déplacement

        hum.moveOnce(label31, startPos, endPos, duration);
    }
}

void serveur::finserveur(QWidget *leftPanel, int tableIndex) {
    if (label31) {
        human hum(leftPanel);
        TableManger manager;

        QPoint startPos = hum.getTablePosition(tableIndex, manager);  // Position actuelle : table
        QPoint endPos(400, 20);                                       // Destination initiale
        int duration = 4000;                                          // Durée de déplacement

        hum.moveOnce(label31, startPos, endPos, duration);
    }
}
void serveur::debarasser(QWidget *leftPanel, int tableIndex) {
    if (label31) {
        human hum(leftPanel);
        TableManger manager;

        QPoint endPos = hum.getTablePosition(tableIndex, manager);  // Position actuelle : table
        QPoint startPos(400, 20);                                       // Destination initiale
        int duration = 4000;                                          // Durée de déplacement

        hum.moveOnce(label31, startPos, endPos, duration);
    }
}
    void serveur::remetcouvert(QWidget *leftPanel, int tableIndex) {
        if (label31) {
            human hum(leftPanel);
            TableManger manager;

            QPoint startPos = hum.getTablePosition(tableIndex, manager);  // Position actuelle : table
            QPoint endPos(1100, 20);                                       // Destination initiale
            int duration = 4000;                                          // Durée de déplacement

            hum.moveOnce(label31, startPos, endPos, duration);

    }

}
void serveur::repositionner(QWidget *leftPanel) {
    if (label31) {
        human hum(leftPanel);

        QPoint endPos (400,20);  // Position actuelle : table
        QPoint startPos(1100, 20);                                       // Destination initiale
        int duration = 4000;                                          // Durée de déplacement

        hum.moveOnce(label31, startPos, endPos, duration);

    }
}


