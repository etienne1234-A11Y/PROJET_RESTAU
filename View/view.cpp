#include "view.h"

#include <QPushButton>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLCDNumber>
#include <QLineEdit>
#include <QProgressBar>
#include <QComboBox>
#include <QGroupBox>
#include <QPixmap>
#include <QGraphicsItem>
#include <QStackedWidget>

View::View(QWidget *parent) : QMainWindow(parent) {
    // Initialiser le QStackedWidget pour basculer entre les interfaces


    // Créer les interfaces


    // Ajouter les interfaces au QStackedWidget

    firstPage = new QWidget(this);
    secondPage = new QWidget(this);
    stackedWidget = new QStackedWidget(this);

    first_interface();
    second_interface();
    stackedWidget->addWidget(firstPage);
    stackedWidget->addWidget(secondPage);

    // Définir le QStackedWidget comme widget central
    setCentralWidget(stackedWidget);

    // Connexions pour changer d'interface
    connect(dashboardButton, &QPushButton::clicked, this, [=]() {
       stackedWidget->setCurrentWidget(secondPage);
   });
    connect(backButton, &QPushButton::clicked, this, [=]() {
        stackedWidget->setCurrentWidget(firstPage);
    });
}

void View::first_interface() {
    startButton = new QPushButton("START");
    pauseButton = new QPushButton("PAUSE");
    speedButton = new QPushButton("SPEED");
    normalButton = new QPushButton("NORMAL");
    dashboardButton = new QPushButton("DASHBOARD");
    timeSpinBox = new QSpinBox();
    leftPanel = new QWidget();
    rightPanel = new QWidget();

    // Créer le widget central
    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    // Layout principal (vertical)
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Layout pour les boutons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(pauseButton);
    buttonLayout->addWidget(speedButton);
    buttonLayout->addWidget(normalButton);
    buttonLayout->addWidget(dashboardButton);

    // Configurer le SpinBox
    timeSpinBox->setPrefix("00:00");
    timeSpinBox->setRange(0, 60); // Limite des secondes
    buttonLayout->addWidget(timeSpinBox);

    mainLayout->addLayout(buttonLayout);

    // Layout pour les deux panneaux principaux
    QHBoxLayout *panelsLayout = new QHBoxLayout();

    leftPanel->setFixedSize(990, 671);
    rightPanel->setFixedSize(521, 671);

    leftPanel->setObjectName("leftPanel");
    rightPanel->setObjectName("rightPanel");

    panelsLayout->addWidget(leftPanel);
    panelsLayout->addWidget(rightPanel);

    mainLayout->addLayout(panelsLayout);

    // Afficher le chef de rang dans le leftPanel
    chefrang *chef = new chefrang(this);
    chef->afficherchefrang(leftPanel); // Passer leftPanel comme parent
    maitrehotel *maitre = new maitrehotel(this);
    maitre->affichermaitrehotel(leftPanel);
    serveur *ser = new serveur(this);
    ser ->afficherserveur(leftPanel);
    commis *com = new commis(this);
    com->affichercommis(rightPanel);
    cuisinier *cuis = new cuisinier(this);
    cuis-> affichercuisinier(rightPanel);
    plongeur *plong = new plongeur(this);
    plong->afficherplongeur(rightPanel);


    show_table_personnages();

    firstPage->setLayout(mainLayout);
}




void View::second_interface() {
    // Créer le widget central

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);





    // Boutons principaux
    QHBoxLayout *topButtonsLayout = new QHBoxLayout;
    startButton = new QPushButton("START");
    pauseButton = new QPushButton("PAUSE");
    backButton = new QPushButton("BACK");
    topButtonsLayout->addWidget(startButton);
    topButtonsLayout->addWidget(pauseButton);
    topButtonsLayout->addWidget(backButton);
    topButtonsLayout->addStretch();

    // Disposition globale
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(topButtonsLayout, 0, 0, 1, 3);
    mainLayout->addWidget(createTablesSection(), 1, 0);
    mainLayout->addWidget(createAlertsSection(), 1, 1);
    mainLayout->addWidget(createIngredientsSection(), 1, 2);
    mainLayout->addWidget(createClientsSection(), 2, 0);
    mainLayout->addWidget(createWaitingSection(), 2, 1);
    mainLayout->addWidget(createPositionsSection(), 2, 2);
    mainLayout->addWidget(createUtensilsSection(), 3, 0, 1, 3);

    centralWidget->setLayout(mainLayout);
    secondPage->setLayout(mainLayout);
}

QPushButton* View::getStartButton() const {
    return startButton;
}

QPushButton* View::getPauseButton() const {
    return pauseButton;
}

QSpinBox* View::getTimeSpinBox() const {
    return timeSpinBox;
}

