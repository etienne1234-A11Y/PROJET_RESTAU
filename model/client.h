//
// Created by TRIPLE K on 09/12/2024.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>





    class client : public QWidget {
        Q_OBJECT

    public:
        // Constructeur explicite, reçoit le panneau parent
        explicit client(QWidget *parent = nullptr);

        // Méthode pour afficher l'image du serveur dans le panneau donné
        void creerclient(QWidget *parent);

    private:
        QLabel *label40;  // Label pour afficher l'image du serveur
    };










#endif //CLIENT_H
