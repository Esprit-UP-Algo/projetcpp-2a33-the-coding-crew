#include "employe.h"
#include "mainwindow.h"
#include "cstdlib"
#include <QMessageBox>
#include <QObject>
#include <QDebug>
#include <iostream>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include<QSqlQueryModel>

Employe::Employe()
{
   nompren= "Sabee Doghmen";
   mdp="sabsoub";
   adresse_email=" sabee.doghmen@esprit.tn";
   cin_emp=14523727 ;
   num_tel=50100257;
   date_derecru = QDate();
   departement="ressource humaines";
   poste="chef departement";
   salaire=1400;
   hfixe=200;
   hsupp=24;
}




Employe::Employe(QString nompren,QString adresse_email,QString mdp,int cin_emp,int num_tel,QDate date_derecru,QString departement,QString poste,int salaire,int hfixe,int hsupp)

{
   this->nompren=nompren;
   this->mdp=mdp;
   this->adresse_email=adresse_email;
   this->cin_emp=cin_emp;
   this->num_tel=num_tel;
   this->date_derecru=date_derecru;
   this->departement=departement;
   this->poste=poste;
   this->salaire=salaire;
   this->hfixe=hfixe;
   this->hsupp=hsupp;

}

// GETTERS
QString Employe::getNom()
{
   return nompren;
}

QString Employe::getMdp()
{
   return mdp;
}

QString Employe::getAdresse()
{
   return adresse_email;
}
int Employe::getCin()
{
   return cin_emp;
}
int Employe::getNumTel()
{
   return num_tel;
}
QDate Employe::getDate()
{
   return date_derecru;
}
QString Employe::getDepartement()
{
   return departement;
}
QString Employe::getPoste()
{
   return poste;
}
int Employe::getSalaire()
{
   return salaire;
}

int Employe::getHfixe()
{
   return hfixe;
}
int Employe::getHsupp()
{
   return hsupp;
}
// SETTERS
void Employe::setNom(QString newNom)
{
   nompren=newNom;
}
void Employe::setMdp(QString newMdp)
{
   mdp=newMdp;
}
void Employe::setAdresse(QString newAdresse)
{
   adresse_email=newAdresse;
}

void Employe::setCin(int newCin)
{
   cin_emp = newCin;
}
void Employe::setNumTel(int newNum)
{
   num_tel=newNum;
}
void Employe::setDate(QDate newDate)
{
  date_derecru=newDate;
}
void Employe::setDepartement(QString newDepartement)
{
   departement=newDepartement;
}
void Employe::setPoste(QString newPoste)
{
   poste=newPoste;
}
void Employe::setSalaire(int newSalaire)
{
   salaire=newSalaire;
}
void Employe::setHfixe(int newHfixe)
{
   hfixe=newHfixe;
}
void Employe::sethsupp(int newHsupp)
{
   hsupp=newHsupp;
}



bool Employe::ajouter()
{
    Employe Emp(nompren,adresse_email,mdp,cin_emp,num_tel,date_derecru,departement,poste,salaire,hfixe,hsupp);

   QSqlQuery query;

   query.prepare("INSERT INTO EMPLOYEE"
                 " (NOMPREN,ADRESSE_EMAIL,PASSWORD,CIN_EMP,NUM_TEL,DATE_DERECRU,DEPARTEMENT,POSTE,SALAIRE,HFIXE,HSUPP)"
                 "VALUES (:nompren,:adresse_email,:mdp,:cin_emp,:num_tel,:date_derecru,:departement,:poste,:salaire,:hfixe,:hsupp)");


   //QString tmpnom = QString(nompren);
   //QString tmpadresse = QString(adresse_email);
   //QString tmpmdp = QString(mdp);
   QString tmpcin = QString::number(cin_emp);
   QString tmpnum = QString::number(num_tel);
   QDate tmpdate = QDate(date_derecru);
   //QString tmpdepartement = QString(departement);
   //QString tmpposte = QString(poste);
   QString tmpsalaire = QString::number(salaire);
   QString tmphfixe = QString::number(hfixe);
   QString tmphsupp = QString::number(hsupp);

   query.bindValue(":nompren",nompren);
   query.bindValue(":mdp",mdp);
   query.bindValue(":adresse_email",adresse_email);
   query.bindValue(":cin_emp",tmpcin);
   query.bindValue(":num_tel", tmpnum);
   query.bindValue(":date_derecru", tmpdate);
   query.bindValue(":departement",departement);
   query.bindValue(":poste",poste);
   query.bindValue(":salaire",tmpsalaire);
   query.bindValue(":hfixe",tmphfixe);
   query.bindValue(":hsupp",tmphsupp);

   return (query.exec());
}


