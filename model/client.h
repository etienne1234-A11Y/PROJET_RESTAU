//
// Created by TRIPLE K on 09/12/2024.
//

#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include "human.h"
#include "TableManger.h"
#include <QTimer>

class client : public QWidget {
    Q_OBJECT

public:
    // Constructeur explicite, reçoit le panneau parent
    explicit client(QWidget *parent = nullptr);

    // Méthode pour créer l'image du client dans le panneau donné
    void creerclient(QWidget *parent);

    // Méthode pour déplacer le client vers une table spécifique
    void deplacerclient(QWidget *parent, int tableIndex);

    // Méthode pour déplacer le client vers l'accueil
    void deplacerclientaccueil(QWidget *parent);

    // Méthode pour déplacer le client vers une position de sortie
    void fin(QWidget *parent, int tableIndex);
    void rentrer(QWidget *parent);

private:
    QLabel *label50;  // Label unique pour afficher l'image du client
    QTimer *movementTimer;  // Timer pour gérer les animations si nécessaire
};

#endif // CLIENT_H
