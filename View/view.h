#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QStackedWidget>
#include <QComboBox>
#include <QGroupBox>
#include <QLineEdit>
#include <QLCDNumber>
#include <QProgressBar>
#include <QPixmap>

#include "controller/ViewController.h"
#include "model/ViewModel.h"
#include "model/CustomTimer.h"
#include "model/TableManger.h"

class View : public QMainWindow {
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    CustomTimer* getTimer() const;
    QPushButton* getStartButton() const;

    QSpinBox* getTimeSpinBox() const;


    int findAvailableTableForClients(int numberOfClients);
    void updateTableStatus(int tableIndex, const std::string& newStatus);

public:
    QWidget *firstPage;
    QWidget *secondPage;
    QStackedWidget *stackedWidget;

    QPushButton *startButton;


    QPushButton *dashboardButton;
    QPushButton *backButton;

    QSpinBox *timeSpinBox;
    QLCDNumber *clientCountDisplay;
    QComboBox *alertComboBox;

    QGraphicsView *view;
    QGraphicsScene *scene;

    QWidget *leftPanel;
    QWidget *rightPanel;
    QPixmap *pixmap;

    CustomTimer *timer;
    TableManger tableManager;

    void first_interface();
    void second_interface();

    QGroupBox* createTablesSection();
    QGroupBox* createAlertsSection();
    QGroupBox* createClientsSection();
    QGroupBox* createWaitingSection();
    QGroupBox* createPositionsSection();
    QGroupBox* createIngredientsSection();
    QGroupBox* createUtensilsSection();
    void updateClientCount(int count);

    void show_table_personnages();

    private :
        TableManger tableManger; // Instance pour gérer les tables
    std::map<int, QLabel*> tableLabels; // Pour suivre les label

};

#endif // VIEW_H
