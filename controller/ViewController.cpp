//
// Created by mmaya on 05/12/2024.
//

#include "ViewController.h"



Controller::Controller(Model *model, View *view , QObject *parent)
    : QObject(parent), view(view) , model(model) {


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
void Controller::assignertable(int tableIndex) {

    // std::random_device rd;  // Obtenir une valeur aléatoire à partir du matériel
    // std::mt19937 gen(rd());  // Initialiser le générateur avec la valeur de rd()
    // std::uniform_int_distribution<> dis(1, 10);  // Plage entre 1 et 10
    //
    // // Générer un nombre aléatoire
    // int nombreClients = dis(gen);
    // QString status = view->getTableStatus(tableIndex);
    //
    // int tableCapacities = view->Tabledisponible(nombreClients);
    //  if  ( nombreClients == tableCapacities && status == "available") {
    //      view->setTableStatus(tableIndex, "occupied");
    //
    //      human *hum = new human(view);
    //      hum->move(tableIndex,view->leftPanel);
    //  }

    }
// void Controller::deplacer() {
//     client *cli = new client(view);
//     cli->deplacerVers(200,100);
// }







void Controller::show() {
    view->show();
}

