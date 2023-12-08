#include "mainwindow.h"
#include "vehicules.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;

    if(test)
      {
        w.show();
          QMessageBox::information(nullptr, QObject::tr("database is open"),QObject::tr("connection sucessful.\n""click cancel to exist."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),QObject::tr("connection failed.\n""click cancel to exist."), QMessageBox::Cancel);
    }
    w.show();


    return a.exec();
}
