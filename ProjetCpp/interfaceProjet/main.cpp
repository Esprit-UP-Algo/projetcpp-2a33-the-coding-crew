#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connect.h"
#include "login.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    login l;
    Connection c;


    bool test=c.createconnect();
    if(test)
    {l.show(); //w.show();
       // ui->table_matiereR->setModel(mR.afficher());

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
