#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test = c.createConnect();

    if (test) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Base de données ouverte"),
                                 QObject::tr("Connexion réussie.\n"
                                             "Cliquez sur Annuler pour quitter."),
                                 QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Base de données fermée"),
                              QObject::tr("Échec de la connexion.\n"
                                          "Cliquez sur Annuler pour quitter."),
                              QMessageBox::Cancel);
        return -1; // Ajoutez cette ligne pour terminer l'application en cas d'échec.
    }

    return a.exec();
}