void View::updateTimeDisplay(int time) {
    // Utilisez l'opérateur approprié selon que timeDisplay est un pointeur ou non
#ifdef USE_POINTER
    timeDisplay->setText(QString::number(time));
#else
    timeDisplay->setText(QString::number(time));
#endif
}


QGroupBox* View::createTablesSection() {
    QGroupBox *group = new QGroupBox("ETATS DES TABLES");
    QVBoxLayout *layout = new QVBoxLayout;
    for (int i = 0; i < 12; ++i) {
        QHBoxLayout *rowLayout = new QHBoxLayout;
        QLineEdit *tableName = new QLineEdit(QString("Table_%1").arg(i + 1));
        tableName->setReadOnly(true);
        QLabel *status = new QLabel("●");
        status->setStyleSheet("color: green; font-size: 16px;");
        rowLayout->addWidget(tableName);
        rowLayout->addWidget(status);
        layout->addLayout(rowLayout);
    }
    group->setLayout(layout);
    return group;
}

QGroupBox* View::createAlertsSection() {
    QGroupBox *group = new QGroupBox("ALERTES");
    QGridLayout *layout = new QGridLayout;
    for (int i = 1; i <= 8; ++i) {
        QLabel *alertLabel = new QLabel(QString("Alerte %1").arg(i));
        QLabel *alertStatus = new QLabel("●");
        alertStatus->setStyleSheet("color: red; font-size: 16px;");
        layout->addWidget(alertLabel, (i - 1) / 4, (i - 1) % 4 * 2);
        layout->addWidget(alertStatus, (i - 1) / 4, (i - 1) % 4 * 2 + 1);
    }
    group->setLayout(layout);
    return group;
}

QGroupBox* View::createClientsSection() {
    QGroupBox *group = new QGroupBox("NOMBRES TOTAL DE CLIENTS");
    QVBoxLayout *layout = new QVBoxLayout;
    QLCDNumber *clientCount = new QLCDNumber;
    layout->addWidget(clientCount);
    group->setLayout(layout);
    return group;
}

QGroupBox* View::createWaitingSection() {
    QGroupBox *group = new QGroupBox("TEMPS MOYENS D'ATTENTES");
    QVBoxLayout *layout = new QVBoxLayout;
    QComboBox *timeComboBox = new QComboBox;
    timeComboBox->addItems({"00:00", "00:30", "01:00"});
    layout->addWidget(timeComboBox);
    group->setLayout(layout);
    return group;
}

QGroupBox* View::createPositionsSection() {
    QGroupBox *group = new QGroupBox("SUIVIS DES POSTES");
    QGridLayout *layout = new QGridLayout;

    QStringList positions = {
        "Maître d'hôtel",
        "Commis cuisine",
        "Chef de rang carré 1",
        "Chef de rang carré 2",
        "Serveur carré 1",
        "Serveur carré 2",
        "Chef cuisinier",
        "Plongeur"
    };

    for (int i = 0; i < positions.size(); ++i) {
        QLineEdit *positionLine = new QLineEdit(positions[i]);
        positionLine->setReadOnly(true); // Nom du poste non modifiable

        QLabel *status = new QLabel("●");
        if (i % 2 == 0) { // Alterner les couleurs pour simuler les statuts
            status->setStyleSheet("color: green; font-size: 16px;"); // Disponible
        } else {
            status->setStyleSheet("color: red; font-size: 16px;"); // Occupé
        }

        layout->addWidget(positionLine, i, 0); // Ajouter le nom du poste
        layout->addWidget(status, i, 1);      // Ajouter l’indicateur d’état
    }

    group->setLayout(layout);
    return group;
}

QGroupBox *View::createIngredientsSection() {
    QGroupBox *group = new QGroupBox("QUANTITÉ D'INGRÉDIENTS DISPONIBLES");
    QGridLayout *layout = new QGridLayout;
    QStringList ingredients = {"Oeufs", "Viandes", "Oignons", "Tomates", "Beurres", "Farines"};
    for (int i = 0; i < ingredients.size(); ++i) {
        QLineEdit *ingredientLine = new QLineEdit(ingredients[i]);
        ingredientLine->setReadOnly(true);
        QProgressBar *progressBar = new QProgressBar;
        progressBar->setValue(50); // Exemple
        layout->addWidget(ingredientLine, i, 0);
        layout->addWidget(progressBar, i, 1);
    }
    group->setLayout(layout);
    return group;
}

QGroupBox* View::createUtensilsSection() {
    QGroupBox *group = new QGroupBox("SUIVIS DES UTENSILES");
    QGridLayout *layout = new QGridLayout;
    QStringList utensils = {"Corbeilles à pain", "Plats", "Verres", "Fourchettes", "Couteaux", "Cuillères"};
    for (int i = 0; i < utensils.size(); ++i) {
        QLineEdit *utensilLine = new QLineEdit(utensils[i]);
        utensilLine->setReadOnly(true);
        QProgressBar *progressBar = new QProgressBar;
        progressBar->setValue(100); // Exemple
        layout->addWidget(utensilLine, i, 0);
        layout->addWidget(progressBar, i, 1);
    }
    group->setLayout(layout);
    return group;
}
void View::open_second_interface() {
    second_interface();
}
void View::open_first_interface() {
    first_interface();
}


