#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QSqlQueryModel>
#include"conteneur.h"
#include<QTextDocument>
#include<QPrinter>
#include<QFileDialog>
#include<QPieSeries>
#include<QChart>
#include<QChartView>
#include<QDebug>
#include <Windows.h>
#include <shellapi.h>
#include <QMessageBox>
#include <QTimer>
#include "smtp.h"
using namespace QtCharts;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   ui->lineEdit_ID->setValidator( new QIntValidator(0 , 999999999, this));
   ui->ID->setValidator( new QIntValidator(0 , 999999999, this));
   ui->lineEdit_quantite->setValidator( new QIntValidator(0 , 999999999, this));
    ui->quantite->setValidator( new QIntValidator(0 , 999999999, this));
   QRegExp regex("[a-z]+",Qt::CaseInsensitive);
   QRegExpValidator* validator = new QRegExpValidator(regex,this);
   ui->lineEdit_matiere->setValidator(validator);
   ui->matiere->setValidator(validator);
   ui->tab_conteneurs->setModel(C.afficher()) ;
   connect(ui->lineEdit_rechercher, &QLineEdit::textChanged, this, &MainWindow::RechercheID);


}
    MainWindow::~MainWindow()
    {
        delete ui;
    }


    void MainWindow::on_boutton_ajouter_clicked()
    {   int c=0;
        int ID=ui->lineEdit_ID->text().toInt() ;
      QString etat = ui->lineEdit_etat->currentText();
        int quantite=ui->lineEdit_quantite->text().toInt();
        QString matiere=ui->lineEdit_matiere->text();



          if(ui->lineEdit_ID->text().isEmpty())
        {QMessageBox msgBox(QMessageBox::Warning, QObject::tr("ERREUR"), QObject::tr("La quantite entre 0 et 10000\nCliquez sur OK pour quitter."), QMessageBox::Ok);
            QString styleSheet = "QMessageBox {"
                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                "border: 2px outset grey;"
                "}"
                "QMessageBox QPushButton {"
                "color: rgba(52,90,105,100%);"
                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                "border-style: solid;"
                "border: 2px solid transparent;"
                "border-radius: 5px;"
                "padding: 1px;"
                "}"
                "QMessageBox QPushButton:hover {"
                "color: #B200ED ;"
                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 70%));"
                "border-style: solid;"
                "border: 2px solid transparent;"
                "border-radius: 5px;"
                "padding: 1px;"
                "}";

            msgBox.setStyleSheet(styleSheet);

            msgBox.exec();
            c++;
}
        if(quantite<0 || quantite>10000)
            {QMessageBox msgBox(QMessageBox::Warning, QObject::tr("ERREUR"), QObject::tr("La quantite entre 0 et 10000\nCliquez sur OK pour quitter."), QMessageBox::Ok);
                QString styleSheet = "QMessageBox {"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                    "border: 2px outset grey;"
                    "}"
                    "QMessageBox QPushButton {"
                    "color: rgba(52,90,105,100%);"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                    "border-style: solid;"
                    "border: 2px solid transparent;"
                    "border-radius: 5px;"
                    "padding: 1px;"
                    "}"
                    "QMessageBox QPushButton:hover {"
                    "color: #B200ED ;"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 70%));"
                    "border-style: solid;"
                    "border: 2px solid transparent;"
                    "border-radius: 5px;"
                    "padding: 1px;"
                    "}";

                msgBox.setStyleSheet(styleSheet);

                msgBox.exec();
                c++;

            }
/*if(RechercheID2()==false)
      {

    QMessageBox msgBox(QMessageBox::Warning, QObject::tr("ERREUR"), QObject::tr("id deja existe"), QMessageBox::Ok);
     msgBox.exec();
    c++;
    }

*/
if(ui->lineEdit_quantite->text().isEmpty())
      {

    QMessageBox msgBox(QMessageBox::Warning, QObject::tr("ERREUR"), QObject::tr("la quantite est vide"), QMessageBox::Ok);
     msgBox.exec();
    c++;
    }
