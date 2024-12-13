#ifndef CUSTOMTIMER_H
#define CUSTOMTIMER_H

#include <QObject>
#include <QTimer>
#include <QSpinBox>

class CustomTimer : public QObject {
    Q_OBJECT

public:
    explicit CustomTimer(QSpinBox *spinBox, QObject *parent = nullptr);

    // Méthodes publiques pour contrôler le timer
    void start(int interval = 1000); // Démarrer le timer avec un intervalle en millisecondes
    void stop();                     // Arrêter le timer
    void reset();                    // Réinitialiser le timer (minutes et secondes)

    private slots:
        void updateTime();               // Slot appelé à chaque timeout pour mettre à jour le temps

private:
    void updateDisplay();            // Mettre à jour l'affichage au format MM:SS

    QTimer *timer;                   // Timer pour gérer les mises à jour périodiques
    QSpinBox *spinBox;               // Référence au QSpinBox pour afficher le temps
    int currentValue;                // Valeur actuelle en secondes (0 à 59)
    int currentMinutes;              // Valeur actuelle en minutes
};

#endif // CUSTOMTIMER_H
