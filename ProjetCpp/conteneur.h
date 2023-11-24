#ifndef CONTENEUR_H
#define CONTENEUR_H
#define CONTENEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


#include <QWidget>


class Conteneur{
private :
    int  quantite,ID ;
    QString etat , matiere  ;




public:
     Conteneur() ;
     Conteneur(int,QString ,int,QString ) ;


     int getID(){return ID ;}
     QString getetat(){return etat ;};
     int getquantite() {return quantite ;};
     QString getmatiere(){return matiere ;};
     void setID(int a) {ID= a;}
     void setquantite(int b) {quantite= b;}
     void setetat(QString e) {etat=e ;}
     void setmatiere(QString m) {matiere=m;}

      bool ajouter(int ID,QString etat,int quantite,QString matiere) ;
      QSqlQueryModel* afficher() ;
      bool supprimer(int) ;
      bool modifier(int);
      QSqlQueryModel* afficher1();

bool idExist(int id);

} ;


#endif // CONTENEUR_H
