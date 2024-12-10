//
// Created by mmaya on 05/12/2024.
//


#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include <QWidget>
class View;
class Model;
#include "model/ViewModel.h"
#include "View/view.h"
#include "model/Database.h"
#include "model/maitrehotel.h"
#include "model/commis.h"
#include "model/cuisinier.h"
#include "model/plongeur.h"
#include "model/serveur.h"
#include "model/client.h"
#include "model/human.h"

class Controller : public QObject {
    Q_OBJECT

public:
    Controller(Model *model,View *view,QObject *parent = nullptr);
    void show();
    void collectedonnees();
    void affichergens();
    void assignertable(int tableIndex);
    //void deplacer();



private:
    Model *model;
    View *view;




};

#endif // VIEWCONTROLLER_H
