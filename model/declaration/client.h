//
// Created by TRIPLE K on 09/12/2024.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QTimer>





    class client : public QWidget {
        Q_OBJECT

    public:
        // Constructeur explicite, reçoit le panneau parent
        explicit client(QWidget *parent = nullptr);

        // Méthode pour afficher l'image du serveur dans le panneau donné
        void creerclient(QWidget *parent);

        void deplacerVers();


    private:
        QLabel *label50;  // Label pour afficher l'image du serveur
    };










#endif //CLIENT_H
