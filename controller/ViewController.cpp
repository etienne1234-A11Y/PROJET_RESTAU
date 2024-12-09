//
// Created by mmaya on 05/12/2024.
//

#include "ViewController.h"



Controller::Controller(Model *model, View *view , QObject *parent)
    : QObject(parent), view(view) , model(model) {

    //Connect View to Model
    connect(view->getStartButton(), &QPushButton::clicked, this, &Controller::onStartButtonClicked);
    connect(view->getPauseButton(), &QPushButton::clicked, this, &Controller::onPauseButtonClicked);
    connect(view->getTimeSpinBox(), QOverload<int>::of(&QSpinBox::valueChanged), this, &Controller::onTimeSpinBoxChanged);

    // Update View when Model changes
    connect(model, &Model::timeUpdated, view, &View::updateTimeDisplay);
}

void Controller::onStartButtonClicked() {
    model->setTime(model->getTime() + 1); // Simulate time increment
}

void Controller::onPauseButtonClicked() {
    // Logic for pausing
}

void Controller::onTimeSpinBoxChanged(int time) {
    model->setTime(time);
}
void Controller::collectedonnees() {
    QString dbName = "resto";
    QString user = "root";
    QString password = "K3m@j0uK3rry";
    QString host = "127.0.0.1";
    int port = 3306;


    Database db(dbName, user, password , host, port);
}
void Controller::affichergens() {
    // Créez les personnages
    chefrang *chef = new chefrang(view);
    maitrehotel *maitre = new maitrehotel(view);
    serveur *ser = new serveur(view);
    commis *com = new commis(view);
    cuisinier *cuis = new cuisinier(view);
    plongeur *plong = new plongeur(view);
    client *cli = new client(view);

    // Ajoutez les personnages dans le leftPanel et rightPanel via les layouts
    chef->afficherchefrang(view->leftPanel);  // Ajouter au panneau gauche
    maitre->affichermaitrehotel(view->leftPanel);
    ser->afficherserveur(view->leftPanel);
    cli->creerclient(view->leftPanel);

    com->affichercommis(view->rightPanel);  // Ajouter au panneau droit
    cuis->affichercuisinier(view->rightPanel);
    plong->afficherplongeur(view->rightPanel);
}



void Controller::show() {
    view->show();
}

