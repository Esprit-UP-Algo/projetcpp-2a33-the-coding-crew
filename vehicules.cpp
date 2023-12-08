#include "vehicules.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

#include <QTableView>

#include <QHeaderView>
vehicules::vehicules()
{
    idc=0;
    capacite=0;
    matricule="";
    datee=QDate::currentDate();
}
vehicules::vehicules(int capacite,QDate datee ,int idc,QString matricule)

{
    this->idc=idc;
    this->capacite=capacite;
    this->matricule=matricule;
    this->datee=datee;

}

int vehicules::getIDC(){return idc;}
int vehicules::getIDCA(){return capacite;}
QString vehicules::getMatricule(){return matricule;}
QDate vehicules::getDate(){return datee;}



void vehicules::setIDC(int idc){this->idc=idc;}
void vehicules::setIDCA(int capacite){this->capacite=capacite;}
void vehicules::setMatricule(QString matricule){this->matricule=matricule;}
void vehicules::setDate(QDate datee){this->datee=datee;}



bool vehicules::ajouter(int capacite,QDate date,int idc,QString matricule)
{

QSqlQuery query;
query.prepare("INSERT INTO GESTION_VEHICULE (CAPACITE,DATEE,IDC,MATRICULE)"
              "VALUES (:capacite ,:datee,:idc,:matricule)");
query.bindValue(":capacite", capacite);
query.bindValue(":datee", datee);
query.bindValue(":idc", idc);
query.bindValue(":matricule", matricule);

return    query.exec();
}

QSqlQueryModel* vehicules::afficher()
{

QSqlQueryModel* model=new QSqlQueryModel();

model->setQuery("SELECT* FROM GESTION_VEHICULE");
model->setHeaderData(0,Qt::Horizontal,QObject:: tr("MATRICULE"));
model->setHeaderData(1,Qt::Horizontal,QObject:: tr("CAPACITE"));
model->setHeaderData(2,Qt::Horizontal,QObject:: tr("IDC"));
model->setHeaderData(3,Qt::Horizontal,QObject:: tr("DATEE"));

QTableView* tableview =new QTableView;
tableview->setModel(model);

QHeaderView* headerview =tableview->horizontalHeader();
headerview ->setSectionResizeMode(QHeaderView::Stretch);
return model;
}

bool vehicules::supprimer(QString matricule)
{
    QSqlQuery query;
    query.prepare("DELETE FROM GESTION_VEHICULE WHERE MATRICULE=:matricule");
    query.bindValue(":matricule", matricule);
    return query.exec();
}

bool vehicules::modifier(QString matricule)
{
 QSqlQuery query;
query.prepare("UPDATE  GESTION_VEHICULE set  CAPACITE =:capacite,DATEE=:datee,IDC=:idc  where MATRICULE=:matricule ");
query.bindValue(":capacite", capacite);
query.bindValue(":datee", datee);
query.bindValue(":idc", idc);
query.bindValue(":matricule", matricule);

 return query.exec();
}

QSqlQueryModel*vehicules ::tri()
{

QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("SELECT* FROM GESTION_VEHICULE ORDER BY DATEE ASC");
model->setHeaderData(0,Qt::Horizontal,QObject:: tr("MATRICULE"));
model->setHeaderData(1,Qt::Horizontal,QObject:: tr("CAPACITE"));
model->setHeaderData(2,Qt::Horizontal,QObject:: tr("IDC"));
model->setHeaderData(3,Qt::Horizontal,QObject:: tr("DATEE"));

QTableView* tableview =new QTableView;
tableview->setModel(model);

QHeaderView* headerview =tableview->horizontalHeader();
headerview ->setSectionResizeMode(QHeaderView::Stretch);
return model;
}

bool vehicules::matExists(QString mat)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM GESTION_VEHICULE WHERE MATRICULE =:mat");
    query.bindValue(":mat", mat);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}
