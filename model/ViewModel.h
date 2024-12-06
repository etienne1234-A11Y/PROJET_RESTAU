//
// Created by mmaya on 05/12/2024.
//


#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QObject>

class Model : public QObject {
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

    int getTime() const;
    void setTime(int newTime);

    signals:
        void timeUpdated(int newTime);

private:
    int time;
};

#endif // VIEWMODEL_H
