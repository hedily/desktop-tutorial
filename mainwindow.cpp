#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QGraphicsScene>
#include <QSqlQuery>
#include <QFileDialog>
#include <QRegularExpression>
#include <QDate>
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), clientManager(), clientModel(new QSqlQueryModel()), selectedClient(nullptr) {
    ui->setupUi(this);
    ui->tableView->setModel(client.afficher());



    updateTable();
}

MainWindow::~MainWindow() {
    delete ui;
    delete clientModel;
}
void MainWindow::on_valider_clicked()
{
    if (ui->id_client->text().isEmpty() || ui->nom->text().isEmpty() ||
        ui->prenom->text().isEmpty() || ui->telephone->text().isEmpty() ||
        ui->email->text().isEmpty() || ui->adresse->text().isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Champs vides"), QObject::tr("Veuillez remplir tous les champs."));
        return;
    }

    bool ok;
    int id_client = ui->id_client->text().toInt(&ok);
    if (!ok || id_client <= 0) {
        QMessageBox::warning(this, QObject::tr("Erreur d'ID"), QObject::tr("L'ID doit être un nombre entier positif."));
        return;
    }

    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();

    // Vérifier si nom et prénom contiennent uniquement des lettres
    QRegularExpression nameRegex("^[A-Za-zÀ-ÿ]+$");
    if (!nameRegex.match(nom).hasMatch()) {
        QMessageBox::warning(this, QObject::tr("Erreur de nom"), QObject::tr("Le nom doit être une chaîne de caractères alphabétiques."));
        return;
    }
    if (!nameRegex.match(prenom).hasMatch()) {
        QMessageBox::warning(this, QObject::tr("Erreur de prénom"), QObject::tr("Le prénom doit être une chaîne de caractères alphabétiques."));
        return;
    }

    QString telephoneStr = ui->telephone->text();
    if (telephoneStr.length() != 8 || !telephoneStr.toUInt(&ok) || !ok) {
        QMessageBox::warning(this, QObject::tr("Erreur de téléphone"), QObject::tr("Le téléphone doit être composé de 8 chiffres."));
        return;
    }
    int telephone = telephoneStr.toInt();

    QString email = ui->email->text();
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.com$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, QObject::tr("Erreur d'email"), QObject::tr("L'email doit être au format nom.prenom@gmail.com."));
        return;
    }

    QString adresse = ui->adresse->text();
    // Vous pouvez ajouter une vérification supplémentaire si vous le souhaitez pour l'adresse, mais ici on part du principe qu'elle est valide.

    Client newClient(id_client, nom, prenom, telephone, email, adresse);
    if (newClient.ajouter()) {
        QMessageBox::information(this, QObject::tr("Ajout Réussi"), QObject::tr("L'ajout du client a été effectué avec succès."));
    } else {
        QMessageBox::critical(this, QObject::tr("Ajout Échoué"), QObject::tr("L'ajout du client a échoué."));
    }
    updateTable();
}

void MainWindow::on_annuler_clicked()
{
    ui->id_client->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->telephone->clear();
    ui->email->clear();
    ui->adresse->clear();
}

void MainWindow::on_supprimer_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Aucune sélection"), QObject::tr("Veuillez sélectionner un client dans la table."));
        return;
    }

    int row = selectedIndexes.first().row();
    int id_client = clientModel->data(clientModel->index(row, 0)).toInt(); // Supposons que l'ID est dans la première colonne

    if (clientManager.supprimer(id_client)) {
        QMessageBox::information(this, QObject::tr("Suppression Réussie"), QObject::tr("La suppression du client a été effectuée avec succès."));
    } else {
        QMessageBox::critical(this, QObject::tr("Suppression Échouée"), QObject::tr("La suppression du client a échoué."));
    }

    updateTable();
}



void MainWindow::on_afficher_clicked() {
    updateTable();
}


void MainWindow::updateTable() {
    delete clientModel;
    clientModel = clientManager.afficher();
    if (clientModel) {
        ui->tableView->setModel(clientModel);
    }
}


Client* MainWindow::getSelectedClient() {
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (!selectedIndexes.isEmpty()) {
        int row = selectedIndexes.first().row();
        int id_client = clientModel->data(clientModel->index(row, 0)).toInt();
        QString nom = clientModel->data(clientModel->index(row, 1)).toString();
        QString prenom = clientModel->data(clientModel->index(row, 2)).toString();
        QString adresse = clientModel->data(clientModel->index(row, 5)).toString(); // Adresse ici
        QString email = clientModel->data(clientModel->index(row, 4)).toString(); // Email ici
        int telephone = clientModel->data(clientModel->index(row, 3)).toInt(); // Téléphone ici

        return new Client(id_client, nom, prenom, telephone, email, adresse);
    }
    return nullptr;
}

