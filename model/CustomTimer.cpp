#include "CustomTimer.h"

CustomTimer::CustomTimer(QSpinBox *spinBox, QObject *parent)
    : QObject(parent), spinBox(spinBox), currentValue(0), currentMinutes(0) {
    timer = new QTimer(this);

    // Connecter le timer à la méthode d'incrémentation
    connect(timer, &QTimer::timeout, this, &CustomTimer::updateTime);

    // Configurer le QSpinBox
    spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons); // Désactiver les boutons
    spinBox->setReadOnly(true);                             // Rendre le champ non modifiable
    spinBox->setRange(0, 0);                                // Fixer la plage à une seule valeur
    spinBox->setSpecialValueText("00:00");                  // Texte initial
}

void CustomTimer::start(int interval) {
    // Démarrer le timer avec l'intervalle spécifié (1000 ms par défaut)
    timer->start(interval);
}

void CustomTimer::stop() {
    // Arrêter le timer
    timer->stop();
}

void CustomTimer::reset() {
    // Arrêter le timer et réinitialiser les minutes et les secondes à 0
    stop();
    currentValue = 0;
    currentMinutes = 0;
    updateDisplay();
}

void CustomTimer::updateTime() {
    // Incrémenter les secondes
    currentValue++;
    if (currentValue == 60) {
        // Passer à la minute suivante et réinitialiser les secondes
        currentValue = 0;
        currentMinutes++;
    }
    updateDisplay();
}

void CustomTimer::updateDisplay() {
    // Format du temps en MM:SS
    QString timeText = QString("%1:%2")
                           .arg(currentMinutes, 2, 10, QChar('0')) // Minutes avec zéro-padding
                           .arg(currentValue, 2, 10, QChar('0'));  // Secondes avec zéro-padding

    // Utiliser setSpecialValueText pour afficher uniquement le temps
    spinBox->setSpecialValueText(timeText);
    spinBox->setValue(0); // Nécessaire pour forcer l'affichage de specialValueText
}
