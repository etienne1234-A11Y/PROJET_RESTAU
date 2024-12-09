//
// Created by mmaya on 05/12/2024.
//

#include "ViewModel.h"


Model::Model(QWidget *parent) : QWidget(parent), time(0) {

}

int Model::getTime() const {
    return time;
}

void Model::setTime(int newTime) {
    if (time != newTime) {
        time = newTime;
        emit timeUpdated(time);
    }
}

