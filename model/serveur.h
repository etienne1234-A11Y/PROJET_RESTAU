//
// Created by TRIPLE K on 08/12/2024.
//

#ifndef SERVEUR_H
#define SERVEUR_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include "human.h"

class serveur : public QWidget {
    Q_OBJECT

public:
    // Constructeur explicite, reçoit le panneau parent
    explicit serveur(QWidget *parent = nullptr);

    // Méthode pour afficher l'image du serveur dans le panneau donné
    void afficherserveur(QWidget *parent);
    void deplacerserveurcuisine(QWidget *parent);
    void deplacerserveurclient(QWidget *parent,int tableIndex);
    void finserveur(QWidget *parent,int tableIndex);
    void debarasser(QWidget *parent,int tableIndex);
    void remetcouvert(QWidget *parent,int tableIndex);
    void repositionner(QWidget *parent);
    QLabel* getLabel() const { return label31; }  // Getter pour le QLabel du client
    int getX() const { return xPos; }             // Getter pour la position X
    int getY() const { return yPos; }             // Getter pour la position Y

private:
    QLabel *label31;  // Label pour afficher l'image du serveur
    QLabel *label32;
    int xPos;
    int yPos;
    QTimer *moveTimer;
};



#endif //SERVEUR_H
