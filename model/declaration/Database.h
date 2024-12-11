#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QVariant>
#include <QSqlError>
#include <QDebug>

class Database {
public:
    Database(const QString& dbName, const QString& user, const QString& password, const QString& host = "localhost", int port = 3306);
    ~Database();

    bool connect();
    void disconnect();
    QSqlQuery executeQuery(const QString& queryStr);

private:
    QSqlDatabase db;
    QString dbName;
    QString user;
    QString password;
    QString host;
    int port;
};

#endif // DATABASE_H
