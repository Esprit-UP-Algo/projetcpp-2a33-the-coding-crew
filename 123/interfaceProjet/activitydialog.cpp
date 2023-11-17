#include "activitydialog.h"
#include "ui_activitydialog.h"

activitydialog::activitydialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::activitydialog)
{
    ui->setupUi(this);
}

activitydialog::~activitydialog()
{
    delete ui;
}
