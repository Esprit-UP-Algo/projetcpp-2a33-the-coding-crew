#include "pointdecollect.h"
#include "add_pc.h"
#include <QSqlQuery>
#include <QtDebug>
#include "connect.h"
#include <QSqlQueryModel>
#include <QObject>
#include <QMessageBox>
PointDeCollect::PointDeCollect()
{
   id_pc=0;
   quntiter=0;
   lieu="";
}
PointDeCollect::PointDeCollect(int a,QDate b,QString c,int d)
{
    id_pc=a;
    quntiter=d;
    lieu=c;
    dat_pc=b;

}

bool PointDeCollect::ajouter()
 {
         QSqlQuery query;
         QString id_string=QString::number(id_pc);
         QString qt_string=QString::number(quntiter);


              query.prepare("INSERT INTO points_de_collectes (id_pc,lieu,dat_pc,quntiter) "
                            "VALUES (:id_pc, :lieu, :dat_pc, :quntiter)");
              query.bindValue(0, id_string);
              query.bindValue(1, lieu);
              query.bindValue(2, dat_pc);
              query.bindValue(3, qt_string);

             return query.exec();
 }

 QSqlQueryModel* PointDeCollect::afficher()
 {   QMessageBox msgBox;
      QSqlQueryModel*  model=new QSqlQueryModel();

            model->setQuery("SELECT ID_PC,LIEU,DAT_PC,QUNTITER FROM points_de_collectes");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("lieu de PC"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("date pc"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("quntite de matier"));
            return  model;

 }

bool PointDeCollect::supprime(int id_PC)
{
     QSqlQuery query;

    query.prepare("Delete from points_de_collectes where id_PC=:id_PC ");
    query.bindValue(0, id_PC);

    return query.exec();

}

bool PointDeCollect::modifier()
{
    QSqlQuery query;
    QString id_string=QString::number(id_pc);
    QString qt_string=QString::number(quntiter);

    query.prepare("UPDATE points_de_collectes SET id_pc = :id_pc, dat_pc = :dat_pc,"
                  " lieu = :lieu, quntiter = :quntiter");

    query.bindValue("id_pc", id_string);
    query.bindValue("dat_pc", dat_pc);
    query.bindValue("lieu", lieu);
    query.bindValue("quntiter", qt_string);


    return query.exec();
}














