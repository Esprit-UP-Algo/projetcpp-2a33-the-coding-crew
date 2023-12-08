#include "conteneur.h"
#include<QDebug>
#include<QSqlQuery>

#include <QString>
#include <QSqlQueryModel>
#include<QObject>
#include <QtSql>
Conteneur::Conteneur()
{ID=0 ;
    etat="";
    quantite=0 ;
    matiere="" ;
}
Conteneur::Conteneur(int ID ,QString etat ,int quantite,QString matiere )
{

    this->ID=ID;
    this->etat=etat;
    this->quantite=quantite;
    this->matiere=matiere ;
}

bool Conteneur::ajouter(int ID,QString etat,int quantite,QString matiere)
{
    QSqlQuery query ;
    query.prepare("INSERT INTO CONTENEUR (ID,ETAT,QUANTITE,MATIERE)"
                  "values (:ID,:etat,:quantite,:matiere)");
    query.bindValue(":ID",ID);
    query.bindValue(":etat",etat);
    query.bindValue(":quantite",quantite);
    query.bindValue(":matiere",matiere);
    return query.exec() ;

}
QSqlQueryModel * Conteneur :: afficher() {
 QSqlQueryModel* model=new QSqlQueryModel() ;
    model->setQuery("SELECT* FROM CONTENEUR ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant")) ;
model->setHeaderData(1,Qt::Horizontal,QObject::tr("etat")) ;
model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite")) ;
model->setHeaderData(3,Qt::Horizontal,QObject::tr("matiere")) ;

return model ;
}

bool Conteneur::supprimer(int ID)
{ QSqlQuery query ;

    query.prepare("DELETE from CONTENEUR WHERE ID= :ID");
    query.bindValue(":ID", ID) ;
    return query.exec() ;
}
bool Conteneur::supprimerC(int id)
{ QSqlQuery query ;

    query.prepare("DELETE from CONTENEUR WHERE id= :id");
    query.bindValue(":id", id) ;
    return query.exec() ;
}
bool Conteneur::modifier(int ID)
{
 QSqlQuery query;



query.prepare("update  CONTENEUR set  etat=:etat,quantite=:quantite,matiere=:matiere where ID=:ID ");


query.bindValue(":ID",ID);
query.bindValue(":etat",etat);
query.bindValue(":quantite",quantite);
query.bindValue(":matiere",matiere);



 return query.exec();
}
/*

QSqlQueryModel* Conteneur::triQuantite1()
   {

   QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM CONTENEUR ORDER BY Quantite");

   return model;
   }
   QSqlQueryModel* Conteneur::triQuantite2()
   {

   QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM BIENS ORDER BY PRICE DESC");

   return model;
       }
   QSqlQueryModel * ::recherche(QString var)
           {
               QSqlQueryModel * model= new QSqlQueryModel();

               model->setQuery("SELECT * FROM CONTENEUR WHERE ID LIKE '%"+var+"%' or etat LIKE '%"+var+"%' or quantite LIKE '%"+var+"%'");
               model->query().bindValue(":ID",ID);
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));

               return model;
           }

*/
QSqlQueryModel* Conteneur::afficher1()

{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM conteneur ORDER BY quantite ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant")) ;
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("etat")) ;
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite")) ;
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("matiere")) ;
    return model;
}

bool Conteneur::idExist(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM conteneur WHERE id=:id");
    query.bindValue("id:",id);
    if (query.exec() && query.next())
     {
        int count=query.value(0).toInt();
        return count>0;
    }
      return false;

}

/*int Conteneur::countEmptyContainers(int n) {


    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM conteneurs WHERE etat='vide' AND id <= :max_id");


    query.bindValue(":max_id", n);

    if (!query.exec()) {
        qDebug() << "Échec de l'exécution de la requête:" << query.lastError().text();
        return -1;
    }

    int count = 0;
    if (query.next()) {
        count = query.value(0).toInt();
    }


    return count;
}

*/


bool  Conteneur::doesIDExist(int id) {
    QSqlQuery query;
      query.prepare("SELECT COUNT(*) FROM conteneur WHERE id = :id");
      query.bindValue(":id", id);

      if (!query.exec()) {
          // Handle the case where the query execution fails
          return false;
      }

      if (query.next()) {
          int count = query.value(0).toInt();
          return count > 0; // If count is greater than 0, the ID exists
      }

      return false;
}
