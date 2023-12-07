#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQueryModel>
#include <QMainWindow>
#include <QObject>
#include <QDebug>

#include <QSharedDataPointer>
#include <QWidget>
#include <QDate>

enum {
    NOM,
    DEPARTEMENT,
    POSTE,
    SALAIRE
};

class Employe
{


    QString nompren;
    QString mdp;
    QString adresse_email;
    int cin_emp;
    int num_tel;
    QDate date_derecru;
    QString departement;
    QString poste;
    int salaire;
    int hfixe;
    int hsupp;
public:
    Employe();
    Employe(QString,QString,QString,int,int,QDate,QString,QString,int,int,int );

    // GETTERS
    QString getNom();
    QString getMdp();
    QString getAdresse();
    int getCin();
    int getNumTel();
    QDate getDate();
    QString getDepartement();
    QString getPoste();
    int getSalaire();
    int getHfixe();
    int getHsupp();


    //SETTERS
    void setNom(QString newNom);
    void setMdp(QString newMdp);
    void setAdresse(QString newAdresse);
    void setCin(int newCin);
    void setNumTel(int newNum);
    void setDate(QDate newDate);
    void setDepartement(QString newDepartement);
    void setPoste(QString newPoste);
    void setSalaire(int newSalaire);
    void setHfixe(int newHfixe);
    void sethsupp(int newHsupp);

    bool ajouter();
    QSqlQueryModel *afficherEmployes();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel*trier_nom();
    QSqlQueryModel *rechercheremp(int critere);
    void exportationExcel(QString &liste_emp);

    ~Employe(){};
};

#endif // EMPLOYE_H
