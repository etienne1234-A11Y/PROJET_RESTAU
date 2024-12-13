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

        emit workStarted();

    }

    signals:
    void workStarted();

};

#endif // WORKTHREAD_H
