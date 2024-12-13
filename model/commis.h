//
// Created by TRIPLE K on 08/12/2024.
//

#ifndef COMMIS_H
#define COMMIS_H




#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include "human.h"

    class commis : public QWidget {
        Q_OBJECT

    public:
        // Constructeur explicite, reçoit le panneau parent
        explicit commis(QWidget *parent = nullptr);

        // Méthode pour afficher l'image du serveur dans le panneau donné
        void affichercommis(QWidget *parent);
        void deplacercommis(QWidget *parent);
        QLabel* getLabel() const { return label34; }  // Getter pour le QLabel du client
        int getX() const { return xPos; }             // Getter pour la position X
        int getY() const { return yPos; }             // Getter pour la position Y

    private:
        QLabel *label34;  // Label pour afficher l'image du
        int xPos;
        int yPos;
        QTimer *moveTimer;
    };






#endif //COMMIS_H