if(ui->lineEdit_matiere->text().isEmpty())
      {

    QMessageBox msgBox(QMessageBox::Warning, QObject::tr("ERREUR"), QObject::tr("la matiere est vide"), QMessageBox::Ok);
     msgBox.exec();
    c++;
    }
    if(c==0)
        {

        bool test=C.ajouter(ID,etat,quantite,matiere);
        if(test)
            {
                QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"), QObject::tr("Ajout avec succès\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);

                QString styleSheet = "QMessageBox {"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                    "border: 2px outset grey;"
                    "}"
                    "QMessageBox QPushButton {"
                    "color: rgba(52,90,105,100%);"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                    "border-style: solid;"
                    "border: 2px solid transparent;"
                    "border-radius: 5px;"
                    "padding: 1px;"
                    "}"
                    "QMessageBox QPushButton:hover {"
                    "color: #B200ED ;"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 70%));"
                    "border-style: solid;"
                    "border: 2px solid transparent;"
                    "border-radius: 5px;"
                    "padding: 1px;"
                    "}";
                ui->ID->clear();
                ui->quantite->clear();
                ui->matiere->clear();

                msgBox.setStyleSheet(styleSheet);

                msgBox.exec();

            }

            else
            {QMessageBox msgBox(QMessageBox::Critical, QObject::tr("Nope"), QObject::tr("Ajout non réussi\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);

                QString styleSheet = "QMessageBox {"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                    "border: 2px outset grey;"
                    "}"
                    "QMessageBox QPushButton {"
                    "color: rgba(52,90,105,100%);"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                    "border-style: solid;"
                    "border: 2px solid transparent;"
                    "border-radius: 5px;"
                    "padding: 1px;"
                    "}"
                    "QMessageBox QPushButton:hover {"
                    "color: #B200ED ;"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 70%));"
                    "border-style: solid;"
                    "border: 2px solid transparent;"
                    "border-radius: 5px;"
                    "padding: 1px;"
                    "}";

                msgBox.setStyleSheet(styleSheet);

                msgBox.exec();
                }
        }

        ui->tab_conteneurs->setModel(C.afficher()) ;
    }





