#ifndef VIEW_H
#define VIEW_H

class Controller;
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>
#include <QLCDNumber>
#include <QLineEdit>
#include <QProgressBar>
#include <QComboBox>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QGraphicsItem>
#include <QStackedWidget>
#include "model\chefrang.h"
#include "model\maitrehotel.h"
#include "model\commis.h"
#include "model\cuisinier.h"
#include "model\plongeur.h"
#include "model\serveur.h"
#include "model\client.h"
#include "controller/ViewController.h"
#include "model/ViewModel.h"
#include <QObject>
#include <QWidget>


class View : public QMainWindow {
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);


public:
    void first_interface();
    void second_interface();
    void open_first_interface();
    void open_second_interface();
    void show_table_personnages();


    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *speedButton;
    QPushButton *normalButton;
    QPushButton *dashboardButton;
    QPushButton *backButton; // Bouton pour revenir à la première interface

    QSpinBox *timeSpinBox;
    QWidget *leftPanel;
    QWidget *rightPanel;
    QPixmap *pixmap;
    QLabel *label;
    QLabel *timeDisplay;
    QStackedWidget *stackedWidget; // Pour basculer entre les interfaces
    QWidget *firstPage;           // Première interface
    QWidget *secondPage;

    //chefrang *chef; // Instance de la classe chefrang
    QVector<QString> tableStatuses;
    QPushButton *getStartButton() const;
    QPushButton *getPauseButton() const;
    QSpinBox *getTimeSpinBox() const;

    void updateTimeDisplay(int time);
    //void setTableStatusStyle(int tableIndex, const QString& status);
    int Tabledisponible(int nombreClients);
    void setTableStatus(int tableIndex, const QString &status);

    QGroupBox* createTablesSection();
    QString getTableStatus(int index);
    QGroupBox* createAlertsSection();
    QGroupBox* createClientsSection();
    QGroupBox* createWaitingSection();
    QGroupBox* createPositionsSection();
    QGroupBox* createIngredientsSection();
    QGroupBox* createUtensilsSection();

private:
    QVector<QString> tableStatus;
    Model *model;  // Modèle partagé
    Controller *controller;


};


#endif // VIEW_H
