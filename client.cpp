#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QStringList>
#include <utility> // pour std::move
#include <QUrl>
#include <QDesktopServices>
#include <QMessageBox>

Client::Client() {}

Client::Client(const QString& id_client, const QString& nom, const QString& prenom,const QString& adresse, int telephone,  const QString& genre, const QString& email, const QString& dn, int pt_fidelite)
    : id_client(id_client), nom(nom), prenom(prenom), adresse(adresse), telephone(telephone), genre(genre),  email(email),dn(dn), pt_fidelite(pt_fidelite) {}

bool Client::ajouter() {
    QSqlQuery query;


    QString telephone_string=QString::number(telephone);
    QString pt_string=QString::number(pt_fidelite);


    query.prepare("INSERT INTO client (id_client, nom, prenom,adresse,telephone, genre,  email, dn, pt_fidelite) "
                  "VALUES (:id_client, :nom, :prenom, :adresse,:telephone ,:genre,  :email, :dn, :pt_fidelite)");

    query.bindValue(":id_client", id_client);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":telephone", telephone_string);

    query.bindValue(":genre", genre);
    query.bindValue(":email", email);

    query.bindValue(":dn", dn);
    query.bindValue(":pt_fidelite", pt_string);



    return query.exec();
}

QSqlQueryModel* Client::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM client");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));


    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Genre"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de Naissance"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Points de Fidélité"));

    return model;
}
bool Client::supprimer(QString id) {
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE id_client = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Client:: modifier(const QString& id_client, const QString& nom, const QString& prenom,
                  const QString& adresse, int telephone, const QString& email,const QString& genre,
                  const QString& dn, int pt_fidelite){
    // Convertir les entiers en QString si nécessaire
    QString telephone_string = QString::number(telephone);
    QString pt_string = QString::number(pt_fidelite);

    QSqlQuery query;
    query.prepare("UPDATE client SET nom = :nom, prenom = :prenom, telephone = :telephone, "
                  "email = :email, adresse = :adresse, genre = :genre, dn = :dn, "
                  "pt_fidelite = :pt_fidelite WHERE id_client = :id_client");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":telephone", telephone_string);
    query.bindValue(":email", email);
    query.bindValue(":id_client", id_client);
    query.bindValue(":genre", genre);
    query.bindValue(":dn", dn);
    query.bindValue(":pt_fidelite", pt_string);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour du client:" << query.lastError().text();
        return false;
    }

    return true;
}



QSqlQueryModel* Client::trier(const QString& critere, bool ascendant) {
    QSqlQuery query;
    QString queryString = "SELECT * FROM client";

    if (!critere.isEmpty()) {
        queryString += " ORDER BY " + critere;
        if (!ascendant) {
            queryString += " DESC";
        }
    }

    query.prepare(queryString);
    query.exec();

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(std::move(query));

    return model;
}

QSqlQueryModel* Client::rechercher(const QString& valeur) {
    QSqlQuery query;
    QString queryString;

    if (valeur.toInt() > 0) {
        queryString = "SELECT * FROM client WHERE id_client = :valeur";
    } else {
        queryString = "SELECT * FROM client "
                      "WHERE nom LIKE :valeurLike "
                      "OR prenom LIKE :valeurLike";
    }

    query.prepare(queryString);

    if (valeur.toInt() > 0) {
        query.bindValue(":valeur", valeur);
    } else {
        query.bindValue(":valeurLike", "%" + valeur + "%");
    }

    qDebug() << "Executing query:" << queryString;
    qDebug() << "Binding values - " << (valeur.toInt() > 0 ? "exact:" : "LIKE pattern:") << valeur;

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(std::move(query));

    return model;
}


 QMap<QString, int> Client::obtenirStatistiquesParAdresse() {
    QMap<QString, int> statistiques;
    QSqlQuery query;
    query.prepare("SELECT adresse, COUNT(*) as count FROM client GROUP BY adresse");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        return statistiques;
    }

    while (query.next()) {
        QString adresse = query.value(0).toString();
        int count = query.value(1).toInt();
        statistiques[adresse] = count;
    }

    return statistiques;
}

 QMap<QString, int> Client::statistiquesParGenre() {
     QSqlQuery query;
     query.prepare("SELECT genre, COUNT(*) as count FROM client GROUP BY genre");

     if (!query.exec()) {
         qDebug() << "Erreur lors de la récupération des statistiques par genre:" << query.lastError().text();
         return QMap<QString, int>();
     }

     QMap<QString, int> statistiques;

     while (query.next()) {
         QString genre = query.value(0).toString();
         int count = query.value(1).toInt();
         statistiques[genre] = count;
     }

     return statistiques;
 }
 QList<Client> Client::getAnniversairesProches() {
     QList<Client> clients;
     QSqlQuery query;
     query.prepare("SELECT * FROM client WHERE pt_fidelite >=800;");

     if (!query.exec()) {
         qDebug() << "Erreur lors de la récupération des anniversaires:" << query.lastError().text();
         return clients;

     }

     while (query.next()) {
         clients.append(Client(
             query.value("id_client").toString(),
             query.value("nom").toString(),
             query.value("prenom").toString(),
             query.value("adresse").toString(),
             query.value("telephone").toInt(),
             query.value("email").toString(),
             query.value("genre").toString(),
             query.value("dn").toString(),
             query.value("pt_fidelite").toInt()
             ));
     }

     return clients;
 }
 bool Client::envoyerEmail(QString id_client, QString sujet, QString message) {
     QSqlQuery query;
     query.prepare("SELECT email FROM client WHERE id_client = :id_client");
     query.bindValue(":id_client", id_client);

     if (query.exec()) {
         if (query.next()) {
             QString email = query.value(0).toString();
             QString mailtoLink = QString("mailto:%1?subject=%2&body=%3")
                                      .arg(email)
                                      .arg(QUrl::toPercentEncoding(sujet))
                                      .arg(QUrl::toPercentEncoding(message));

             if (QDesktopServices::openUrl(QUrl(mailtoLink))) {
                 return true;
             } else {
                 QMessageBox::warning(nullptr, "Erreur", "Impossible d'ouvrir le client de messagerie.");
                 return false;
             }
         } else {
             QMessageBox::warning(nullptr, "Erreur", "Client introuvable.");
             return false;
         }
     } else {
         QMessageBox::warning(nullptr, "Erreur", "Erreur lors de l'exécution de la requête.");
         return false;
     }
 }
