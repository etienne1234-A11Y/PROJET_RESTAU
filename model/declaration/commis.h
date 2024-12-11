//
// Created by TRIPLE K on 08/12/2024.
//

#ifndef COMMIS_H
#define COMMIS_H




#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

    class commis : public QWidget {
        Q_OBJECT

    public:
        // Constructeur explicite, reçoit le panneau parent
        explicit commis(QWidget *parent = nullptr);

        // Méthode pour afficher l'image du serveur dans le panneau donné
        void affichercommis(QWidget *parent);

    private:
        QLabel *label34;  // Label pour afficher l'image du serveur
    };






#endif //COMMIS_H
