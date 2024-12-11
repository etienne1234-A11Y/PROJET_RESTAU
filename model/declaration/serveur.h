//
// Created by TRIPLE K on 08/12/2024.
//

#ifndef SERVEUR_H
#define SERVEUR_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

class serveur : public QWidget {
    Q_OBJECT

public:
    // Constructeur explicite, reçoit le panneau parent
    explicit serveur(QWidget *parent = nullptr);

    // Méthode pour afficher l'image du serveur dans le panneau donné
    void afficherserveur(QWidget *parent);

private:
    QLabel *label31;  // Label pour afficher l'image du serveur
};



#endif //SERVEUR_H
