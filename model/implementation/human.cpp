//
// Created by TRIPLE K on 10/12/2024.
//

#include "../declaration/human.h"

#include <iostream>
#include <ostream>

human::human(QWidget *parent) : QWidget(parent) {
}

void human::move(int tableIndex,QWidget *leftPanel) {
    // QVector<QPoint> tablePositions = {
    //     {200, 20}, {415, 20}, {600, 120}, {800, 10},
    //     {280, 140}, {800, 530}, {500, 325}, {500, 500},
    //     {280, 400}, {800, 350}, {625, 20}
    // };
    //
    // if (tableIndex >= 0 && tableIndex < tablePositions.size()) {
    //     QPoint tablePos = tablePositions[tableIndex];
    //
    //     // Déplacer le client à la position de la table
    //     // Supposons que vous avez un QLabel représentant le client
    //     QPixmap pixmap10("F:/X3/programmation concurrente/depot/images/clientdown.png");
    //     QLabel *clientLabel = new QLabel(leftPanel);
    //     clientLabel->setPixmap(pixmap10);
    //     clientLabel->setGeometry(100, 200,15,30);  // Position initiale du client
    //
    //     // Déplacer le client à la position de la table
    //     clientLabel->move(tablePos);  // Déplacer le client à la position de la table
    //     clientLabel->show();
    // }
}
void human::deplacement(QWidget *leftPanel) {


}





