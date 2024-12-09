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

class Controller : public QObject {
    Q_OBJECT

public:
    Controller(Model *model,View *view,QObject *parent = nullptr);
    void show();
    void collectedonnees();
    void affichergens();


private:
    Model *model;
    View *view;


    private slots:
    void onStartButtonClicked();
    void onPauseButtonClicked();
    void onTimeSpinBoxChanged(int time);

};

#endif // VIEWCONTROLLER_H
