#include <QPrinter>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>
#include <QLayoutItem>
#include <QLayout>
#include <QImage>
#include <QPainter>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegularExpression>
#include <QFileDialog>
#include <QDate>
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QStandardItemModel>
#include <QCoreApplication>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
using namespace qrcodegen;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), clientModel(new QSqlQueryModel()), selectedClient(nullptr) {
    ui->setupUi(this);
    updateTable();
connect(ui->updateNotifications, &QPushButton::clicked, this, &MainWindow::on_pushButtonAfficher_clicked);
    connect(ui->statistique, &QPushButton::clicked, this, &MainWindow::afficherStatistiques);
    connect(ui->statistique, &QPushButton::clicked, this, &MainWindow::afficherStatistiquesGraphiqueBarres);
connect(ui->button_mail, &QPushButton::clicked, this, &MainWindow::on_button_mail_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
    delete clientModel;
}

void MainWindow::on_valider_clicked() {
    QString id_client = ui->id_client->text();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString adresse = ui->adresse->text();
    QString genre = ui->genre->text();
    QString email = ui->email->text();
    QString dn = ui->dn->text();
    int pt_fidelite = ui->pt_fidelite->text().toInt();
    bool ok;
    int telephone = ui->telephone->text().toInt(&ok);

    if (id_client.isEmpty() || !id_client.contains(QRegularExpression("^[a-zA-Z0-9]+$"))) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("L'ID client doit être non nul et alphanumérique."));
        return;
    }
    if (nom.isEmpty() || !nom.contains(QRegularExpression("^[a-zA-Z]+$"))) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le nom doit être non nul et alphabétique."));
        return;
    }
    if (prenom.isEmpty() || !prenom.contains(QRegularExpression("^[a-zA-Z]+$"))) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le prénom doit être non nul et alphabétique."));
        return;
    }
    if (adresse.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("L'adresse ne doit pas être vide."));
        return;
    }
    if (!ok || ui->telephone->text().length() != 8 || !ui->telephone->text().contains(QRegularExpression("^[0-9]{8}$"))) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le numéro de téléphone doit être un nombre de 8 chiffres."));
        return;
    }
    if (genre.isEmpty() || (genre.toLower() != "femme" && genre.toLower() != "homme")) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le genre doit être 'femme' ou 'homme'."));
        return;
    }

    if (pt_fidelite < 0) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Les points de fidélité doivent être un entier positif."));
        return;
    }

    Client clientManager(id_client, nom, prenom, adresse, telephone, genre, email, dn, pt_fidelite);
    bool test = clientManager.ajouter();
    if (test) {
        QMessageBox::information(this, QObject::tr("Ajout Réussi"), QObject::tr("L'ajout du client a été effectué avec succès."));
        updateTable();
    } else {
        QMessageBox::critical(this, QObject::tr("Ajout Échoué"), QObject::tr("L'ajout du client a échoué."));
    }
}

void MainWindow::on_annuler_clicked() {
    ui->id_client->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->adresse->clear();
    ui->email->clear();
    ui->telephone->clear();
    ui->genre->clear();
    ui->dn->clear();
    ui->pt_fidelite->clear();
}

void MainWindow::on_supprimer_clicked() {
    QModelIndexList selectedIndexes = ui->tableView_afficher->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Aucune sélection"), QObject::tr("Veuillez sélectionner un client dans la table."));
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        QObject::tr("Confirmation"),
        QObject::tr("Êtes-vous sûr de vouloir supprimer ce client ?"),
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::No) {
        return;
    }

    int row = selectedIndexes.first().row();
    QString id_client = clientModel->data(clientModel->index(row, 0)).toString();

    if (id_client.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Erreur"), QObject::tr("L'ID du client est vide."));
        return;
    }


    if (clientManager.supprimer(id_client)) {
        QMessageBox::information(this, QObject::tr("Suppression Réussie"), QObject::tr("La suppression du client a été effectuée avec succès."));
    } else {
        QMessageBox::critical(this, QObject::tr("Suppression Échouée"), QObject::tr("La suppression du client a échoué. Vérifiez les logs pour plus de détails."));
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
        ui->tableView_afficher->setModel(clientModel);
    } else {
        qDebug() << "Erreur lors de la récupération des données du client.";
    }
}

Client* MainWindow::getSelectedClient() {
    QModelIndexList selectedIndexes = ui->tableView_afficher->selectionModel()->selectedRows();
    if (!selectedIndexes.isEmpty()) {
        int row = selectedIndexes.first().row();
        QString id_client = clientModel->data(clientModel->index(row, 0)).toString();
        QString nom = clientModel->data(clientModel->index(row, 1)).toString();
        QString prenom = clientModel->data(clientModel->index(row, 2)).toString();
        QString adresse = clientModel->data(clientModel->index(row, 3)).toString();
        int telephone = clientModel->data(clientModel->index(row, 4)).toInt();
        QString genre = clientModel->data(clientModel->index(row, 5)).toString();
        QString email = clientModel->data(clientModel->index(row, 6)).toString();
        QString dn = clientModel->data(clientModel->index(row, 7)).toString();
        int pt_fidelite = clientModel->data(clientModel->index(row, 8)).toInt();

        return new Client(id_client, nom, prenom, adresse, telephone, genre, email, dn, pt_fidelite);
    }
    return nullptr;
}

void MainWindow::updateClient(Client* client) {

}

void MainWindow::on_modifier_clicked()
{
    selectedClient = getSelectedClient();
    if (!selectedClient) {
        QMessageBox::warning(this, QObject::tr("Aucun client sélectionné"), QObject::tr("Veuillez sélectionner un client dans la table."));
        return;
    }

    displayClientDetails(selectedClient);

    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString adresse = ui->adresse->text();
    int telephone = ui->telephone->text().toInt();
    QString genre = ui->genre->text();
    QString email = ui->email->text();
    QString dn = ui->dn->text();
    int pt_fidelite = ui->pt_fidelite->text().toInt();

    bool test = clientManager.modifier(selectedClient->getIdClient(), nom, prenom, adresse, telephone, genre, email, dn, pt_fidelite);

    if (test) {
        QMessageBox::information(this, QObject::tr("Modification réussie"), QObject::tr("Le client a été modifié avec succès."));
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur de modification"), QObject::tr("La modification du client a échoué."));
    }

    updateTable();
}
void MainWindow::displayClientDetails(Client* client) {
    if (client) {
        ui->id_client->setText(client->getIdClient());
        ui->nom->setText(client->getNom());
        ui->prenom->setText(client->getPrenom());
        ui->adresse->setText(client->getAdresse());
        ui->telephone->setText(QString::number(client->getTelephone()));
        ui->genre->setText(client->getGenre());
        ui->email->setText(client->getEmail());
        ui->dn->setText(client->getDateNaissance());
        ui->pt_fidelite->setText(QString::number(client->getPointsFidelite()));
    }
}