void MainWindow::on_boutton_supprimer_clicked()
{Conteneur C1 ;
    int ID=ui->lineEdit_supp->text().toInt();
bool test=C1.supprimer(ID);

if (test)
   {  QMessageBox msgBox(QMessageBox::Critical, QObject::tr(""), QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
msgBox.exec();
}
else {
     QMessageBox msgBox(QMessageBox::Critical, QObject::tr("Erreur"), QObject::tr("Suppression avec non succes"), QMessageBox::Cancel);
msgBox.exec();
}

ui->tab_conteneurs->setModel(C.afficher()) ;
}






void MainWindow::on_pushButton_modifier_clicked()
{

   int ID=ui->ID->text().toInt();
       QString etat = ui->etat->currentText();
       QString matiere = ui->matiere->text();
       int quantite=ui->quantite->text().toInt();
int s=ui->quantite->text().toInt();
int c=0;
          Conteneur C(ID,etat,quantite,matiere);
          /*if(C.idExist(ID)==false)

                {

              QMessageBox msgBox(QMessageBox::Warning, QObject::tr("ERREUR"), QObject::tr("id  n'existe pas"), QMessageBox::Ok);
              c++;
         msgBox.exec();

              }*/
          if(ui->ID->text().isEmpty())
          {QMessageBox msgBox(QMessageBox::Warning, QObject::tr("ERREUR"), QObject::tr("La quantite entre 0 et 10000\nCliquez sur OK pour quitter."), QMessageBox::Ok);
              QString styleSheet = "QMessageBox {"
                  "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                  "border: 2px outset grey;"
                  "}"
                  "QMessageBox QPushButton {"
                  "color: rgba(52,90,105,100%);"
                  "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                  "border-style: solid;"
                  "border: 2px solid transparent;"
                  "border-radius: 5px;"
                  "padding: 1px;"
                  "}"
                  "QMessageBox QPushButton:hover {"
                  "color: #B200ED ;"
                  "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 70%));"
                  "border-style: solid;"
                  "border: 2px solid transparent;"
                  "border-radius: 5px;"
                  "padding: 1px;"
                  "}";

              msgBox.setStyleSheet(styleSheet);

              msgBox.exec();
              c++;
  }
          if(ui->quantite->text().isEmpty())
                {

              QMessageBox msgBox(QMessageBox::Warning, QObject::tr("ERREUR"), QObject::tr("la quantite est vide"), QMessageBox::Ok);
              c++;
               msgBox.exec();
              }
          if(ui->matiere->text().isEmpty())
                {

              QMessageBox msgBox(QMessageBox::Warning, QObject::tr("ERREUR"), QObject::tr("la matiere est vide"), QMessageBox::Ok);
               msgBox.exec();
              c++;
              }
          if(s<0 || s>10000)
              {QMessageBox msgBox(QMessageBox::Warning, QObject::tr("ERREUR"), QObject::tr("La quantite entre 0 et 10000\nCliquez sur OK pour quitter."), QMessageBox::Ok);
                  QString styleSheet = "QMessageBox {"
                      "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                      "border: 2px outset grey;"
                      "}"
                      "QMessageBox QPushButton {"
                      "color: rgba(52,90,105,100%);"
                      "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                      "border-style: solid;"
                      "border: 2px solid transparent;"
                      "border-radius: 5px;"
                      "padding: 1px;"
                      "}"
                      "QMessageBox QPushButton:hover {"
                      "color: #B200ED ;"
                      "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 70%));"
                      "border-style: solid;"
                      "border: 2px solid transparent;"
                      "border-radius: 5px;"
                      "padding: 1px;"
                      "}";

                  msgBox.setStyleSheet(styleSheet);

                  msgBox.exec();
                  c++;

              }

  if(c==0)
    {
             bool test=C.modifier(ID) ;

             if(test)

           {ui->tab_conteneurs->setModel(C.afficher());

           QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),

                             QObject::tr("invite modifiée.\n"

                                         "Click ok to exit."), QMessageBox::Ok);
           ui->ID->clear();
           ui->quantite->clear();
           ui->matiere->clear();




           }

             else

                 QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),

                             QObject::tr("echec d'ajout !.\n"

                                         "Click Cancel to exit."), QMessageBox::Cancel);
}

}
/*

void MainWindow::on_comboBox_activated(const QString &arg1)

    {
        if(ui->comboBox->currentText()==" Quantite croissant")
                ui->tab_conteneurs->setModel(C.tri());
           else if(ui->comboBox->currentText()=="Quantité décroissante")
               ui->tab_conteneurs->setModel(C.tri());

    }




void MainWindow::on_lineEdit_rechercher_cursorPositionChanged(int arg1, int arg2)
{
    ui->tab_conteneurs->setModel(C.recherche(arg1));
}
}
*/
//rechercher
void MainWindow::RechercheID() {
    QString searchText = ui->lineEdit_rechercher->text();
    QSqlQuery query;
    query.prepare("SELECT * FROM CONTENEUR WHERE matiere LIKE :id");
    query.bindValue(":id", "%" + searchText + "%");

    if (query.exec()) {
        QSqlQueryModel *searchModel = new QSqlQueryModel(this);
        searchModel->setQuery(query);
        ui->tab_conteneurs->setModel(searchModel);
    }
}

bool MainWindow::RechercheID2() {
    QSqlQuery query;
    int id=ui->lineEdit_ID->text().toInt();
    query.prepare("SELECT COUNT(*) FROM conteneur  WHERE ID=:id");
    query.bindValue("id:",id);
    if (query.exec() && query.next())
     {
        int count=query.value(0).toInt();
        return count>0;
    }
      return false;
}


void MainWindow::on_pushButton_clicked()
{
    ui->tab_conteneurs->setModel(C.afficher1());
}

