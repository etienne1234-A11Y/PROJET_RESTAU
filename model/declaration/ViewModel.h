//
// Created by mmaya on 05/12/2024.
//


#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QObject>
#include <QWidget>

class Model : public QWidget {
    Q_OBJECT

public:
    explicit Model(QWidget *parent = nullptr);

    int getTime() const;
    void setTime(int newTime);

    signals:
        void timeUpdated(int newTime);

private:
    int time;
};

#endif // VIEWMODEL_H
