#include "matiererecyclee.h"
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


#include <QPieSeries>
#include <QPieSlice>
#include <QChart>
#include <QChartView>

#include <QtCharts/QChart>
#include <QPixmap>
#include <QMessageBox>
#include <QComboBox>
#include <QFileDialog>
#include <QPainter>
#include <QTextStream>
#include <QTextDocument>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts>
#include <QPieSlice>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <QQuickWidget>
#include <QUrl>
#include <QQmlContext>

#include <QtWidgets/QWidget>
#include <QtCharts/QChart>
#include <QQuickItem>

#include <QFile>
#include <QToolButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QDebug>
#include <QIcon>

matiereRecyclee::matiereRecyclee()
{
id_mr=0;
typeMr=" ";
prix=0;
date_entree= QDate(00, 00, 2023);
quantite=0;
}

matiereRecyclee::matiereRecyclee(int id,QString t,float p,QDate d,int q)
{
id_mr=id;
typeMr=t;
prix=p;
date_entree=d;
quantite=q;
}



void matiereRecyclee::setId_mr(int n)
{
    id_mr=n;
}
void matiereRecyclee::setPrix (int n)
{
    prix=n;
}

void matiereRecyclee::setTypeMr(QString n)
{
    typeMr=n;
}

void matiereRecyclee::setDate_entree(QDate n)
{
   date_entree=n;

}
void matiereRecyclee::setQuantite(int n)
{
    quantite=n;
}


 int matiereRecyclee::getId_mr()
 {
     return id_mr;
 }
 float matiereRecyclee::getPrix()
 {
     return prix;
 }
 QString matiereRecyclee::getTypeMr()
 {
     return typeMr;
 }
 QDate matiereRecyclee::getDate_entree()
 {
     return date_entree;
 }
 int matiereRecyclee::getQuantite()
 {
     return quantite;
 }

 bool matiereRecyclee::ajouter()
 {
         QSqlQuery query;
         QString id_string=QString::number(id_mr);
         QString qt_string=QString::number(quantite);
         QString prix_string=QString::number(prix);

              query.prepare("INSERT INTO matiere_recyclee (id_Mr,Type_prod,prix,date_entree,quantités) "
                            "VALUES (:id, :type, :prix, :date_entree, :quantite)");
              query.bindValue(":id", id_string);
              query.bindValue(":type", typeMr);
              query.bindValue(":prix", prix_string);
              query.bindValue(":date_entree", date_entree);
              query.bindValue(":quantite", qt_string);

             return query.exec();
 }

QSqlQueryModel* matiereRecyclee::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT ID_MR , TYPE_PROD ,PRIX ,DATE_ENTREE ,QUANTITÉS FROM matiere_recyclee");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date d'entrée"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Quantité"));

    return model;
}


bool matiereRecyclee::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from matiere_recyclee where id_Mr=:id");
    query.bindValue(":id", id);

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




bool matiereRecyclee::modif()
    {
        QSqlQuery query;
        QString id_string = QString::number(id_mr);
        QString qt_string = QString::number(quantite);
        QString prix_string = QString::number(prix);

        query.prepare("UPDATE matiere_recyclee SET ID_MR = :id , TYPE_PROD = :type, PRIX = :prix, DATE_ENTREE = :date_entree, QUANTITÉS = :quantite WHERE ID_MR = :id");
        query.bindValue(":id", id_string);
        query.bindValue(":type", typeMr);
        query.bindValue(":prix", prix_string);
        query.bindValue(":date_e"
                        "ntree", date_entree);
        query.bindValue(":quantite", qt_string);

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

QSqlQueryModel* matiereRecyclee::sortTableByQTT()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_MR, TYPE_PROD, PRIX, DATE_ENTREE, QUANTITÉS FROM matiere_recyclee ORDER BY QUANTITÉS DESC");
    return model;

}

QMap<QString, int> matiereRecyclee::getProdStatistics() {
    QMap<QString, int> statistics;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) AS count FROM matiere_recyclee WHERE TYPE_PROD = 'Carton'");
    if (query.exec() && query.next()) {
        statistics["Carton"] = query.value("count").toInt();
    }

    query.prepare("SELECT COUNT(*) AS count FROM matiere_recyclee WHERE TYPE_PROD='Plastique'");
    if (query.exec() && query.next()) {
        statistics["Plastique"] = query.value("count").toInt();
    }

    query.prepare("SELECT COUNT(*) AS count FROM matiere_recyclee WHERE TYPE_PROD='Verre'");
    if (query.exec() && query.next()) {
        statistics["Verre"] = query.value("count").toInt();
    }

    return statistics;
}
