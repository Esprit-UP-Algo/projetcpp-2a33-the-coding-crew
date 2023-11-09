#ifndef MATIERERECYCLEE_H
#define MATIERERECYCLEE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QImage>


class matiereRecyclee
{    private:
     int id_mr;
     QString typeMr;
     float prix;
     QDate date_entree;
     int quantite;

public:

    void setId_mr(int n);
    void setPrix (int n);
    void setTypeMr(QString n);
    void setDate_entree(QDate n);
    void setQuantite(int n);

     int getId_mr();
     float getPrix();
     QString getTypeMr();
     QDate getDate_entree();
     int getQuantite();

    matiereRecyclee();
    matiereRecyclee(int,QString,float,QDate,int);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modif();
    QImage generateQRCode(const QString& text);
     QSqlQueryModel* sortTableByQTT();



};

#endif // MATIERERECYCLEE_H