void MainWindow::on_trier_2_clicked() {
    QString critere = ui->comboBox->currentText().toLower();
    if (critere == "point de fidelite") {
        critere = "pt_fidelite";
    } else if (critere == "prenom") {
        critere = "prenom";
    } else if (critere == "nom") {
        critere = "nom";
    }

    bool ascendant = true;
    QSqlQueryModel* model = clientManager.trier(critere, ascendant);
    ui->tableView_afficher->setModel(model);
}

void MainWindow::on_rechercher_clicked() {
    QString valeur = ui->recherche->text();
    QSqlQueryModel* model = clientManager.rechercher(valeur);
    ui->tableView_afficher->setModel(model);
}

void MainWindow::on_exporter_clicked() {

       QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer sous", "", "Fichiers PDF (*.pdf)");

       if (fileName.isEmpty()) {
           return;
       }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setOutputFileName(fileName);
       printer.setPageOrientation(QPageLayout::Landscape);
       printer.setPageSize(QPageSize(QPageSize::A4));

       QPainter painter;
       if (!painter.begin(&printer)) {
           QMessageBox::warning(this, "Erreur", "Impossible de créer le fichier PDF.");
           return;
       }


       QAbstractItemModel *model = ui->tableView_afficher->model();
       if (!model) {
           QMessageBox::warning(this, "Erreur", "Le modèle de données est invalide.");
           return;
       }


       QRect printableArea = printer.pageLayout().paintRectPixels(printer.resolution());
       int margin = 20;
       int x = margin;
       int y = margin;
       int pageWidth = printableArea.width() - 2 * margin;
       int pageHeight = printableArea.height() - 2 * margin;
       int cellHeight = 40;
       int columnCount = model->columnCount();
       int cellWidth = pageWidth / columnCount;


       painter.setFont(QFont("Arial", 14, QFont::Bold));
       painter.drawText(x, y, "Exportation des données des employés");
       y += 50;

       painter.setFont(QFont("Arial", 10, QFont::Bold));
       painter.setPen(Qt::black);
       for (int col = 0; col < columnCount; ++col) {
           QString header = model->headerData(col, Qt::Horizontal).toString();
           painter.drawRect(x + col * cellWidth, y, cellWidth, cellHeight);
           painter.drawText(x + col * cellWidth + 5, y + 5, cellWidth - 10, cellHeight - 10, Qt::AlignCenter, header);
       }
       y += cellHeight;

       painter.setFont(QFont("Arial", 9));
       for (int row = 0; row < model->rowCount(); ++row) {
           if (y + cellHeight > pageHeight) {
               printer.newPage();
               y = margin;

               for (int col = 0; col < columnCount; ++col) {
                   QString header = model->headerData(col, Qt::Horizontal).toString();
                   painter.drawRect(x + col * cellWidth, y, cellWidth, cellHeight);
                   painter.drawText(x + col * cellWidth + 5, y + 5, cellWidth - 10, cellHeight - 10, Qt::AlignCenter, header);
               }
               y += cellHeight;
           }

           for (int col = 0; col < columnCount; ++col) {
               QString data = model->data(model->index(row, col)).toString();
               painter.drawRect(x + col * cellWidth, y, cellWidth, cellHeight);
               painter.drawText(x + col * cellWidth + 5, y + 5, cellWidth - 10, cellHeight - 10, Qt::AlignCenter, data);
           }
           y += cellHeight;
       }

       painter.end();

       QMessageBox::information(this, "Exportation", "Les données ont été exportées vers un fichier PDF avec succès.");
   }






void MainWindow::afficherStatistiques() {
    QMap<QString, int> statistiques = clientManager.obtenirStatistiquesParAdresse();
    QString result;
    for (auto it = statistiques.cbegin(); it != statistiques.cend(); ++it) {
        result += QString("%1 : %2\n").arg(it.key()).arg(it.value());
    }

    QMessageBox::information(this, "Statistiques par Adresse", result);
}

void MainWindow::afficherStatistiquesGraphiqueBarres() {
    QMap<QString, int> statistiques = clientManager.obtenirStatistiquesParAdresse();

    if (statistiques.isEmpty()) {
        QMessageBox::information(this, "Statistiques", "Aucune donnée à afficher.");
        return;
    }


    QBarSet *set = new QBarSet("Nombre de clients");


    for (auto it = statistiques.cbegin(); it != statistiques.cend(); ++it) {
        *set << it.value();
    }


    QBarSeries *series = new QBarSeries();
    series->append(set);


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des Clients par Adresse");
    chart->setAnimationOptions(QChart::SeriesAnimations);


    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(statistiques.keys());
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);


    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de Clients");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    chartView->setMinimumSize(800, 600);
    chartView->setMaximumSize(1200, 800);

    QFont font = chart->titleFont();
    font.setPointSize(16);
    chart->setTitleFont(font);

    foreach (QAbstractAxis *axis, chart->axes()) {
        axis->setTitleFont(font);
        axis->setLabelsFont(font);
    }

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addWidget(chartView);
    ui->stat_view->setScene(scene);
    ui->stat_view->setRenderHint(QPainter::Antialiasing);
}
void MainWindow::on_update_clicked()
{
    QString id_client = ui->id_client->text();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString adresse = ui->adresse->text();


    int telephone = ui->telephone->text().toInt();

    QString genre = ui->genre->text();
    QString email = ui->email->text();
    QString dn = ui->dn->text();
    int pt_fidelite = ui->pt_fidelite->text().toInt();

    Client clientManager(id_client, nom, prenom, adresse, telephone, genre, email, dn, pt_fidelite);
   bool test =  clientManager.modifier(id_client, nom, prenom, adresse, telephone,genre,email,dn, pt_fidelite) ;

 if (test) {
        QMessageBox::information(this, QObject::tr("update Réussi"), QObject::tr("L'update du client a été effectué avec succès."));
        updateTable();
    } else {
        QMessageBox::critical(this, QObject::tr("update Échoué"), QObject::tr("L'ajout du client a échoué."));
    }
}
void MainWindow::genererStatistiquesParGenre()
{
    QSqlQuery query;
    query.prepare("SELECT genre, COUNT(*) AS nombre_clients FROM CLIENT GROUP BY genre");

    if (query.exec()) {

        QPieSeries *series = new QPieSeries();


        while (query.next()) {
            QString genre = query.value("genre").toString();
            int nombreClients = query.value("nombre_clients").toInt();


            QPieSlice *slice = series->append(genre + ": " + QString::number(nombreClients), nombreClients);
            slice->setLabelVisible(true);
            slice->setLabelPosition(QPieSlice::LabelOutside);
            slice->setBrush(QColor::fromHsv(rand() % 256, 200, 255));
        }


        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques par Genre des Clients");
        chart->setAnimationOptions(QChart::SeriesAnimations);


        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);


        QLayout *layout = ui->stackedWidget_stat->layout();
        if (layout) {
            QLayoutItem *item;
            while ((item = layout->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }
            layout->addWidget(chartView);
        }

        ui->stackedWidget_stat->show();
    } else {
        qDebug() << "Erreur de requête : " << query.lastError();
    }
}



