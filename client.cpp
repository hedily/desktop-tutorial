#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include<QSqlQueryModel>
#include<QObject>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QFile>
#include <QTextDocument>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QPieSeries>
#include <utility> // pour std::move


Client::Client() {}

Client::Client(int id_client, const QString& nom, const QString& prenom,int telephone, const QString& email, const QString& adresse)
    : id_client(id_client), nom(nom), prenom(prenom), email(email), telephone(telephone), adresse(adresse) {}

bool Client::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO client (id_client, nom, prenom, telephone, email, adresse) VALUES (:id_client, :nom, :prenom, :telephone, :email, :adresse)");

    query.bindValue(":id_client", id_client);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du client:" << query.lastError().text();
        return false;
    }

    return true;
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
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));

    return model;
}

bool Client::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE id_client = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }
    return true;
}
bool Client::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE client SET nom = :nom, prenom = :prenom, telephone = :telephone, email = :email, adresse = :adresse WHERE id_client = :id_client");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":id_client", id_client); // Utilisation de l'ID du client actuel

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
        // Recherche par ID (si la valeur est un entier positif)
        queryString = "SELECT * FROM client WHERE id_client = :valeur";
    } else {
        // Recherche par nom ou prenom
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

bool Client::genererPDF(const QString &filePath) {
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);

    QPainter painter(&writer);
    if (!painter.isActive()) {
        qDebug() << "Failed to initialize painter.";
        return false;
    }

    // Define table parameters
    const int headerHeight = 60;
    const int rowHeight = 60;
    const int columnWidth = writer.width() / 6;
    const int tableTop = 100;
    const int tableLeft = 40;
    const QStringList headers = {"ID", "Nom","Prenom",  "Téléphone", "Email","Adresse"};

    // Draw table headers with a thicker border
    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawRect(tableLeft + i * columnWidth, tableTop, columnWidth, headerHeight);
        painter.drawText(tableLeft + i * columnWidth + 10, tableTop + 35, headers[i]);
    }

    // Draw table rows with standard border
    pen.setWidth(1);
    painter.setPen(pen);
    painter.setFont(QFont("Arial", 10));
    int y = tableTop + headerHeight;
    QSqlQuery query;
    query.prepare("SELECT * FROM client");

    if (!query.exec()) {
        qDebug() << "Error fetching archives for PDF:" << query.lastError().text();
        return false;
    }

    while (query.next()) {
        for (int i = 0; i < headers.size(); ++i) {
            painter.drawRect(tableLeft + i * columnWidth, y, columnWidth, rowHeight);
            painter.drawText(tableLeft + i * columnWidth + 10, y + 25, query.value(i).toString());
        }
        y += rowHeight;
    }

    painter.end();
    return true;
}
