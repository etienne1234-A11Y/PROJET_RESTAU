//
// Created by mmaya on 05/12/2024.
//


#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include "model/ViewModel.h"
#include "view.h"

class Controller : public QObject {
    Q_OBJECT

public:
    explicit Controller(Model *model, View *view, QObject *parent = nullptr);

private:
    Model *model;
    View *view;

    private slots:
        void onStartButtonClicked();
    void onPauseButtonClicked();
    void onTimeSpinBoxChanged(int time);
};

#endif // VIEWCONTROLLER_H