void MainWindow::on_pushButtonAfficher_clicked() {
    Client clientManager;
    QList<Client> anniversaires = clientManager.getAnniversairesProches();


    QStandardItemModel *model = new QStandardItemModel();


    model->setHorizontalHeaderLabels(QStringList() << "ID" << "Nom" << "Prénom" << "Téléphone" << "Email" << "Adresse");

    for (const Client& client : anniversaires) {
        QList<QStandardItem *> rowItems;
        rowItems << new QStandardItem(client.getIdClient())
                 << new QStandardItem(client.getNom())
                 << new QStandardItem(client.getPrenom())
                 << new QStandardItem(QString::number(client.getTelephone()))
                 << new QStandardItem(client.getGenre())
                 << new QStandardItem(client.getAdresse());

        model->appendRow(rowItems);
    }


    ui->notification->setModel(model);
}


void MainWindow::on_button_mail_clicked() {

    QModelIndexList selectedIndexes = ui->notification->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un client.");
        return;
    }

    QModelIndex index = selectedIndexes.first();
    QString id_client = ui->notification->model()->data(ui->notification->model()->index(index.row(), 0)).toString();
    QString sujet = "Sujet prédéfini";
    QString message = "Félicitations ! 🎉 Nous sommes ravis de vous informer que vous avez bénéficié d'une réduction exceptionnelle sur votre prochain achat. Profitez de cette opportunité pour vous offrir ce que vous désirez à un prix réduit ! Merci de votre fidélité et bonne shopping !";


    if (!clientManager.envoyerEmail(id_client, sujet, message)) {
        QMessageBox::warning(this, "Erreur", "Échec de l'envoi de l'email.");
    }
}

void MainWindow::on_QR_button_clicked()
{
    if (!ui->tableView_afficher->currentIndex().isValid()) {
        QMessageBox::warning(this, QObject::tr("Erreur"), QObject::tr("Veuillez sélectionner un client."));
        return;
    }

    QStringList clientDetails;
    for (int col = 0; col < 7; ++col) {
        clientDetails << ui->tableView_afficher->model()->data(ui->tableView_afficher->model()->index(ui->tableView_afficher->currentIndex().row(), col)).toString();
    }

    QString text = "client details: " + clientDetails.join(" ");

    using namespace qrcodegen;

    QrCode qr = QrCode::encodeText(text.toUtf8().data(), QrCode::Ecc::MEDIUM);
    qint32 sz = qr.getSize();

    QImage im(sz, sz, QImage::Format_RGB32);
    QRgb black = qRgb(0, 0, 0);
    QRgb white = qRgb(255, 255, 255);

    for (int y = 0; y < sz; y++) {
        for (int x = 0; x < sz; x++) {
            im.setPixel(x, y, qr.getModule(x, y) ? black : white);
        }
    }

    ui->qr_code->setPixmap(QPixmap::fromImage(im.scaled(256, 256, Qt::KeepAspectRatio, Qt::FastTransformation), Qt::MonoOnly));
}


