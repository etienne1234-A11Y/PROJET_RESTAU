//
// Created by TRIPLE K on 08/12/2024.
//

#ifndef MAITREHOTEL_H
#define MAITREHOTEL_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>


class maitrehotel : public QWidget {
    Q_OBJECT

public:
    // Constructeur explicite, reçoit le panneau parent
    explicit maitrehotel(QWidget *parent = nullptr);

    // Méthode pour afficher l'image du serveur dans le panneau donné
    void affichermaitrehotel(QWidget *parent);

private:
    QLabel *label30;  // Label pour afficher l'image du serveur
};


#endif //MAITREHOTEL_H
