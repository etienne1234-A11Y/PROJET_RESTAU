//
// Created by mmaya on 05/12/2024.
//

#include "ViewController.h"


Controller::Controller(Model *model, View *view, QObject *parent)
    : QObject(parent), model(model), view(view) {

    // Connect View to Model
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
void Controller::show() {
    view->show();
}
