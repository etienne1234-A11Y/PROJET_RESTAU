//
// Created by TRIPLE K on 10/12/2024.
//
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#ifndef HUMAN_H
#define HUMAN_H



class human : public QWidget {
    Q_OBJECT

    public:
    explicit human(QWidget *parent = nullptr);
    void move(int tableIndex,QWidget *parent);
    void deplacement (QWidget *parent);

};



#endif //HUMAN_H
