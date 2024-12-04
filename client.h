#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client {
private:
    QString nom, prenom, adresse, email, genre, dn ,id_client;
    int  telephone, pt_fidelite;

public:

    Client();
    Client(const QString& id_client, const QString& nom, const QString& prenom, const QString& adresse, int telephone,const QString& email, const QString& genre,  const QString& dn, int pt_fidelite);

    QString getIdClient() const { return id_client; }
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    int getTelephone() const { return telephone; }
    QString getEmail() const { return email; }
    QString getAdresse() const { return adresse; }
    QString getGenre() const { return genre; }
    QString getDateNaissance() const { return dn; }
    int getPointsFidelite() const { return pt_fidelite; }


    void setIdClient(const QString& i) { id_client = i; }
    void setNom(const QString& n) { nom = n; }
    void setPrenom(const QString& p) { prenom = p; }
    void setTelephone(int t) { telephone = t; }
    void setEmail(const QString& e) { email = e; }
    void setAdresse(const QString& a) { adresse = a; }
    void setGenre(const QString& g) { genre = g; }
    void setDateNaissance(const QString& d) { dn = d; }
    void setPointsFidelite(int p) { pt_fidelite = p; }


    bool ajouter();

    QSqlQueryModel* afficher();
    bool modifier(const QString& id_client, const QString& nom, const QString& prenom,
                  const QString& adresse, int telephone,const QString& genre, const QString& email,
                  const QString& dn, int pt_fidelite);

    QSqlQueryModel* rechercher(const QString& valeur);
    QSqlQueryModel* trier(const QString& critere, bool ascendant);


    QMap<QString, int> obtenirStatistiquesParAdresse();
    QMap<QString, int> statistiquesParGenre() ;

    QList<Client> getAnniversairesProches();

    bool envoyerEmail(QString id_client, QString sujet, QString message);

    bool supprimer(QString id);



};

#endif // CLIENT_H
