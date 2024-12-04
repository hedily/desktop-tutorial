#include "connection.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>

Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connection::createConnect() {
    db.setDatabaseName("CPP_Project");
    db.setUserName("hedil");            // Nom d'utilisateur
    db.setPassword("oracle");           // Mot de passe

    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données:";
        qDebug() << "Nom de la base de données:" << db.databaseName();
        qDebug() << "Utilisateur:" << db.userName();
        qDebug() << "Erreur:" << db.lastError().text();
        return false;
    }

    qDebug() << "Connexion réussie à la base de données!";
    return true;
}

void Connection::closeConnection() {
    db.close();
    qDebug() << "Connexion fermée.";
}
