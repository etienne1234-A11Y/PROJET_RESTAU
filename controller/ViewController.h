// ViewController.h
#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H
class View;

#include <QObject>
#include <QPushButton>
#include<QList>
#include <QWidget>
#include <iostream>
#include <QTimer>
#include "model/ViewModel.h"
#include "View/view.h"
#include "model/TableManger.h"
#include "model/chefrang.h"
#include "model/maitrehotel.h"
#include "model/serveur.h"
#include "model/client.h"
#include "model/commis.h"
#include "model/cuisinier.h"
#include "model/plongeur.h"
#include "WorkerThread.h"
#include "model/Database.h"

class Controller : public QObject {
    Q_OBJECT
public:
    Controller(Model *model, View *view, QObject *parent = nullptr);

    void startsimulation();
    void assignertable();
    void chefrangchaise();
    void chefrangcuisine();
    void deplacerServeurCuisine();
    void deplacerServeurClient();
    void finDeplacementServeur();
    void finclient();
    void chefrendposte();
    void prendcommande();
    void debarasser();
    void serveurrepositionner();
    void chefrangposer();
    void chefrepositionner();
    void clientdepart();
    void collectedonnees();
    void affichergens();
    void afficherclient();
    void chefrangaccueil();
    void clientaccueil();
    void findemission();
    void remet();

    void setTableIndex(int index) { tableIndex = index; }
    int getTableIndex() const { return tableIndex; }

    void show();



private:
    Model *model;
    View *view;
    TableManger *tableManger;
    chefrang *chef;
    maitrehotel *maitre;
    serveur *ser;
    client *cli;
    commis *com;
    cuisinier *cuis;
    plongeur *plong;
    int tableIndex;  // Indice de la table partagé



};

#endif // VIEWCONTROLLER_H