void View::show_table_personnages() {
    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/acceuil.png");
    QLabel *label = new QLabel(leftPanel);
    label->setObjectName("label");
    label ->setPixmap(*pixmap);
    //label->setScaledContents(true);
    label->setGeometry(12,10,171,230);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/fauteil1.png");
    QLabel *label1 = new QLabel(leftPanel);
    label1 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label1->setGeometry(10,350,171,221);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/fauteil2.png");
    QLabel *label2 = new QLabel(leftPanel);
    label2 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label2->setGeometry(10,565,401,101);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tapis-removebg-preview.png");
    QLabel *label3 = new QLabel(leftPanel);
    label3 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label3->setGeometry(5,230,171,128);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tapis-removebg-preview.png");
    QLabel *label4 = new QLabel(leftPanel);
    label4 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label4->setGeometry(130,230,171,128);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tapis-removebg-preview.png");
    QLabel *label5 = new QLabel(leftPanel);
    label5 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label5->setGeometry(260,230,171,128);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tapis-removebg-preview.png");
    QLabel *label6 = new QLabel(leftPanel);
    label6 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label6->setGeometry(390,230,171,128);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tapis-removebg-preview.png");
    QLabel *label7 = new QLabel(leftPanel);
    label7 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label7->setGeometry(520,230,171,128);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tapis-removebg-preview.png");
    QLabel *label8 = new QLabel(leftPanel);
    label8 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label8->setGeometry(650,230,171,128);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tapis-removebg-preview.png");
    QLabel *label9 = new QLabel(leftPanel);
    label9 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label9->setGeometry(780,230,171,128);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tapis-removebg-preview.png");
    QLabel *label10 = new QLabel(leftPanel);
    label10 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label10->setGeometry(910,230,171,128);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tapis-removebg-preview.png");
    QLabel *label22 = new QLabel(leftPanel);
    label22 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label22->setGeometry(1040,230,171,128);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tablede4-removebg-preview.png");
    QLabel *label11 = new QLabel(leftPanel);
    label11 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label11->setGeometry(200,20,121,101);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tableronde6-removebg-preview.png");
    QLabel *label12 = new QLabel(leftPanel);
    label12 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label12->setGeometry(415,20,121,101);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tableronde8-removebg-preview.png");
    QLabel *label13 = new QLabel(leftPanel);
    label13 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label13->setGeometry(600,120,151,131);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/tableronde10-removebg-preview.png");
    QLabel *label14 = new QLabel(leftPanel);
    label14 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label14->setGeometry(800,10,161,161);



    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/table4-removebg-preview.png");
    QLabel *label16 = new QLabel(leftPanel);
    label16 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label16->setGeometry(280,140,121,101);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/table6-removebg-preview.png");
    QLabel *label17 = new QLabel(leftPanel);
    label17 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label17->setGeometry(800,530,161,131);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/table8-removebg-preview.png");
    QLabel *label18 = new QLabel(leftPanel);
    label18 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label18->setGeometry(500,325,201,171);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/table10-removebg-preview.png");
    QLabel *label15 = new QLabel(leftPanel);
    label15 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label15->setGeometry(500,500,201,171);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/table6-removebg-preview.png");
    QLabel *label19 = new QLabel(leftPanel);
    label19 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label19->setGeometry(280,400,201,171);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/table4-removebg-preview.png");
    QLabel *label20 = new QLabel(leftPanel);
    label20 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label20->setGeometry(800,355,121,101);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/table 2.png");
    QLabel *label21 = new QLabel(leftPanel);
    label21 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label21->setGeometry(625,20,121,71);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/cuisiniere.png");
    QLabel *label23 = new QLabel(rightPanel);
    label23 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label23->setGeometry(410,10,63,321);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/table.png");
    QLabel *label24 = new QLabel(rightPanel);
    label24 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label24->setGeometry(180,10,81,251);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/table.png");
    QLabel *label25 = new QLabel(rightPanel);
    label25 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label25->setGeometry(240,10,81,251);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/plonge.png");
    QLabel *label26 = new QLabel(rightPanel);
    label26 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label26->setGeometry(410,420,71,81);

    pixmap = new QPixmap( "F:/X3/programmation concurrente/restaurant_projet/resto_projet/images/plonge.png");
    QLabel *label27 = new QLabel(rightPanel);
    label27 ->setPixmap(*pixmap);
    label->setScaledContents(true);
    label27->setGeometry(410,510,71,81);



}