#include "add_pc.h"
#include "ui_add_pc.h"
#include "pointdecollect.h"
#include <QMessageBox>
#include <QIntValidator>
add_PC::add_PC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_PC)
{

    ui->setupUi(this);
    ui->lineEdit_idpc->setValidator(new QIntValidator(0, 9999999, this));
    ui->lineEdit_quntite->setValidator(new QIntValidator(0, 9999999, this));

}

add_PC::~add_PC()
{
    delete ui;
}

void add_PC::on_B_ajouter_accepted()
{

    int id=ui->lineEdit_idpc->text().toInt();
    QDate date= ui->dateEdit->date();
    QString lieu = ui->lineEdit_lieu->text();
    int quntte=ui->lineEdit_quntite->text().toInt();
    PointDeCollect p(id,date,lieu,quntte);
    bool test=p.ajouter();
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Add operation completed.\nClick Cancel to exit"),QMessageBox::Cancel);
        this->close();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Failed to add.\nClick Cancel to exit"), QMessageBox::Cancel);
    }


}

void add_PC::on_B_ajouter_rejected()
{
     this->close();
}
