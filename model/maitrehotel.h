//
// Created by TRIPLE K on 08/12/2024.
//

#ifndef MAITREHOTEL_H
#define MAITREHOTEL_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <random>


class maitrehotel : public QWidget {
    Q_OBJECT

public:
    // Constructeur explicite, reçoit le panneau parent
    explicit maitrehotel(QWidget *parent = nullptr);

    // Méthode pour afficher l'image du serveur dans le panneau donné
    void affichermaitrehotel(QWidget *parent);
    void assignertable(QWidget *parent);
    QLabel* getLabel() const { return label30; }  // Getter pour le QLabel du client
    int getX() const { return xPos; }             // Getter pour la position X
    int getY() const { return yPos; }             // Getter pour la position Y

private:
    QLabel *label30;  // Label pour afficher l'image du serveur
    int xPos;
    int yPos;
    QTimer *moveTimer;
};


#endif //MAITREHOTEL_H