void MainWindow::on_pushButton_2_clicked()
{
   ui->tab_conteneurs->setModel(C.afficher());
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
        query.prepare("SELECT * FROM CONTENEUR");
        query.exec();
        QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tab_conteneurs->model());
        model->setQuery(query);

        if (model) {
            QString content;


                    for (int col = 0; col <model->columnCount(); ++col) {

                         content += model->headerData(col, Qt::Horizontal).toString();
                         if (col < model->columnCount()-3) {

                                     content += "\t";

                                 }

                         else

                         content += "\t \t \t \t \t ";
                            }
                    content += "\n";

                    for (int row = 0; row < model->rowCount(); ++row) {
                        for (int col = 0; col < model->columnCount(); ++col) {
                            content += model->data(model->index(row, col)).toString() + "\t";
                        }
                        content += "\n";
                    }


            QTextDocument document;
            document.setPlainText(content);

            QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "C:/Users/LENOVO/Desktop", "Fichiers PDF (*.pdf)");

            if (!fileName.isEmpty()) {

                QPrinter printer;
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName(fileName);


                document.print(&printer);

                QMessageBox msgBox(QMessageBox::Information, QObject::tr("Export PDF"), QObject::tr("Le PDF a été créé avec succès\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
                QString styleSheet = "QMessageBox {"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                    "border: 2px outset grey;"
                    "}"
                    "QMessageBox QPushButton {"
                    "color: rgba(52,90,105,100%);"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                    "border-style: solid;"
                    "border: 2px solid transparent;"
                    "border-radius: 5px;"
                    "padding: 1px;"
                    "}"
                    "QMessageBox QPushButton:hover {"
                    "color: #B200ED ;"
                    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 70%));"
                    "border-style: solid;"
                    "border: 2px solid transparent;"
                    "border-radius: 5px;"
                    "padding: 1px;"
                    "}";

                msgBox.setStyleSheet(styleSheet);

                msgBox.exec();
            }
        }
}
int MainWindow::countType(const QString& type)
{
    int count = 0;

    QSqlQuery query;
    qDebug()<<type;
    query.prepare("SELECT COUNT(\"ETAT\") FROM CONTENEUR WHERE \"ETAT\" = :type");
    query.bindValue(":type", type);

    if (query.exec() && query.next()) {
        qDebug()<<"VALUE: "<<query.value(0);
        count = query.value(0).toInt();
    }

    return count;
}
void MainWindow::on_pushButton_4_clicked()
{

           QList<QWidget*> childWidgets = ui->label_14->findChildren<QWidget*>();
               for (QWidget* childWidget : childWidgets) {
                   childWidget->deleteLater();
               }
           ui->label_14->hide();
           float s0,s1,s2;
           s0=countType("Vide");
           qDebug()<<"s0: "<<s0;
           s2=countType("Demi rempli");
            qDebug()<<"s1: "<<s2;
           s1=countType("Rempli");
            qDebug()<<"s2: "<<s2;
           float stat=s0+s1+s2;
           float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
           float y = (stat != 0) ? (s1 * 100) / stat : 0.0;
           float z = (stat != 0) ? (s2 * 100) / stat : 0.0;



           QString ch1=QString("vide:%1%").arg(x);
           QString ch2=QString("demi remplit:%1%").arg(z);
           QString ch3=QString("remplit:%1%").arg(y);

           QPieSeries *series=new QPieSeries();
           series->setHoleSize(0.39);
           QPieSlice *slice= series->append(ch1,x);
           slice->setLabelVisible();
           slice->setBrush(QColor(187,93,87));
           QPieSlice *slice1= series->append(ch2,z);
           slice1->setLabelVisible();
           slice1->setBrush(QColor(255,186,186));
           QPieSlice *slice2= series->append(ch3,y);
           slice2->setLabelVisible();
           slice2->setBrush(QColor(255,123,123));
           slice2->setLabelColor(QColor(Qt::black));
           QChart *chart=new QChart();
           chart->addSeries(series);
           chart->setAnimationOptions(QChart::AllAnimations);
           //chart->setTitle("Statistique Pour Nombre D'année D'experience");
           //chart->setTheme(QChart::ChartThemeHighContrast);
           QBrush backgroundBrush(QColor(187,93,87,0));
           chart->setBackgroundBrush(backgroundBrush);
           QChartView *chartview=new QChartView(chart);
           chartview->setRenderHint(QPainter::Antialiasing);
           chartview->setFixedSize(ui->label_14->size());
           chartview->setParent(ui->label_14);
           ui->label_14->show();

}



void MainWindow::on_EMAIL_clicked()
{
    Smtp smtpObject("marammelki12@gmail.com", "condition112277", "smtp.gmail.com", 465, 10000);
    smtpObject.sendMail("marammelki12@gmail.com", "maram.melki@esprit.tn", "Alerte dans la conteneur", "la conteneur num 3 ");
}
bool MainWindow::RechercheQuantiteUnder100() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM conteneur WHERE QUANTITE < 100");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}

