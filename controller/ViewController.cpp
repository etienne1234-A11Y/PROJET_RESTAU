// ViewController.cpp
#include "ViewController.h"
#include <QRandomGenerator>
#include <QTimer>
#include <iostream>

Controller::Controller(Model *model, View *view, QObject *parent)
    : QObject(parent), view(view), model(model), tableIndex(-1) {
    connect(view->getStartButton(), &QPushButton::clicked, this, &Controller::startsimulation);
    tableManger = new TableManger();
    chef = new chefrang();
    maitre = new maitrehotel();
    ser = new serveur();
    cli = new client();
    com = new commis();
    cuis = new cuisinier();
    plong = new plongeur();
}
int numberOfClients = QRandomGenerator::global()->bounded(1, 11);

void Controller::startsimulation() {
    // Réinitialiser le compteur de temps avant de commencer
    view->getTimeSpinBox()->setValue(0);
    view->getTimer()->start(1000); // Démarrer le timer avec un intervalle de 1 seconde

    // Créer et configurer les threads de travail
    WorkThread* t1 = new WorkThread();
    WorkThread* t2 = new WorkThread();
    WorkThread* t3 = new WorkThread();
    WorkThread* t4 = new WorkThread();
    WorkThread* t5 = new WorkThread();
    WorkThread* t6 = new WorkThread();
    WorkThread* t7 = new WorkThread();
    WorkThread* t8 = new WorkThread();
    WorkThread* t9 = new WorkThread();
    WorkThread* t10 = new WorkThread();
    WorkThread* t11 = new WorkThread();
    WorkThread* t12 = new WorkThread();
    WorkThread* t13 = new WorkThread();
    WorkThread* t14 = new WorkThread();
    WorkThread* t15 = new WorkThread();
    WorkThread* t24 = new WorkThread();
    WorkThread* t17 = new WorkThread();
    WorkThread* t18 = new WorkThread();
    WorkThread* t19 = new WorkThread();
    WorkThread* t20 = new WorkThread();

    connect(t1, &WorkThread::workStarted, this, &Controller::affichergens);
    connect(t2, &WorkThread::workStarted, this, &Controller::clientaccueil);
    connect(t3, &WorkThread::workStarted, this, &Controller::chefrangaccueil);
    connect(t4, &WorkThread::workStarted, this, &Controller::afficherclient);
    connect(t5, &WorkThread::workStarted, this, &Controller::assignertable);
    connect(t6, &WorkThread::workStarted, this, &Controller::chefrangchaise);
    connect(t7, &WorkThread::workStarted, this, &Controller::chefrangcuisine);
    connect(t8, &WorkThread::workStarted, this, &Controller::findemission);
    connect(t9, &WorkThread::workStarted, this, &Controller::deplacerServeurCuisine);
    connect(t10, &WorkThread::workStarted, this, &Controller::finDeplacementServeur);
    connect(t11, &WorkThread::workStarted, this, &Controller::finclient);
    connect(t12, &WorkThread::workStarted, this, &Controller::deplacerServeurClient);
    connect(t13, &WorkThread::workStarted, this, &Controller::chefrendposte);
    connect(t14, &WorkThread::workStarted, this, &Controller::prendcommande);
    connect(t15, &WorkThread::workStarted, this, &Controller::debarasser);
     connect(t24, &WorkThread::workStarted, this, &Controller::serveurrepositionner);
     connect(t17, &WorkThread::workStarted, this, &Controller::chefrangposer);
     connect(t18, &WorkThread::workStarted, this, &Controller::chefrepositionner);
     connect(t19, &WorkThread::workStarted, this, &Controller::clientdepart);
    connect(t20, &WorkThread::workStarted, this, &Controller::remet);


    // Démarrer le premier thread immédiatement
    t1->start();

    // Utiliser QTimer::singleShot pour démarrer les threads suivants après un délai
    QTimer::singleShot(3000, this, [this, t4] {
        t4->start();
    });

    QTimer::singleShot(4000, this, [this, t2] {
        t2->start();
    });

    QTimer::singleShot(10000, this, [this, t3] {
        t3->start();
    });

    QTimer::singleShot(15000, this, [this, t5] {
        t5->start();
    });

    // QTimer::singleShot(25000, this, [this, t6] {
    //     t6->start();
    // });
    QTimer::singleShot(35000, this, [this, t13] {
        t13->start();
    });
    QTimer::singleShot(40000, this, [this, t14] {
        t14->start();
    });

    QTimer::singleShot(45000, this, [this, t7] {
        t7->start();
    });

    QTimer::singleShot(50000, this, [this, t8] {
        t8->start();
    });

    QTimer::singleShot(55000, this, [this, t9] {
        t9->start();
    });
    QTimer::singleShot(60000, this, [this, t12] {
        t12->start();
    });

    QTimer::singleShot(65000, this, [this, t10] {
        t10->start();
    });

    QTimer::singleShot(70000, this, [this, t15] {
        t15->start();
    });
    QTimer::singleShot(75000, this, [this, t20] {
        t20->start();
    });
    QTimer::singleShot(80000, this, [this, t11] {
        t11->start();
    });

    QTimer::singleShot(85000, this, [this, t24] {
        t24->start();
    });

    QTimer::singleShot(90000, this, [this, t19] {
        t19->start();
    });
    QTimer::singleShot(95000, this, [this, t17] {
        t17->start();
    });
    QTimer::singleShot(100000, this, [this, t18] {
        t18->start();
    });

}

