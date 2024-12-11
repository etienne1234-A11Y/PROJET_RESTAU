//
// Created by TRIPLE K on 08/12/2024.
//

#ifndef CUISINIER_H
#define CUISINIER_H




#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

    class cuisinier : public QWidget {
        Q_OBJECT

    public:
        // Constructeur explicite, reçoit le panneau parent
        explicit cuisinier(QWidget *parent = nullptr);

        // Méthode pour afficher l'image du serveur dans le panneau donné
        void affichercuisinier(QWidget *parent);

    private:
        QLabel *label33;  // Label pour afficher l'image du serveur
    };






#endif //CUISINIER_H
