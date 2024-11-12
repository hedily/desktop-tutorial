#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "client.h"
#include <QItemSelection>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_valider_clicked();

    void on_annuler_clicked();

    void on_afficher_clicked();

    void updateTable();

    void on_modifier_clicked();

    void on_supprimer_clicked();

//
    void on_trier_2_clicked();

    void on_rechercher_clicked();

    void on_exporter_clicked();

private:
    Ui::MainWindow *ui;
    Client clientManager; // Instance de la classe Client pour gérer les clients
    QSqlQueryModel *clientModel; // Modèle pour afficher les données des clients
    Client *selectedClient; // Client sélectionné
    Client client;

    void populateClientTable();
    void displayClientDetails(Client *client);
    void clearClientDetails();
    Client* getSelectedClient();
    void updateClient(Client* client);
};

#endif // MAINWINDOW_H
