<<<<<<< HEAD
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Connection c;

    if (!c.createConnect()) {
        QMessageBox::critical(nullptr, QObject::tr("Base de données fermée"),
                              QObject::tr("Échec de la connexion.\n"
                                          "Cliquez sur Annuler pour quitter."),
                              QMessageBox::Cancel);
        return -1; // Terminer l'application en cas d'échec
    }

    MainWindow w;
    w.show();
    QMessageBox::information(nullptr, QObject::tr("Base de données ouverte"),
                             QObject::tr("Connexion réussie.\n"
                                         "Cliquez sur Annuler pour quitter."),
                             QMessageBox::Cancel);

    return a.exec();
=======
int main(){
    cout<<"hello"<<endl;
    cout<<"....";
    cout<<"hi"<<endl;
    cout<<"222";
    return 0;
>>>>>>> 95f2bc20b28fe46007011ffe2d0bfa2b33b759bb
}