void MainWindow::on_stat_genre_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT genre, COUNT(*) AS nombre_clients FROM CLIENT GROUP BY genre");

    if (query.exec()) {
        QPieSeries *series = new QPieSeries();

        while (query.next()) {
            QString genre = query.value("genre").toString();
            int nombreClients = query.value("nombre_clients").toInt();

            QPieSlice *slice = series->append(genre + ": " + QString::number(nombreClients), nombreClients);
            slice->setLabelVisible(true);
            slice->setLabelPosition(QPieSlice::LabelOutside);
            slice->setBrush(QColor::fromHsv(rand() % 256, 200, 255));
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques par Genre des Clients");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QLayout *layout = ui->stackedWidget_stat->layout();
        if (layout) {
            QLayoutItem *item;
            while ((item = layout->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }
            layout->addWidget(chartView);
        }

        ui->stackedWidget_stat->show();
    } else {
        qDebug() << "Erreur de requête : " << query.lastError();
    }
}


























/////////////////////////////////////////////////
/*
 * QR Code generator library (C++)
 *
 * Copyright (c) Project Nayuki. (MIT License)
 * https://www.nayuki.io/page/qr-code-generator-library
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * - The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * - The Software is provided "as is", without warranty of any kind, express or
 *   implied, including but not limited to the warranties of merchantability,
 *   fitness for a particular purpose and noninfringement. In no event shall the
 *   authors or copyright holders be liable for any claim, damages or other
 *   liability, whether in an action of contract, tort or otherwise, arising from,
 *   out of or in connection with the Software or the use or other dealings in the
 *   Software.
 */

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
//#include "qrcodegen.hpp"

using std::int8_t;
using std::uint8_t;
using std::size_t;
using std::vector;


namespace qrcodegen {

/*---- Class QrSegment ----*/

QrSegment::Mode::Mode(int mode, int cc0, int cc1, int cc2) :
    modeBits(mode) {
    numBitsCharCount[0] = cc0;
    numBitsCharCount[1] = cc1;
    numBitsCharCount[2] = cc2;
}


int QrSegment::Mode::getModeBits() const {
    return modeBits;
}


int QrSegment::Mode::numCharCountBits(int ver) const {
    return numBitsCharCount[(ver + 7) / 17];
}


const QrSegment::Mode QrSegment::Mode::NUMERIC     (0x1, 10, 12, 14);
const QrSegment::Mode QrSegment::Mode::ALPHANUMERIC(0x2,  9, 11, 13);
const QrSegment::Mode QrSegment::Mode::BYTE        (0x4,  8, 16, 16);
const QrSegment::Mode QrSegment::Mode::KANJI       (0x8,  8, 10, 12);
const QrSegment::Mode QrSegment::Mode::ECI         (0x7,  0,  0,  0);


QrSegment QrSegment::makeBytes(const vector<uint8_t> &data) {
    if (data.size() > static_cast<unsigned int>(INT_MAX))
        throw std::length_error("Data too long");
    BitBuffer bb;
    for (uint8_t b : data)
        bb.appendBits(b, 8);
    return QrSegment(Mode::BYTE, static_cast<int>(data.size()), std::move(bb));
}


QrSegment QrSegment::makeNumeric(const char *digits) {
    BitBuffer bb;
    int accumData = 0;
    int accumCount = 0;
    int charCount = 0;
    for (; *digits != '\0'; digits++, charCount++) {
        char c = *digits;
        if (c < '0' || c > '9')
            throw std::domain_error("String contains non-numeric characters");
        accumData = accumData * 10 + (c - '0');
        accumCount++;
        if (accumCount == 3) {
            bb.appendBits(static_cast<uint32_t>(accumData), 10);
            accumData = 0;
            accumCount = 0;
        }
    }
    if (accumCount > 0)  // 1 or 2 digits remaining
        bb.appendBits(static_cast<uint32_t>(accumData), accumCount * 3 + 1);
    return QrSegment(Mode::NUMERIC, charCount, std::move(bb));
}


QrSegment QrSegment::makeAlphanumeric(const char *text) {
    BitBuffer bb;
    int accumData = 0;
    int accumCount = 0;
    int charCount = 0;
    for (; *text != '\0'; text++, charCount++) {
        const char *temp = std::strchr(ALPHANUMERIC_CHARSET, *text);
        if (temp == nullptr)
            throw std::domain_error("String contains unencodable characters in alphanumeric mode");
        accumData = accumData * 45 + static_cast<int>(temp - ALPHANUMERIC_CHARSET);
        accumCount++;
        if (accumCount == 2) {
            bb.appendBits(static_cast<uint32_t>(accumData), 11);
            accumData = 0;
            accumCount = 0;
        }
    }
    if (accumCount > 0)  // 1 character remaining
        bb.appendBits(static_cast<uint32_t>(accumData), 6);
    return QrSegment(Mode::ALPHANUMERIC, charCount, std::move(bb));
}


vector<QrSegment> QrSegment::makeSegments(const char *text) {
    // Select the most efficient segment encoding automatically
    vector<QrSegment> result;
    if (*text == '\0');  // Leave result empty
    else if (isNumeric(text))
        result.push_back(makeNumeric(text));
    else if (isAlphanumeric(text))
        result.push_back(makeAlphanumeric(text));
    else {
        vector<uint8_t> bytes;
        for (; *text != '\0'; text++)
            bytes.push_back(static_cast<uint8_t>(*text));
        result.push_back(makeBytes(bytes));
    }
    return result;
}


QrSegment QrSegment::makeEci(long assignVal) {
    BitBuffer bb;
    if (assignVal < 0)
        throw std::domain_error("ECI assignment value out of range");
    else if (assignVal < (1 << 7))
        bb.appendBits(static_cast<uint32_t>(assignVal), 8);
    else if (assignVal < (1 << 14)) {
        bb.appendBits(2, 2);
        bb.appendBits(static_cast<uint32_t>(assignVal), 14);
    } else if (assignVal < 1000000L) {
        bb.appendBits(6, 3);
        bb.appendBits(static_cast<uint32_t>(assignVal), 21);
    } else
        throw std::domain_error("ECI assignment value out of range");
    return QrSegment(Mode::ECI, 0, std::move(bb));
}


QrSegment::QrSegment(const Mode &md, int numCh, const std::vector<bool> &dt) :
    mode(&md),
    numChars(numCh),
    data(dt) {
    if (numCh < 0)
        throw std::domain_error("Invalid value");
}


QrSegment::QrSegment(const Mode &md, int numCh, std::vector<bool> &&dt) :
    mode(&md),
    numChars(numCh),
    data(std::move(dt)) {
    if (numCh < 0)
        throw std::domain_error("Invalid value");
}


int QrSegment::getTotalBits(const vector<QrSegment> &segs, int version) {
    int result = 0;
    for (const QrSegment &seg : segs) {
        int ccbits = seg.mode->numCharCountBits(version);
        if (seg.numChars >= (1L << ccbits))
            return -1;  // The segment's length doesn't fit the field's bit width
        if (4 + ccbits > INT_MAX - result)
            return -1;  // The sum will overflow an int type
        result += 4 + ccbits;
        if (seg.data.size() > static_cast<unsigned int>(INT_MAX - result))
            return -1;  // The sum will overflow an int type
        result += static_cast<int>(seg.data.size());
    }
    return result;
}


bool QrSegment::isNumeric(const char *text) {
    for (; *text != '\0'; text++) {
        char c = *text;
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}


bool QrSegment::isAlphanumeric(const char *text) {
    for (; *text != '\0'; text++) {
        if (std::strchr(ALPHANUMERIC_CHARSET, *text) == nullptr)
            return false;
    }
    return true;
}


const QrSegment::Mode &QrSegment::getMode() const {
    return *mode;
}


int QrSegment::getNumChars() const {
    return numChars;
}


const std::vector<bool> &QrSegment::getData() const {
    return data;
}


const char *QrSegment::ALPHANUMERIC_CHARSET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";



/*---- Class QrCode ----*/

int QrCode::getFormatBits(Ecc ecl) {
    switch (ecl) {
    case Ecc::LOW     :  return 1;
    case Ecc::MEDIUM  :  return 0;
    case Ecc::QUARTILE:  return 3;
    case Ecc::HIGH    :  return 2;
    default:  throw std::logic_error("Unreachable");
    }
}


QrCode QrCode::encodeText(const char *text, Ecc ecl) {
    vector<QrSegment> segs = QrSegment::makeSegments(text);
    return encodeSegments(segs, ecl);
}


QrCode QrCode::encodeBinary(const vector<uint8_t> &data, Ecc ecl) {
    vector<QrSegment> segs{QrSegment::makeBytes(data)};
    return encodeSegments(segs, ecl);
}


QrCode QrCode::encodeSegments(const vector<QrSegment> &segs, Ecc ecl,
                              int minVersion, int maxVersion, int mask, bool boostEcl) {
    if (!(MIN_VERSION <= minVersion && minVersion <= maxVersion && maxVersion <= MAX_VERSION) || mask < -1 || mask > 7)
        throw std::invalid_argument("Invalid value");

    // Find the minimal version number to use
    int version, dataUsedBits;
    for (version = minVersion; ; version++) {
        int dataCapacityBits = getNumDataCodewords(version, ecl) * 8;  // Number of data bits available
        dataUsedBits = QrSegment::getTotalBits(segs, version);
        if (dataUsedBits != -1 && dataUsedBits <= dataCapacityBits)
            break;  // This version number is found to be suitable
        if (version >= maxVersion) {  // All versions in the range could not fit the given data
            std::ostringstream sb;
            if (dataUsedBits == -1)
                sb << "Segment too long";
            else {
                sb << "Data length = " << dataUsedBits << " bits, ";
                sb << "Max capacity = " << dataCapacityBits << " bits";
            }
            throw data_too_long(sb.str());
        }
    }
    assert(dataUsedBits != -1);

    // Increase the error correction level while the data still fits in the current version number
    for (Ecc newEcl : {Ecc::MEDIUM, Ecc::QUARTILE, Ecc::HIGH}) {  // From low to high
        if (boostEcl && dataUsedBits <= getNumDataCodewords(version, newEcl) * 8)
            ecl = newEcl;
    }

    // Concatenate all segments to create the data bit string
    BitBuffer bb;
    for (const QrSegment &seg : segs) {
        bb.appendBits(static_cast<uint32_t>(seg.getMode().getModeBits()), 4);
        bb.appendBits(static_cast<uint32_t>(seg.getNumChars()), seg.getMode().numCharCountBits(version));
        bb.insert(bb.end(), seg.getData().begin(), seg.getData().end());
    }
    assert(bb.size() == static_cast<unsigned int>(dataUsedBits));

    // Add terminator and pad up to a byte if applicable
    size_t dataCapacityBits = static_cast<size_t>(getNumDataCodewords(version, ecl)) * 8;
    assert(bb.size() <= dataCapacityBits);
    bb.appendBits(0, std::min(4, static_cast<int>(dataCapacityBits - bb.size())));
    bb.appendBits(0, (8 - static_cast<int>(bb.size() % 8)) % 8);
    assert(bb.size() % 8 == 0);

    // Pad with alternating bytes until data capacity is reached
    for (uint8_t padByte = 0xEC; bb.size() < dataCapacityBits; padByte ^= 0xEC ^ 0x11)
        bb.appendBits(padByte, 8);

    // Pack bits into bytes in big endian
    vector<uint8_t> dataCodewords(bb.size() / 8);
    for (size_t i = 0; i < bb.size(); i++)
        dataCodewords.at(i >> 3) |= (bb.at(i) ? 1 : 0) << (7 - (i & 7));

    // Create the QR Code object
    return QrCode(version, ecl, dataCodewords, mask);
}


QrCode::QrCode(int ver, Ecc ecl, const vector<uint8_t> &dataCodewords, int msk) :
    // Initialize fields and check arguments
    version(ver),
    errorCorrectionLevel(ecl) {
    if (ver < MIN_VERSION || ver > MAX_VERSION)
        throw std::domain_error("Version value out of range");
    if (msk < -1 || msk > 7)
        throw std::domain_error("Mask value out of range");
    size = ver * 4 + 17;
    size_t sz = static_cast<size_t>(size);
    modules    = vector<vector<bool> >(sz, vector<bool>(sz));  // Initially all light
    isFunction = vector<vector<bool> >(sz, vector<bool>(sz));

    // Compute ECC, draw modules
    drawFunctionPatterns();
    const vector<uint8_t> allCodewords = addEccAndInterleave(dataCodewords);
    drawCodewords(allCodewords);

    // Do masking
    if (msk == -1) {  // Automatically choose best mask
        long minPenalty = LONG_MAX;
        for (int i = 0; i < 8; i++) {
            applyMask(i);
            drawFormatBits(i);
            long penalty = getPenaltyScore();
            if (penalty < minPenalty) {
                msk = i;
                minPenalty = penalty;
            }
            applyMask(i);  // Undoes the mask due to XOR
        }
    }
    assert(0 <= msk && msk <= 7);
    mask = msk;
    applyMask(msk);  // Apply the final choice of mask
    drawFormatBits(msk);  // Overwrite old format bits

    isFunction.clear();
    isFunction.shrink_to_fit();
}


int QrCode::getVersion() const {
    return version;
}


int QrCode::getSize() const {
    return size;
}


QrCode::Ecc QrCode::getErrorCorrectionLevel() const {
    return errorCorrectionLevel;
}


int QrCode::getMask() const {
    return mask;
}


bool QrCode::getModule(int x, int y) const {
    return 0 <= x && x < size && 0 <= y && y < size && module(x, y);
}


void QrCode::drawFunctionPatterns() {
    // Draw horizontal and vertical timing patterns
    for (int i = 0; i < size; i++) {
        setFunctionModule(6, i, i % 2 == 0);
        setFunctionModule(i, 6, i % 2 == 0);
    }

    // Draw 3 finder patterns (all corners except bottom right; overwrites some timing modules)
    drawFinderPattern(3, 3);
    drawFinderPattern(size - 4, 3);
    drawFinderPattern(3, size - 4);

    // Draw numerous alignment patterns
    const vector<int> alignPatPos = getAlignmentPatternPositions();
    size_t numAlign = alignPatPos.size();
    for (size_t i = 0; i < numAlign; i++) {
        for (size_t j = 0; j < numAlign; j++) {
            // Don't draw on the three finder corners
            if (!((i == 0 && j == 0) || (i == 0 && j == numAlign - 1) || (i == numAlign - 1 && j == 0)))
                drawAlignmentPattern(alignPatPos.at(i), alignPatPos.at(j));
        }
    }

    // Draw configuration data
    drawFormatBits(0);  // Dummy mask value; overwritten later in the constructor
    drawVersion();
}


void QrCode::drawFormatBits(int msk) {
    // Calculate error correction code and pack bits
    int data = getFormatBits(errorCorrectionLevel) << 3 | msk;  // errCorrLvl is uint2, msk is uint3
    int rem = data;
    for (int i = 0; i < 10; i++)
        rem = (rem << 1) ^ ((rem >> 9) * 0x537);
    int bits = (data << 10 | rem) ^ 0x5412;  // uint15
    assert(bits >> 15 == 0);

    // Draw first copy
    for (int i = 0; i <= 5; i++)
        setFunctionModule(8, i, getBit(bits, i));
    setFunctionModule(8, 7, getBit(bits, 6));
    setFunctionModule(8, 8, getBit(bits, 7));
    setFunctionModule(7, 8, getBit(bits, 8));
    for (int i = 9; i < 15; i++)
        setFunctionModule(14 - i, 8, getBit(bits, i));

    // Draw second copy
    for (int i = 0; i < 8; i++)
        setFunctionModule(size - 1 - i, 8, getBit(bits, i));
    for (int i = 8; i < 15; i++)
        setFunctionModule(8, size - 15 + i, getBit(bits, i));
    setFunctionModule(8, size - 8, true);  // Always dark
}


void QrCode::drawVersion() {
    if (version < 7)
        return;

    // Calculate error correction code and pack bits
    int rem = version;  // version is uint6, in the range [7, 40]
    for (int i = 0; i < 12; i++)
        rem = (rem << 1) ^ ((rem >> 11) * 0x1F25);
    long bits = static_cast<long>(version) << 12 | rem;  // uint18
    assert(bits >> 18 == 0);

    // Draw two copies
    for (int i = 0; i < 18; i++) {
        bool bit = getBit(bits, i);
        int a = size - 11 + i % 3;
        int b = i / 3;
        setFunctionModule(a, b, bit);
        setFunctionModule(b, a, bit);
    }
}


void QrCode::drawFinderPattern(int x, int y) {
    for (int dy = -4; dy <= 4; dy++) {
        for (int dx = -4; dx <= 4; dx++) {
            int dist = std::max(std::abs(dx), std::abs(dy));  // Chebyshev/infinity norm
            int xx = x + dx, yy = y + dy;
            if (0 <= xx && xx < size && 0 <= yy && yy < size)
                setFunctionModule(xx, yy, dist != 2 && dist != 4);
        }
    }
}


void QrCode::drawAlignmentPattern(int x, int y) {
    for (int dy = -2; dy <= 2; dy++) {
        for (int dx = -2; dx <= 2; dx++)
            setFunctionModule(x + dx, y + dy, std::max(std::abs(dx), std::abs(dy)) != 1);
    }
}


void QrCode::setFunctionModule(int x, int y, bool isDark) {
    size_t ux = static_cast<size_t>(x);
    size_t uy = static_cast<size_t>(y);
    modules   .at(uy).at(ux) = isDark;
    isFunction.at(uy).at(ux) = true;
}


bool QrCode::module(int x, int y) const {
    return modules.at(static_cast<size_t>(y)).at(static_cast<size_t>(x));
}


vector<uint8_t> QrCode::addEccAndInterleave(const vector<uint8_t> &data) const {
    if (data.size() != static_cast<unsigned int>(getNumDataCodewords(version, errorCorrectionLevel)))
        throw std::invalid_argument("Invalid argument");

    // Calculate parameter numbers
    int numBlocks = NUM_ERROR_CORRECTION_BLOCKS[static_cast<int>(errorCorrectionLevel)][version];
    int blockEccLen = ECC_CODEWORDS_PER_BLOCK  [static_cast<int>(errorCorrectionLevel)][version];
    int rawCodewords = getNumRawDataModules(version) / 8;
    int numShortBlocks = numBlocks - rawCodewords % numBlocks;
    int shortBlockLen = rawCodewords / numBlocks;

    // Split data into blocks and append ECC to each block
    vector<vector<uint8_t> > blocks;
    const vector<uint8_t> rsDiv = reedSolomonComputeDivisor(blockEccLen);
    for (int i = 0, k = 0; i < numBlocks; i++) {
        vector<uint8_t> dat(data.cbegin() + k, data.cbegin() + (k + shortBlockLen - blockEccLen + (i < numShortBlocks ? 0 : 1)));
        k += static_cast<int>(dat.size());
        const vector<uint8_t> ecc = reedSolomonComputeRemainder(dat, rsDiv);
        if (i < numShortBlocks)
            dat.push_back(0);
        dat.insert(dat.end(), ecc.cbegin(), ecc.cend());
        blocks.push_back(std::move(dat));
    }

    // Interleave (not concatenate) the bytes from every block into a single sequence
    vector<uint8_t> result;
    for (size_t i = 0; i < blocks.at(0).size(); i++) {
        for (size_t j = 0; j < blocks.size(); j++) {
            // Skip the padding byte in short blocks
            if (i != static_cast<unsigned int>(shortBlockLen - blockEccLen) || j >= static_cast<unsigned int>(numShortBlocks))
                result.push_back(blocks.at(j).at(i));
        }
    }
    assert(result.size() == static_cast<unsigned int>(rawCodewords));
    return result;
}


void QrCode::drawCodewords(const vector<uint8_t> &data) {
    if (data.size() != static_cast<unsigned int>(getNumRawDataModules(version) / 8))
        throw std::invalid_argument("Invalid argument");

    size_t i = 0;  // Bit index into the data
    // Do the funny zigzag scan
    for (int right = size - 1; right >= 1; right -= 2) {  // Index of right column in each column pair
        if (right == 6)
            right = 5;
        for (int vert = 0; vert < size; vert++) {  // Vertical counter
            for (int j = 0; j < 2; j++) {
                size_t x = static_cast<size_t>(right - j);  // Actual x coordinate
                bool upward = ((right + 1) & 2) == 0;
                size_t y = static_cast<size_t>(upward ? size - 1 - vert : vert);  // Actual y coordinate
                if (!isFunction.at(y).at(x) && i < data.size() * 8) {
                    modules.at(y).at(x) = getBit(data.at(i >> 3), 7 - static_cast<int>(i & 7));
                    i++;
                }
                // If this QR Code has any remainder bits (0 to 7), they were assigned as
                // 0/false/light by the constructor and are left unchanged by this method
            }
        }
    }
    assert(i == data.size() * 8);
}


void QrCode::applyMask(int msk) {
    if (msk < 0 || msk > 7)
        throw std::domain_error("Mask value out of range");
    size_t sz = static_cast<size_t>(size);
    for (size_t y = 0; y < sz; y++) {
        for (size_t x = 0; x < sz; x++) {
            bool invert;
            switch (msk) {
            case 0:  invert = (x + y) % 2 == 0;                    break;
            case 1:  invert = y % 2 == 0;                          break;
            case 2:  invert = x % 3 == 0;                          break;
            case 3:  invert = (x + y) % 3 == 0;                    break;
            case 4:  invert = (x / 3 + y / 2) % 2 == 0;            break;
            case 5:  invert = x * y % 2 + x * y % 3 == 0;          break;
            case 6:  invert = (x * y % 2 + x * y % 3) % 2 == 0;    break;
            case 7:  invert = ((x + y) % 2 + x * y % 3) % 2 == 0;  break;
            default:  throw std::logic_error("Unreachable");
            }
            modules.at(y).at(x) = modules.at(y).at(x) ^ (invert & !isFunction.at(y).at(x));
        }
    }
}


long QrCode::getPenaltyScore() const {
    long result = 0;

    // Adjacent modules in row having same color, and finder-like patterns
    for (int y = 0; y < size; y++) {
        bool runColor = false;
        int runX = 0;
        std::array<int,7> runHistory = {};
        for (int x = 0; x < size; x++) {
            if (module(x, y) == runColor) {
                runX++;
                if (runX == 5)
                    result += PENALTY_N1;
                else if (runX > 5)
                    result++;
            } else {
                finderPenaltyAddHistory(runX, runHistory);
                if (!runColor)
                    result += finderPenaltyCountPatterns(runHistory) * PENALTY_N3;
                runColor = module(x, y);
                runX = 1;
            }
        }
        result += finderPenaltyTerminateAndCount(runColor, runX, runHistory) * PENALTY_N3;
    }
    // Adjacent modules in column having same color, and finder-like patterns
    for (int x = 0; x < size; x++) {
        bool runColor = false;
        int runY = 0;
        std::array<int,7> runHistory = {};
        for (int y = 0; y < size; y++) {
            if (module(x, y) == runColor) {
                runY++;
                if (runY == 5)
                    result += PENALTY_N1;
                else if (runY > 5)
                    result++;
            } else {
                finderPenaltyAddHistory(runY, runHistory);
                if (!runColor)
                    result += finderPenaltyCountPatterns(runHistory) * PENALTY_N3;
                runColor = module(x, y);
                runY = 1;
            }
        }
        result += finderPenaltyTerminateAndCount(runColor, runY, runHistory) * PENALTY_N3;
    }

    // 2*2 blocks of modules having same color
    for (int y = 0; y < size - 1; y++) {
        for (int x = 0; x < size - 1; x++) {
            bool  color = module(x, y);
            if (  color == module(x + 1, y) &&
                color == module(x, y + 1) &&
                color == module(x + 1, y + 1))
                result += PENALTY_N2;
        }
    }

    // Balance of dark and light modules
    int dark = 0;
    for (const vector<bool> &row : modules) {
        for (bool color : row) {
            if (color)
                dark++;
        }
    }
    int total = size * size;  // Note that size is odd, so dark/total != 1/2
    // Compute the smallest integer k >= 0 such that (45-5k)% <= dark/total <= (55+5k)%
    int k = static_cast<int>((std::abs(dark * 20L - total * 10L) + total - 1) / total) - 1;
    assert(0 <= k && k <= 9);
    result += k * PENALTY_N4;
    assert(0 <= result && result <= 2568888L);  // Non-tight upper bound based on default values of PENALTY_N1, ..., N4
    return result;
}


vector<int> QrCode::getAlignmentPatternPositions() const {
    if (version == 1)
        return vector<int>();
    else {
        int numAlign = version / 7 + 2;
        int step = (version * 8 + numAlign * 3 + 5) / (numAlign * 4 - 4) * 2;
        vector<int> result;
        for (int i = 0, pos = size - 7; i < numAlign - 1; i++, pos -= step)
            result.insert(result.begin(), pos);
        result.insert(result.begin(), 6);
        return result;
    }
}


int QrCode::getNumRawDataModules(int ver) {
    if (ver < MIN_VERSION || ver > MAX_VERSION)
        throw std::domain_error("Version number out of range");
    int result = (16 * ver + 128) * ver + 64;
    if (ver >= 2) {
        int numAlign = ver / 7 + 2;
        result -= (25 * numAlign - 10) * numAlign - 55;
        if (ver >= 7)
            result -= 36;
    }
    assert(208 <= result && result <= 29648);
    return result;
}


int QrCode::getNumDataCodewords(int ver, Ecc ecl) {
    return getNumRawDataModules(ver) / 8
           - ECC_CODEWORDS_PER_BLOCK    [static_cast<int>(ecl)][ver]
                 * NUM_ERROR_CORRECTION_BLOCKS[static_cast<int>(ecl)][ver];
}


vector<uint8_t> QrCode::reedSolomonComputeDivisor(int degree) {
    if (degree < 1 || degree > 255)
        throw std::domain_error("Degree out of range");
    // Polynomial coefficients are stored from highest to lowest power, excluding the leading term which is always 1.
    // For example the polynomial x^3 + 255x^2 + 8x + 93 is stored as the uint8 array {255, 8, 93}.
    vector<uint8_t> result(static_cast<size_t>(degree));
    result.at(result.size() - 1) = 1;  // Start off with the monomial x^0

    // Compute the product polynomial (x - r^0) * (x - r^1) * (x - r^2) * ... * (x - r^{degree-1}),
    // and drop the highest monomial term which is always 1x^degree.
    // Note that r = 0x02, which is a generator element of this field GF(2^8/0x11D).
    uint8_t root = 1;
    for (int i = 0; i < degree; i++) {
        // Multiply the current product by (x - r^i)
        for (size_t j = 0; j < result.size(); j++) {
            result.at(j) = reedSolomonMultiply(result.at(j), root);
            if (j + 1 < result.size())
                result.at(j) ^= result.at(j + 1);
        }
        root = reedSolomonMultiply(root, 0x02);
    }
    return result;
}


vector<uint8_t> QrCode::reedSolomonComputeRemainder(const vector<uint8_t> &data, const vector<uint8_t> &divisor) {
    vector<uint8_t> result(divisor.size());
    for (uint8_t b : data) {  // Polynomial division
        uint8_t factor = b ^ result.at(0);
        result.erase(result.begin());
        result.push_back(0);
        for (size_t i = 0; i < result.size(); i++)
            result.at(i) ^= reedSolomonMultiply(divisor.at(i), factor);
    }
    return result;
}


uint8_t QrCode::reedSolomonMultiply(uint8_t x, uint8_t y) {
    // Russian peasant multiplication
    int z = 0;
    for (int i = 7; i >= 0; i--) {
        z = (z << 1) ^ ((z >> 7) * 0x11D);
        z ^= ((y >> i) & 1) * x;
    }
    assert(z >> 8 == 0);
    return static_cast<uint8_t>(z);
}


int QrCode::finderPenaltyCountPatterns(const std::array<int,7> &runHistory) const {
    int n = runHistory.at(1);
    assert(n <= size * 3);
    bool core = n > 0 && runHistory.at(2) == n && runHistory.at(3) == n * 3 && runHistory.at(4) == n && runHistory.at(5) == n;
    return (core && runHistory.at(0) >= n * 4 && runHistory.at(6) >= n ? 1 : 0)
           + (core && runHistory.at(6) >= n * 4 && runHistory.at(0) >= n ? 1 : 0);
}


int QrCode::finderPenaltyTerminateAndCount(bool currentRunColor, int currentRunLength, std::array<int,7> &runHistory) const {
    if (currentRunColor) {  // Terminate dark run
        finderPenaltyAddHistory(currentRunLength, runHistory);
        currentRunLength = 0;
    }
    currentRunLength += size;  // Add light border to final run
    finderPenaltyAddHistory(currentRunLength, runHistory);
    return finderPenaltyCountPatterns(runHistory);
}


void QrCode::finderPenaltyAddHistory(int currentRunLength, std::array<int,7> &runHistory) const {
    if (runHistory.at(0) == 0)
        currentRunLength += size;  // Add light border to initial run
    std::copy_backward(runHistory.cbegin(), runHistory.cend() - 1, runHistory.end());
    runHistory.at(0) = currentRunLength;
}


bool QrCode::getBit(long x, int i) {
    return ((x >> i) & 1) != 0;
}


/*---- Tables of constants ----*/

const int QrCode::PENALTY_N1 =  3;
const int QrCode::PENALTY_N2 =  3;
const int QrCode::PENALTY_N3 = 40;
const int QrCode::PENALTY_N4 = 10;


const int8_t QrCode::ECC_CODEWORDS_PER_BLOCK[4][41] = {
    // Version: (note that index 0 is for padding, and is set to an illegal value)
    //0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40    Error correction level
    {-1,  7, 10, 15, 20, 26, 18, 20, 24, 30, 18, 20, 24, 26, 30, 22, 24, 28, 30, 28, 28, 28, 28, 30, 30, 26, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},  // Low
    {-1, 10, 16, 26, 18, 24, 16, 18, 22, 22, 26, 30, 22, 22, 24, 24, 28, 28, 26, 26, 26, 26, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28},  // Medium
    {-1, 13, 22, 18, 26, 18, 24, 18, 22, 20, 24, 28, 26, 24, 20, 30, 24, 28, 28, 26, 30, 28, 30, 30, 30, 30, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},  // Quartile
    {-1, 17, 28, 22, 16, 22, 28, 26, 26, 24, 28, 24, 28, 22, 24, 24, 30, 28, 28, 26, 28, 30, 24, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},  // High
};

const int8_t QrCode::NUM_ERROR_CORRECTION_BLOCKS[4][41] = {
    // Version: (note that index 0 is for padding, and is set to an illegal value)
    //0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40    Error correction level
    {-1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 4,  4,  4,  4,  4,  6,  6,  6,  6,  7,  8,  8,  9,  9, 10, 12, 12, 12, 13, 14, 15, 16, 17, 18, 19, 19, 20, 21, 22, 24, 25},  // Low
    {-1, 1, 1, 1, 2, 2, 4, 4, 4, 5, 5,  5,  8,  9,  9, 10, 10, 11, 13, 14, 16, 17, 17, 18, 20, 21, 23, 25, 26, 28, 29, 31, 33, 35, 37, 38, 40, 43, 45, 47, 49},  // Medium
    {-1, 1, 1, 2, 2, 4, 4, 6, 6, 8, 8,  8, 10, 12, 16, 12, 17, 16, 18, 21, 20, 23, 23, 25, 27, 29, 34, 34, 35, 38, 40, 43, 45, 48, 51, 53, 56, 59, 62, 65, 68},  // Quartile
    {-1, 1, 1, 2, 4, 4, 4, 5, 6, 8, 8, 11, 11, 16, 16, 18, 16, 19, 21, 25, 25, 25, 34, 30, 32, 35, 37, 40, 42, 45, 48, 51, 54, 57, 60, 63, 66, 70, 74, 77, 81},  // High
};


data_too_long::data_too_long(const std::string &msg) :
    std::length_error(msg) {}



/*---- Class BitBuffer ----*/

BitBuffer::BitBuffer()
    : std::vector<bool>() {}


void BitBuffer::appendBits(std::uint32_t val, int len) {
    if (len < 0 || len > 31 || val >> len != 0)
        throw std::domain_error("Value out of range");
    for (int i = len - 1; i >= 0; i--)  // Append bit by bit
        this->push_back(((val >> i) & 1) != 0);
}

}



