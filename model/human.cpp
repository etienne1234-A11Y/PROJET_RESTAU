#include "Human.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QEasingCurve>
#include <QPoint>
#include "TableManger.h"  // Inclure la classe TableManager

// Renommé en Human pour respecter la convention de nommage
human::human(QWidget *parent) : QWidget(parent) {
    // Initialisation si nécessaire
}
void human::moveOnce(QLabel *personnageLabel, const QPoint &startPos, const QPoint &endPos, int duration) {
    personnageLabel->setGeometry(startPos.x(), startPos.y(), 15, 30);

    // Créer une animation pour déplacer le personnage vers la position finale
    QPropertyAnimation *goToEnd = new QPropertyAnimation(personnageLabel, "pos");
    goToEnd->setDuration(duration);
    goToEnd->setStartValue(startPos);
    goToEnd->setEndValue(endPos);
    goToEnd->setEasingCurve(QEasingCurve::OutQuad);

    // Lancer l'animation sans boucle
    goToEnd->start();
}

void human::moveLoop(QLabel *personnageLabel, const QPoint &startPos, const QPoint &endPos, int duration) {
    personnageLabel->setGeometry(startPos.x(), startPos.y(), 15, 30);

    QPropertyAnimation *goToEnd = new QPropertyAnimation(personnageLabel, "pos");
    goToEnd->setDuration(duration);
    goToEnd->setStartValue(startPos);
    goToEnd->setEndValue(endPos);
    goToEnd->setEasingCurve(QEasingCurve::OutQuad);

    QPropertyAnimation *returnToStart = new QPropertyAnimation(personnageLabel, "pos");
    returnToStart->setDuration(duration);
    returnToStart->setStartValue(endPos);
    returnToStart->setEndValue(startPos);
    returnToStart->setEasingCurve(QEasingCurve::OutQuad);

    QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
    group->addAnimation(goToEnd);
    group->addAnimation(returnToStart);
    group->setLoopCount(-1);
    group->start();
}

QPoint human::getTablePosition(int tableIndex, const TableManger &manager) const {
    // On récupère les positions des tables sous forme de std::pair<int, int>
    std::pair<int, int> position = manager.getTablePosition(tableIndex);

    // Convertir le std::pair<int, int> en QPoint
    return QPoint(position.first, position.second);
}
