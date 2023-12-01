#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Arduino
{
public:
    Arduino();
    int connect_arduino(); // permet de connecter le PC a Arduino
    int close_arduino(); // permet de femer la connexion
    int write_to_arduino( QByteArray ); // envoyer des donnees vers arduino
    QByteArray read_from_arduino(); //recevoir des donnees de la carte Arduino
    QSerialPort* getserial(); // accesseur
    QString getarduino_port_name();
    private:
    QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
    //et des fonctions (envoi, lecture de reception, ... ) sur ce qu'est une voie serie pour Arduino.
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data; // contenant les donnees lues a partir d'Arduino
};

#endif // ARDUINO_H
