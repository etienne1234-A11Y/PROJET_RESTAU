#include "chefrang.h"
#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include "human.h"
#include "TableManger.h"

chefrang::chefrang(QWidget *parent) : QWidget(parent) {
    label28 = nullptr;
}

void chefrang::afficherchefrang(QWidget *leftPanel) {
    // Ajouter deux chefs de rang au panneau de gauche
    QPixmap pixmap("F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/RangeChief.png");

    // Chef 1
    label28 = new QLabel(leftPanel);
    label28->setPixmap(pixmap);
    label28->setScaledContents(true);
    label28->setGeometry(200, 230, 15, 30);
    label28->raise();
    label28->show();

    // Chef 2
    QLabel *label29 = new QLabel(leftPanel);
    label29->setPixmap(pixmap);
    label29->setScaledContents(true);
    label29->setGeometry(200, 350, 15, 30);
    label29->raise();
    label29->show();
}

void chefrang::deplacerchefrangaccueil(QWidget *leftPanel) {
    if (label28) {
        human hum(leftPanel);

        QPoint startPos(200, 230);
        QPoint endPos(80, 200);  // Position d'accueil

        int duration = 4000;
        hum.moveOnce(label28, startPos, endPos, duration);
    }
}

void chefrang::deplacerchefrangclient(QWidget *leftPanel, int tableIndex) {
    if (label28) {
        human hum(leftPanel);
        TableManger manager;

        QPoint startPos(200, 230);
        QPoint endPos = hum.getTablePosition(tableIndex, manager);

        int duration = 4000;
        hum.moveOnce(label28, startPos, endPos, duration);
    }
}

void chefrang::repartposte(QWidget *leftPanel, int tableIndex) {
    if (label28) {
        human hum(leftPanel);
        TableManger manager;

        QPoint startPos = hum.getTablePosition(tableIndex, manager);
        QPoint endPos(200, 230);

        int duration = 4000;
        hum.moveOnce(label28, startPos, endPos, duration);
    }
}

void chefrang::prendcommande(QWidget *leftPanel, int tableIndex) {
    if (label28) {
        human hum(leftPanel);
        TableManger manager;

        QPoint startPos(200, 230);
        QPoint endPos = hum.getTablePosition(tableIndex, manager);

        int duration = 4000;
        hum.moveOnce(label28, startPos, endPos, duration);
    }
}

void chefrang::deplacerchefrangcuisine(QWidget *leftPanel, int tableIndex) {
    if (label28) {
        human hum(leftPanel);
        TableManger manager;

        QPoint startPos = hum.getTablePosition(tableIndex, manager);
        QPoint endPos(1100, 230);  // Position de la cuisine

        int duration = 4000;
        hum.moveOnce(label28, startPos, endPos, duration);
    }
}

void chefrang::findemission(QWidget *leftPanel) {
    if (label28) {
        human hum(leftPanel);

        QPoint startPos(1100, 230);
        QPoint endPos(200, 230);

        int duration = 4000;
        hum.moveOnce(label28, startPos, endPos, duration);
    }
}
void chefrang::poserplat(QWidget *leftPanel, int tableIndex) {
    if (label28) {
        human hum(leftPanel);
        TableManger manager;

        QPoint endPos = hum.getTablePosition(tableIndex, manager);
        QPoint startPos(200, 230);  // Position de la cuisine

        int duration = 4000;
        hum.moveOnce(label28, startPos, endPos, duration);
    }

}
void chefrang::position(QWidget *leftPanel, int tableIndex) {
    if (label28) {
        human hum(leftPanel);
        TableManger manager;

        QPoint startPos = hum.getTablePosition(tableIndex, manager);
        QPoint endPos(200, 230);  // Position de la cuisine

        int duration = 4000;
        hum.moveOnce(label28, startPos, endPos, duration);

    }
}
