#ifndef HUMAN_H
#define HUMAN_H

#include <QWidget>
#include <QLabel>
#include <QPoint>
#include "TableManger.h" // Correction du nom de la classe TableManager
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
class human : public QWidget {
    Q_OBJECT

public:
    // Constructeur de la classe Human
    explicit human(QWidget *parent = nullptr);

    // Méthode pour animer un personnage entre deux positions
    void moveLoop(QLabel *personnageLabel, const QPoint &startPos, const QPoint &endPos, int duration);
    void moveOnce(QLabel *personnageLabel, const QPoint &startPos, const QPoint &endPos, int duration);

    // Méthode pour obtenir la position d'une table
    QPoint getTablePosition(int tableIndex, const TableManger &manager) const;
    void stopMovements();
private:
    QVector<QPropertyAnimation*> activeAnimations;
    // Autres données ou méthodes nécessaires
};

#endif // HUMAN_H
