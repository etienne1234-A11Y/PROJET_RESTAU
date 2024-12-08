//
// Created by TRIPLE K on 08/12/2024.
//

#ifndef PLONGEUR_H
#define PLONGEUR_H




#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

class plongeur: public QWidget {
    Q_OBJECT

public:
    // Constructeur explicite, reçoit le panneau parent
    explicit plongeur(QWidget *parent = nullptr);

    // Méthode pour afficher l'image du serveur dans le panneau donné
    void afficherplongeur(QWidget *parent);

private:
    QLabel *label35;  // Label pour afficher l'image du serveur
};






#endif //PLONGEUR_H