void MainWindow::updateClient(Client* client) {
    if (!client) {
        QMessageBox::warning(this, QObject::tr("Erreur"), QObject::tr("Client invalide. Aucune mise à jour effectuée."));
        return;
    }

    // Récupérer les nouvelles informations à partir des champs de saisie
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    int telephone = ui->telephone->text().toInt();
    QString email = ui->email->text();
    QString adresse = ui->adresse->text();

    // Mettre à jour le client existant
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE client SET nom = :nom, prenom = :prenom, telephone = :telephone, email = :email, adresse = :adresse WHERE id_client = :id_client");
    updateQuery.bindValue(":nom", nom);
    updateQuery.bindValue(":prenom", prenom);
    updateQuery.bindValue(":telephone", telephone);
    updateQuery.bindValue(":email", email);
    updateQuery.bindValue(":adresse", adresse);
    updateQuery.bindValue(":id_client", client->getIdClient());

    if (!updateQuery.exec()) {
        qDebug() << "Erreur lors de la mise à jour du client:" << updateQuery.lastError().text();
        QMessageBox::critical(this, QObject::tr("Erreur de mise à jour"), QObject::tr("La mise à jour du client a échoué."));
        return; // Sortir si la mise à jour échoue
    }

    // Supprimé le message d'information
    // QMessageBox::information(this, QObject::tr("Mise à jour réussie"), QObject::tr("Le client a été mis à jour avec succès."));
}




void MainWindow::on_modifier_clicked()
{
    selectedClient = getSelectedClient();
    if (!selectedClient) {
        QMessageBox::warning(this, QObject::tr("Aucun client sélectionné"), QObject::tr("Veuillez sélectionner un client dans la table."));
        return;
    }

    // Affichez les détails du client sélectionné
    displayClientDetails(selectedClient);

    // Mettre à jour le client
    updateClient(selectedClient);

    // Suppression de l'ancien client
    int idClientToDelete = selectedClient->getIdClient(); // ID du client à supprimer
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM client WHERE id_client = :id_client");
    deleteQuery.bindValue(":id_client", idClientToDelete);

    if (!deleteQuery.exec()) {
        qDebug() << "Erreur lors de la suppression du client:" << deleteQuery.lastError().text();
        QMessageBox::critical(this, QObject::tr("Erreur de suppression"), QObject::tr("La suppression du client a échoué."));
    }

    // Mettre à jour la table après la modification
    updateTable(); // Actualiser la table après la mise à jour
}
void MainWindow::displayClientDetails(Client *client) {
    if (client) {
        ui->id_client->setText(QString::number(client->getIdClient()));
        ui->nom->setText(client->getNom());
        ui->prenom->setText(client->getPrenom());
        ui->adresse->setText(client->getAdresse()); // Adresse ici
        ui->email->setText(client->getEmail()); // Email ici
        ui->telephone->setText(QString::number(client->getTelephone())); // Téléphone ici
    }
}


void MainWindow::on_trier_2_clicked()
{
    QString critere = ui->comboBox->currentText().toLower();

    // Récupérez et ajustez le critère de tri
    if (critere == "id") {
        critere = "id_client";
    } else if (critere == "prenom") {
        critere = "prenom";
    } else if (critere == "nom") {
        critere = "nom";
    }

    bool ascendant = true;  // Optionnel : Ajouter une logique pour gérer l'ordre de tri
    QSqlQueryModel* model = client.trier(critere, ascendant);
    ui->tableView->setModel(model);
}


void MainWindow::on_rechercher_clicked()
{
    QString valeur = ui->recherche->text(); // Récupération de la valeur saisie

    QSqlQueryModel* model = client.rechercher(valeur);
    ui->tableView->setModel(model);
}


void MainWindow::on_exporter_clicked()
{
    Client client;
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");

    if (filePath.isEmpty()) {
        return; // L'utilisateur a annulé la boîte de dialogue
    }

    bool success = client.genererPDF(filePath);
    QMessageBox msgBox;
    if (success) {
        msgBox.setText("PDF généré avec succès.");
    } else {
        msgBox.setText("Échec de la génération du PDF.");
    }
    msgBox.exec();
}

