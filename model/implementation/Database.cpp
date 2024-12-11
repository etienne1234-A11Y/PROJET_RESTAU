#include "../declaration/Database.h"

Database::Database(const QString& dbName, const QString& user, const QString& password, const QString& host, int port)
    : dbName(dbName), user(user), password(password), host(host), port(port) {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName(dbName);
    db.setUserName(user);
    db.setPassword(password);
    db.setHostName(host);
    db.setPort(port);
}

Database::~Database() {
    if (db.isOpen()) {
        db.close();
    }
}

bool Database::connect() {
    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données : " << db.lastError().text();
        return false;
    }
    return true;
}

void Database::disconnect() {
    if (db.isOpen()) {
        db.close();
    }
}

QSqlQuery Database::executeQuery(const QString& queryStr) {
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
    }
    return query;
}
