#ifndef CHEFRANG_H
#define CHEFRANG_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include "human.h"

class chefrang : public QWidget {
    Q_OBJECT

public:
    // Constructeur explicite, reçoit le panneau parent
    explicit chefrang(QWidget *parent = nullptr);

    // Méthode pour afficher l'image du serveur dans le panneau donné
    void afficherchefrang(QWidget *parent);
    void deplacerchefrangaccueil(QWidget *parent);
    void deplacerchefrangcuisine(QWidget *parent,int tableIndex);
    void deplacerchefrangclient(QWidget *parent,int tableIndex);
    void repartposte(QWidget *parent,int tableIndex);
    void prendcommande(QWidget *parent,int tableIndex);
    void findemission(QWidget *parent);
    void position(QWidget *parent,int tableIndex);
    void poserplat(QWidget *parent,int tableIndex);
    QLabel* getLabel() const { return label28; }  // Getter pour le QLabel du client
    int getX() const { return xPos; }             // Getter pour la position X
    int getY() const { return yPos; }             // Getter pour la position Y

private:
    QLabel *label28;  // Label pour afficher l'image du serveur
    QLabel *label29;
    QLabel *labe100;
    int xPos;
    int yPos;
    QTimer *moveTimer;
};

#endif // CHEFRANG_H
