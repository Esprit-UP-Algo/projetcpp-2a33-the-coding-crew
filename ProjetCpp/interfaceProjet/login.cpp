#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <string>
#include <QMessageBox>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_confirmer_login_clicked()
{
QString UserName = ui -> lineEdit_username->text();
QString Password= ui-> lineEdit_password -> text();
if(UserName== "gestionmr" && Password == "1234")
{
    QMessageBox::information(this,"Connecté","Connecté");
    this->hide();
    MainWindow *mainpage=new MainWindow();
    mainpage->show();

}
else
{
    QMessageBox::warning(this,"noon","please enter valid username or password");
}
}

void login::on_annuler_login_clicked()
{
    QMessageBox::StandardButton reply;

    reply= QMessageBox::question(this,"close?","are you sure to close the app?");
    if(reply==QMessageBox::Yes)
    {
QApplication::quit();
    }
}
