
// main.cpp
#include <QApplication>
#include <QFile>
#include "model/ViewModel.h"
#include "view/view.h"
#include "controller/ViewController.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    QFile styleFile(":/style.css"); // Utilisation depuis les ressources
    if (styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        app.setStyleSheet(styleSheet); // Applique la feuille de style à toute l'application
    }

    View view;
    Model model;
    Controller controller(&model,&view);


    controller.show();

    return app.exec();
}

