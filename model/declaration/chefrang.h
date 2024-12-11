#ifndef CHEFRANG_H
#define CHEFRANG_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

class chefrang : public QWidget {
    Q_OBJECT

public:
    // Constructeur explicite, reçoit le panneau parent
    explicit chefrang(QWidget *parent = nullptr);

    // Méthode pour afficher l'image du serveur dans le panneau donné
    void afficherchefrang(QWidget *parent);

private:
    QLabel *label28;  // Label pour afficher l'image du serveur
};

#endif // CHEFRANG_H
