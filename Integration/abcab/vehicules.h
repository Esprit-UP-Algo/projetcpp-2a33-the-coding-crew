#ifndef VEHICULES_H
#define VEHICULES_H

#include <QString>
#include <QSqlQueryModel>
#include <QDate>
class vehicules
{
public:
    vehicules();
    vehicules(int,QDate,int ,QString );
    //getters
        int getIDC();
        int getIDCA();
        QString getMatricule();
        QDate getDate();

    //setters
        void setIDC(int);
        void setIDCA(int);
        void setMatricule(QString);
        void setDate(QDate);

     //fonctionalites

        bool ajouterVe();
        QSqlQueryModel* afficher();
        bool supprimer(QString matricule );
        bool modifier(QString matricule);
        QSqlQueryModel *recherche(QString var);
        QSqlQueryModel* tri();
bool matExists(QString mat);

private:
   int idc;
   int capacite;
   QString matricule;
   QDate datee;
};

#endif // VEHICULES_H