void Controller::collectedonnees() {
    QString dbName = "resto";
    QString user = "root";
    QString password = "K3m@j0uK3rry";
    QString host = "127.0.0.1";
    int port = 3306;
    Database db(dbName, user, password, host, port);
}

void Controller::affichergens() {
    chef->afficherchefrang(view->leftPanel);
    maitre->affichermaitrehotel(view->leftPanel);
    ser->afficherserveur(view->leftPanel);

    com->affichercommis(view->rightPanel);
    cuis->affichercuisinier(view->rightPanel);
    plong->afficherplongeur(view->rightPanel);
}

void Controller::afficherclient() {
    cli->creerclient(view->leftPanel);
}



void Controller::chefrangaccueil() {

        chef->deplacerchefrangaccueil(view->leftPanel);

}

void Controller::clientaccueil() {

        cli->deplacerclientaccueil(view->leftPanel);

}

void Controller::assignertable() {
    tableIndex = tableManger->findAvailableTable(numberOfClients);  // Stocker l'indice ici
    view->updateClientCount(numberOfClients);

    if (tableIndex != -1) {
        if (tableIndex >= 0 && tableIndex < tableManger->getTablePositions().size()) {
            std::cout << "Table disponible trouvée à l'indice " << tableIndex << std::endl;
            cli->deplacerclient(view->leftPanel, tableIndex);
            chef->deplacerchefrangclient(view->leftPanel, tableIndex);
            tableManger->setTableStatus(tableIndex, "occupied");
            view->updateTableStatus(tableIndex, "occupied");
        } else {
            std::cerr << "Erreur : Indice de table invalide." << std::endl;
        }
    } else {
        std::cerr << "Aucune table disponible pour " << numberOfClients << " client(s)." << std::endl;
    }
}

void Controller::chefrangchaise() {
    if (tableIndex != -1) {
        chef->deplacerchefrangclient(view->leftPanel, tableIndex);
    }
}
void Controller::chefrendposte() {
    if (tableIndex != -1) {
        chef->repartposte(view->leftPanel, tableIndex);
    }
}
void Controller::prendcommande() {
    if (tableIndex != -1) {
        chef->prendcommande(view->leftPanel, tableIndex);
    }
}



void Controller::chefrangcuisine() {
    if (tableIndex != -1) {
        chef->deplacerchefrangcuisine(view->leftPanel, tableIndex);
    }
}

void Controller::findemission() {
    if (tableIndex != -1) {
        chef->findemission(view->leftPanel);
    }
}

void Controller::deplacerServeurCuisine() {
    if (tableIndex != -1) {
        ser->deplacerserveurcuisine(view->leftPanel);
    }
}

void Controller::deplacerServeurClient() {
    if (tableIndex != -1) {
        ser->deplacerserveurclient(view->leftPanel, tableIndex);
    }
}

void Controller::finDeplacementServeur() {
    if (tableIndex != -1) {
        ser->finserveur(view->leftPanel, tableIndex);
    }
}

void Controller::finclient() {
    if (tableIndex != -1) {
        cli->fin(view->leftPanel, tableIndex);
    }
}
void Controller::debarasser() {
    if (tableIndex != -1) {
        ser->debarasser(view->leftPanel, tableIndex);
    }
}
void Controller ::serveurrepositionner() {

        ser->repositionner(view->leftPanel);

}
void Controller::chefrangposer() {
    if (tableIndex != -1) {
        chef->poserplat(view->leftPanel, tableIndex);
    }
}
void Controller::chefrepositionner() {
    if (tableIndex != -1) {
        chef->position(view->leftPanel, tableIndex);
    }
}
void Controller::clientdepart() {
    cli->rentrer(view->leftPanel);
}
void Controller::remet() {
    if (tableIndex != -1) {
        ser->remetcouvert(view->leftPanel, tableIndex);
    }
}

void Controller::show() {
    view->show();
}
