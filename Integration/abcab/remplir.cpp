#include "remplir.h"
#include "ui_remplir.h"
#include "conteneur.h"
#include <QMessageBox>
remplir::remplir(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::remplir)
{
    Conteneur C;
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(on_push_id_2_clicked())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

}

remplir::~remplir()
{
    delete ui;
}




void remplir::on_push_id_2_clicked()
{
    int id=ui->line_id->text().toInt() ;

    Conteneur C;
   data=A.read_from_arduino();
  if(C.doesIDExist(id))
  {
   if(data=="1")
    {
      qDebug() << "avec succes";
      QMessageBox::critical(nullptr, QObject::tr("Full"),
                   QObject::tr("conteneur est rempli.\n"
                                 ));
      C.supprimerC(id);
   }
  }else
  {
      qDebug() << "Id n'existe pas";

  }
}
