#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mainwindow.h"
#include "pointdecollect.h"
#include "add_pc.h"
#include "modifier_pc.h"
#include "connect.h"
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/OneDrive/Bureau/img/LOGO");
    ui->label_pic->setPixmap(pix.scaled(150,150,Qt::KeepAspectRatio));
    ui->tab_PC->setModel(p.afficher());



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_B_ajouter_clicked()
{
    add_PC a;
    a.exec();

}

void MainWindow::on_B_supp_clicked()
{
    PointDeCollect p1;

    p1.setid(ui->lineEdit_supp->text().toInt());
    bool test= p.supprime(p1.getid());
    QMessageBox msgBox;
    if (test)
        msgBox.setText("suppreme avec succe");
     else
        msgBox.setText("no suppreme ");
    msgBox.exec();
}

void MainWindow::on_B_modifier_clicked()
{
    modifier_PC a;
    a.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->tab_PC->setModel(p.afficher());
}
