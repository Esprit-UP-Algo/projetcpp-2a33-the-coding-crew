#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QLineEdit>
#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include <QMessageBox>
#include <QChartView>
#include <QPieSlice>
#include <QPieSeries>
#include <iostream>
#include <QChart>
#include <QSqlQuery>
using namespace std;
using namespace QtCharts;
MainWindow::MainWindow(QWidget *matricule)
    : QMainWindow(matricule)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_vehicules->setModel(V.afficher());
    connect(ui->texte_recherche,&QLineEdit::textChanged,this,&MainWindow::on_texte_recherche_textChanged);
    ui->label_32->hide();

    ui->lineEdit_Cap->setValidator(new QIntValidator(100,9999,this));
     ui->lineEdit_ID->setValidator(new QIntValidator(100,9999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int capacite=ui->lineEdit_Cap->text().toInt();
    int idc=ui->lineEdit_ID->text().toInt();
    QString matricule=ui->lineEdit_mat->text();
    QDate date=ui->lineEdit_Date->date();


vehicules v;

int c=0;
if(v.matExists(matricule)==false)
{
  c++;
  QMessageBox::information(nullptr, QObject::tr("erreur dans la matricule"),QObject::tr("existe "), QMessageBox::Cancel);

  }
if(ui->lineEdit_mat->text().isEmpty())
  {
    c++;
    QMessageBox::information(nullptr, QObject::tr("erreur dans la matricule"),QObject::tr("donner matricule"), QMessageBox::Cancel);

    }

if(capacite!=1000 || capacite!=2000 ||capacite!=3000 ||capacite!=4000 ||capacite!=5000 ||capacite!=6000 )
{
c++;
QMessageBox::information(nullptr, QObject::tr("erreur dans la capacite"),QObject::tr("donner 1000 ou 2000 ou 3000 ou 4000 ou 5000 ou 6000"), QMessageBox::Cancel);
}
if(c==0) {
   bool test =v.ajouter(capacite,date,idc,matricule);
    if(test)
             {QMessageBox::information(nullptr, QObject::tr(""),QObject::tr("ajout avec succes"), QMessageBox::Cancel);
    ui->lineEdit_Cap->clear();
        ui->lineEdit_ID->clear();
                ui->lineEdit_mat->clear();
                ui->lineEdit_Date->clear();
        }

        ui->tab_vehicules->setModel(V.afficher());
        }
}

void MainWindow::on_pushButton_3_clicked()
{
    vehicules vs;
    QString matricule =ui->lineEdit_sup->text();
    bool test = vs.supprimer(matricule);
    if(test)
             {QMessageBox::information(nullptr, QObject::tr(""),QObject::tr("suppression avec succes"), QMessageBox::Cancel);
    ui->lineEdit_sup->clear();
    }
    ui->tab_vehicules->setModel(V.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{

    bool test;
    float capacite=ui->lineEdit_Cap->text().toInt();
    float idc=ui->lineEdit_ID->text().toInt();
    QString matricule=ui->lineEdit_mat->text();
    QDate date=ui->lineEdit_Date->date();
    vehicules v(capacite,date,idc,matricule);
    int c=0;
    if(v.matExists(matricule)==false)
    {
      c++;
      QMessageBox::information(nullptr, QObject::tr("erreur dans la matricule"),QObject::tr("n'existe pas"), QMessageBox::Cancel);

      }
    if(ui->lineEdit_mat->text().isEmpty())
      {
        c++;
        QMessageBox::information(nullptr, QObject::tr("erreur dans la matricule"),QObject::tr("donner matricule"), QMessageBox::Cancel);

        }
if(capacite!=1000 || capacite!=2000 ||capacite!=3000 ||capacite!=4000 ||capacite!=5000 ||capacite!=6000 )
  {
    c++;
    QMessageBox::information(nullptr, QObject::tr("erreur dans la capacite"),QObject::tr("donner 1000 ou 2000 ou 3000 ou 4000 ou 5000 ou 6000"), QMessageBox::Cancel);
  }

if(c==0) { test=v.modifier(matricule);
    if(test)
             {QMessageBox::information(nullptr, QObject::tr(""),QObject::tr("modification avec succes"), QMessageBox::Cancel);
        ui->lineEdit_Cap->clear();
            ui->lineEdit_ID->clear();
                    ui->lineEdit_mat->clear();
                    ui->lineEdit_Date->clear();
    }
    ui->tab_vehicules->setModel(V.afficher());

}}

void MainWindow::on_texte_recherche_textChanged(const QString &var)
{


            QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("SELECT * FROM GESTION_VEHICULE WHERE MATRICULE LIKE '%" + var + "%'");
         if(model->rowCount()>0)
           { ui->tab_vehicules->setModel(model); }

         if(model->rowCount()==0)
           { ui->tab_vehicules->setModel(model);
             QMessageBox::information(nullptr, QObject::tr("error"),QObject::tr("matricule n'existe pas "), QMessageBox::Cancel);
             ui->texte_recherche->clear();
         }

         QHeaderView* headerView = ui->tab_vehicules->horizontalHeader();
         headerView->setSectionResizeMode(QHeaderView::Stretch);

}

void MainWindow::on_TRI_clicked()
{
     vehicules v;
    QSqlQueryModel* model=v.tri();

    ui->tab_vehicules->setModel(model);

}

void MainWindow::on_PDF_clicked()
{


    // Associez le modèle à votre QTableView

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tab_vehicules->model());

    if (model) {
        QString content;
        //header
        for (int col = 0; col < model->columnCount(); ++col) {

             content += model->headerData(col, Qt::Horizontal).toString() + "\t ";

                }
        content += "\n";
        // Parcourez les données du modèle et ajoutez-les au contenu
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                content += model->data(model->index(row, col)).toString() + "\t";
            }
            content += "\n";
        }

        // Créez un objet QTextDocument et définissez son contenu
        QTextDocument document;
        document.setPlainText(content);

        // Créez un dialogue pour sélectionner l'emplacement de sauvegarde du PDF.
        QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "C:/Users/karim NAHDI/Desktop/vehicule", "Fichiers PDF (*.pdf)");

        if (!fileName.isEmpty()) {
            // Créez un objet QPrinter pour générer le PDF.
            QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);

            // Imprimez le document sur le PDF.
            document.print(&printer);

            // Affichez un message à l'utilisateur pour confirmer l'exportation réussie.
            QMessageBox::information(this, "Export PDF", "Le PDF a été créé avec succès.");
        }
    }
}
int MainWindow::count1()
{   int s = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(CAPACITE) FROM GESTION_VEHICULE WHERE CAPACITE =1000");

    if (query.exec()) {
        if (query.next()) {
            s = query.value(0).toInt();

            std::cout << "La valeur s3 est : " << s << std::endl;
        } else {
            std::cout << "Aucun enregistrement n'a été trouvé." << std::endl;
        }
    } else {
        std::cout << "Erreur lors de l'exécution de la requête." << std::endl;
    }

    return s;
}
int MainWindow::count2()
{   int s = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(CAPACITE) FROM GESTION_VEHICULE WHERE CAPACITE =2000");

    if (query.exec()) {
        if (query.next()) {
            s = query.value(0).toInt();

            std::cout << "La valeur s3 est : " << s << std::endl;
        } else {
            std::cout << "Aucun enregistrement n'a été trouvé." << std::endl;
        }
    } else {
        std::cout << "Erreur lors de l'exécution de la requête." << std::endl;
    }

    return s;
}
int MainWindow::count3()
{   int s = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(CAPACITE) FROM GESTION_VEHICULE WHERE CAPACITE =3000");

    if (query.exec()) {
        if (query.next()) {
            s = query.value(0).toInt();

            std::cout << "La valeur s3 est : " << s << std::endl;
        } else {
            std::cout << "Aucun enregistrement n'a été trouvé." << std::endl;
        }
    } else {
        std::cout << "Erreur lors de l'exécution de la requête." << std::endl;
    }

    return s;
}
int MainWindow::count4()
{   int s = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(CAPACITE) FROM GESTION_VEHICULE WHERE CAPACITE = 4000");

    if (query.exec()) {
        if (query.next()) {
            s = query.value(0).toInt();

            std::cout << "La valeur s3 est : " << s << std::endl;
        } else {
            std::cout << "Aucun enregistrement n'a été trouvé." << std::endl;
        }
    } else {
        std::cout << "Erreur lors de l'exécution de la requête." << std::endl;
    }

    return s;
}
int MainWindow::count5()
{   int s = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(CAPACITE) FROM GESTION_VEHICULE WHERE CAPACITE = 5000");

    if (query.exec()) {
        if (query.next()) {
            s = query.value(0).toInt();

            std::cout << "La valeur s3 est : " << s << std::endl;
        } else {
            std::cout << "Aucun enregistrement n'a été trouvé." << std::endl;
        }
    } else {
        std::cout << "Erreur lors de l'exécution de la requête." << std::endl;
    }

    return s;
}
int MainWindow::count6()
{   int s = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(CAPACITE) FROM GESTION_VEHICULE WHERE CAPACITE =6000");

    if (query.exec()) {
        if (query.next()) {
            s = query.value(0).toInt();

            std::cout << "La valeur s3 est : " << s << std::endl;
        } else {
            std::cout << "Aucun enregistrement n'a été trouvé." << std::endl;
        }
    } else {
        std::cout << "Erreur lors de l'exécution de la requête." << std::endl;
    }

    return s;
}
void MainWindow::on_STAT_clicked()
{

        QList<QWidget*> childWidgets = ui->label_32->findChildren<QWidget*>();
            for (QWidget* childWidget : childWidgets) {
                childWidget->deleteLater();

            }
            //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
            ui->label_32->clear();
            ui->label_32->hide();

        int s1, s2, s3, s4,s5,s6;

        s1 = count1();
        s2 = count2();
        s3 = count3();
        s4 = count4();
    s5 = count5();
  s6 = count6();

        int stat = s1 + s2 + s3 + s4 + s5+ s6 ;
        float x1 = (stat != 0) ? (s1 * 100) / stat : 0.0;
        float x2 = (stat != 0) ? (s2 * 100) / stat : 0.0;
        float x3 = (stat != 0) ? (s3 * 100) / stat : 0.0;
        float x4 = (stat != 0) ? (s4 * 100) / stat : 0.0;
        float x5 = (stat != 0) ? (s5 * 100) / stat : 0.0;
        float x6 = (stat != 0) ? (s6 * 100) / stat : 0.0;

        QString ch1 = QString("CAPACITE1 %1%").arg(QString::number(x1));
        QString ch2 = QString("CAPACITE2 %2%").arg(QString::number(x2));
        QString ch3 = QString("CAPACITE3 %3%").arg(QString::number(x3));
      QString ch4 = QString("CAPACITE4 %4%").arg(QString::number(x4));
QString ch5 = QString("CAPACITE5 %4%").arg(QString::number(x5));
QString ch6 = QString("CAPACITE6 %4%").arg(QString::number(x6));

        QPieSeries *series=new QPieSeries();
        series->setHoleSize(0.35);



        QPieSlice *slice1= series->append(ch1,x1);
        slice1->setLabelVisible();
        slice1->setLabelColor(QColor("#FFFFFF"));
            slice1->setBrush(QColor(189, 76, 224, 1)); //couleur ici
        QPieSlice *slice2= series->append(ch2,x2);
        slice2->setLabelVisible();
        slice2->setLabelColor(QColor("#FFFFFF"));
        slice2->setBrush(QColor(84, 16, 149, 1));
        QPieSlice *slice3= series->append(ch3,x3);
        slice2->setLabelVisible();

        slice3->setLabelColor(QColor(Qt::white));
        slice3->setBrush(QColor(119, 82, 254));
        QPieSlice *slice4= series->append(ch4,x4);
        slice4->setLabelVisible();
        slice4->setLabelColor(QColor(Qt::white));
        slice4->setBrush(QColor(77, 76, 125));
        QPieSlice *slice5= series->append(ch5,x5);
        slice5->setLabelVisible();
        slice5->setLabelColor(QColor(Qt::white));
        slice5->setBrush(QColor(Qt::blue));
        QPieSlice *slice6= series->append(ch6,x6);
        slice6->setLabelVisible();
        slice6->setLabelColor(QColor(Qt::white));
        slice6->setBrush(QColor(Qt::red));


        QChart *chart=new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QBrush backgroundBrush(QColor(187,93,87,0));
        chart->setBackgroundBrush(backgroundBrush);
        QChartView *chartview=new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setFixedSize(ui->label_32->size());
        chartview->setParent(ui->label_32);
      ui->label_32->setStyleSheet("background:transparent; color:white; ");
        ui->label_32->show();


}

