#include "client.h"
#include "human.h" // Ajout de l'inclusion pour la classe human

client::client(QWidget *parent) : QWidget(parent), label50(nullptr), movementTimer(new QTimer(this)) {
    // Initialisation si nécessaire
}

void client::creerclient(QWidget *leftPanel) {
    // Créer un QLabel pour afficher l'image du client uniquement si label50 n'existe pas
    if (!label50) {
        label50 = new QLabel(leftPanel);
        QPixmap pixmap10("E:/Gpush/images/clientdown.png");
        label50->setPixmap(pixmap10);
        label50->setScaledContents(true);
        label50->setGeometry(60, 280, 15, 30); // Position initiale
        label50->raise();
        label50->show();
    }
}

void client::deplacerclientaccueil(QWidget *leftPanel) {
    // S'assurer que le client est créé
    if (!label50) {
        creerclient(leftPanel);
    }

    // Créer un objet human pour gérer les mouvements
    human *hum = new human(leftPanel);

    // Position de départ (position actuelle du label)
    QPoint startPos = label50->pos();

    // Position de destination (par exemple, accueil)
    QPoint endPos(60, 200);

    // Durée du mouvement
    int duration = 4000;

    // Déplacer le client avec une animation
    hum->moveOnce(label50, startPos, endPos, duration);
}

void client::deplacerclient(QWidget *leftPanel, int tableIndex) {
    // S'assurer que le client est créé
    if (!label50) {
        creerclient(leftPanel);
    }

    // Créer un objet human pour gérer les mouvements
    human *hum = new human(leftPanel);
    TableManger manager;

    // Position de départ (position actuelle du label)
    QPoint startPos = label50->pos();

    // Récupération de la position de la table cible en fonction de l'index
    QPoint endPos = hum->getTablePosition(tableIndex, manager);

    // Durée du mouvement
    int duration = 4000;

    // Déplacer le client avec une animation
    hum->moveOnce(label50, startPos, endPos, duration);
}

void client::fin(QWidget *leftPanel, int tableIndex) {
    // S'assurer que le client est créé
    if (!label50) {
        creerclient(leftPanel);
    }

    // Créer un objet human pour gérer les mouvements
    human *hum = new human(leftPanel);
    TableManger manager;

    // Position de départ (position actuelle du label)
    QPoint startPos = label50->pos();

    // Position de destination (par exemple, hors écran)
    QPoint endPos(60, 200);

    // Durée du mouvement
    int duration = 4000;

    // Déplacer le client avec une animation
    hum->moveOnce(label50, startPos, endPos, duration);
}
void client::rentrer(QWidget *leftPanel) {
    if (!label50) {
        creerclient(leftPanel);
    }

    // Créer un objet human pour gérer les mouvements
    human *hum = new human(leftPanel);


    // Position de départ (position actuelle du label)
    QPoint endPos(0,300);

    // Position de destination (par exemple, hors écran)
    QPoint startPos(60, 200);

    // Durée du mouvement
    int duration = 4000;

    // Déplacer le client avec une animation
    hum->moveOnce(label50, startPos, endPos, duration);
}