QSqlQueryModel* Employe::afficherEmployes()
{
   QSqlQueryModel *model = new QSqlQueryModel();

   model->setQuery("select * from EMPLOYEE");


   return model;
}



bool Employe::supprimer(int cin_emp)
{
   QSqlQuery query;
   query.prepare("Delete from EMPLOYEE where CIN_EMP=:cin_emp");
   query.bindValue(0,cin_emp);
   return query.exec();
}


bool Employe::modifier()
{

   QSqlQuery query;
   //QString tmpnom = QString(nompren);
   //QString tmpadresse = QString(adresse_email);
   //QString tmpmdp = QString(mdp);
   QString tmpcin = QString::number(cin_emp);
   QString tmpnum = QString::number(num_tel);
   QDate tmpdate = QDate(date_derecru);
   //QString tmpdepartement = QString(departement);
   //QString tmpposte = QString(poste);
   QString tmpsalaire = QString::number(salaire);
   QString tmphfixe = QString::number(hfixe);
   QString tmphsupp = QString::number(hsupp);
   query.prepare("UPDATE EMPLOYEE SET NOMPREN=:nompren,ADRESSE_EMAIL=:adresse_email,PASSWORD=:mdp,CIN_EMP=:cin_emp,NUM_TEL=:num_tel,DATE_DERECRU=:date_derecru,DEPARTEMENT=:departement,POSTE=:poste,SALAIRE=:salaire,HFIXE=:hfixe,HSUPP=:hsupp WHERE CIN_EMP=:cin_emp");

   query.bindValue(":nompren",nompren);
   query.bindValue(":mdp",mdp);
   query.bindValue(":adresse_email",adresse_email);
   query.bindValue(":cin_emp",tmpcin);
   query.bindValue(":num_tel", tmpnum);
   query.bindValue(":date_derecru", tmpdate);
   query.bindValue(":departement",departement);
   query.bindValue(":poste",poste);
   query.bindValue(":salaire",tmpsalaire);
   query.bindValue(":hfixe",tmphfixe);
   query.bindValue(":hsupp",tmphsupp);

   if(query.exec())
       {
           if(query.numRowsAffected() > 0)
               return true;
           else
               return false;
       }
       else
           return false;

}


QSqlQueryModel* Employe:: trier_nom()
{

       QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select * from EMPLOYEE order by nompren ");

       model->setHeaderData(0, Qt::Horizontal, QObject::tr(" NOMPREN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE_EMAIL"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PASSWORD"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN_EMP"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_TEL"));;
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_DERECRU"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("DEPARTEMENT"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("POSTE"));
       model->setHeaderData(8, Qt::Horizontal, QObject::tr("SALAIRE"));
       model->setHeaderData(9, Qt::Horizontal, QObject::tr("HFIXE"));
       model->setHeaderData(10, Qt::Horizontal, QObject::tr("HSUPP"));




   return model;
}



QSqlQueryModel * Employe::rechercheremp(int cin_emp)
{
   QSqlQueryModel *model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("SELECT * FROM EMPLOYEE WHERE CIN_EMP =:cin_emp");
     query.bindValue(":cin_emp", cin_emp);

     if (query.exec()) {
         model->setQuery(query);
     }

     return model;
}



/*
void MainWindow::exportToExcel(const QString &fileName)
{
   QXlsx::Document xlsx;

   // Créez une feuille de calcul dans le fichier Excel
   xlsx.addSheet("Données Employé");

   // Ajoutez des en-têtes
   QStringList headers = {"Nom et Prénom", "Adresse Email", "CIN", "Numéro de Téléphone", "Date de Recrutement", "Département", "Poste", "Salaire"};
   for (int col = 1; col <= headers.size(); ++col) {
       xlsx.write(1, col, headers.at(col - 1));
   }

   // Ajoutez les données des employés
   for (int row = 2; row <= ui->affichage->model()->rowCount(); ++row) {
       for (int col = 1; col <= ui->affichage->model()->columnCount(); ++col) {
           QVariant data = ui->affichage->model()->data(ui->affichage->model()->index(row - 2, col - 1));
           xlsx.write(row, col, data.toString());
       }
   }

   // Sauvegardez le fichier Excel
   xlsx.saveAs(fileName);
}

*/

QSqlQueryModel *afficherEmployes()
{
   QSqlQueryModel *model = new QSqlQueryModel();
   model->setQuery("Select * from SABEE.EMPLOYEE");

   return model;
}
