#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include <QObject>

class WorkThread : public QThread {
    Q_OBJECT
public:
    WorkThread(QObject* parent = nullptr) : QThread(parent) {}

protected:
    void run() override {
        // Insérez la logique à exécuter dans le thread
        // Par exemple, la fonction assignertable ou affichergens
        emit workStarted();
        // Simuler une tâche
        QThread::sleep(2); // Simuler un délai pour la tâche
        emit workFinished();
    }

    signals:
    void workStarted();
    void workFinished();
};

#endif // WORKTHREAD_H
