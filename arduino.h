#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino {
public:
    Arduino();
    int connect_arduino();  // Connecter le PC à Arduino
    int close_arduino();    // Fermer la connexion
    void write_to_arduino(QByteArray); // Envoyer des données
    QByteArray read_from_arduino();    // Recevoir des données
    QSerialPort* getserial();          // Obtenir l'objet QSerialPort
    QString getarduino_port_name();    // Obtenir le nom du port Arduino

private:
    QSerialPort* serial;   // Objet pour la communication série
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;       // Conteneur pour les données lues
};

#endif // ARDUINO_H
