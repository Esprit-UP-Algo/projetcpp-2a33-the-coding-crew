#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "pointdecollect.h"
#include "add_pc.h"
#include "modifier_pc.h"
#include "connect.h"
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>
#include<QStringList>
#include <QRegExp>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTextStream>
#include <QTextDocument>
#include <QSortFilterProxyModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/OneDrive/Bureau/img/LOGO");
    ui->label_pic->setPixmap(pix.scaled(150,150,Qt::KeepAspectRatio));
    PointDeCollect p1;
    ui->comboBox_ID->setModel(p.afficher());
    ui->tableView_ID->setModel(p.afficherID());
    ui->tab_PC->setModel(p.afficher());




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_B_ajouter_clicked()
{
    int id=ui->lineEdit_idpc->text().toInt();
    QDate date= ui->dateEdit->date();
    QString lieu = ui->lineEdit_lieu->text();
    int quntte=ui->lineEdit_quntite->text().toInt();
    PointDeCollect p(id,date,lieu,quntte);
    bool test=p.ajouter();
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Add operation completed.\nClick Cancel to exit"),QMessageBox::Cancel);

    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Failed to add.\nClick Cancel to exit"), QMessageBox::Cancel);
    }

}

void MainWindow::on_B_supp_clicked()
{
    PointDeCollect p1;

    p1.setid(ui->lineEdit_idpc->text().toInt());
    bool test= p.supprime(ui->lineEdit_idpc->text().toInt());
    QMessageBox msgBox;
    if (test)
        msgBox.setText("suppreme avec succe");
     else
        msgBox.setText("no suppreme ");
    msgBox.exec();
}

void MainWindow::on_B_modifier_clicked()
{
    QMessageBox msgBox;
    int id=ui->lineEdit_idpc->text().toInt();
    QDate date= ui->dateEdit->date();
    QString lieu = ui->lineEdit_lieu->text();
    int quntite=ui->lineEdit_quntite->text().toInt();
    PointDeCollect p(id,date,lieu,quntite);
    bool test=p.modifier();

    if (test)
    msgBox.setText("modifier avec succe");
    else
        msgBox.setText("no modifier XD  ");
    msgBox.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->tab_PC->setModel(p.afficher());
    ui->tableView_ID->setModel(p.afficherID());
    ui->comboBox_ID->setModel(p.afficherID());\
    ui->tab_PC->setModel(p.tier_lieu());
}

void MainWindow::on_comboBox_ID_currentIndexChanged(const QString &arg1)
{
    QMessageBox msgBox;
    QString id_pc= ui->comboBox_ID->currentText();

    QSqlQuery qry;

          qry.prepare("SELECT * FROM points_de_collectes where id_pc='"+id_pc+"' ");
          if (qry.exec())
          {
              while (qry.next())
              {
                  ui->lineEdit_idpc->setText(qry.value(0).toString());
                  ui->lineEdit_lieu->setText(qry.value(1).toString());
                  ui->dateEdit->setDate(qry.value(2).toDate());
                  ui->lineEdit_quntite->setText(qry.value(3).toString());
              }

          }
          else
          {
              msgBox.setText("no  XD  ");
          }
          //ui->comboBox_ID->setModel(p.afficherID());
}


void MainWindow::on_lineEdit_RE_textChanged(const QString &arg1)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PC,LIEU,DAT_PC,QUNTITER FROM points_de_collectes WHERE ID_PC LIKE '%" + arg1 + "%' ");
    ui->tableView_ID->setModel(model);
}


void MainWindow::on_b_trier_clicked()
{
    ui->tab_PC->setModel(p.tier_lieu());
}

void MainWindow::on_lineEdit__textChanged(const QString &arg1)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PC,LIEU,DAT_PC,QUNTITER FROM points_de_collectes WHERE ID_PC LIKE '%" + arg1 + "%' OR LIEU LIKE '%" + arg1 + "%' OR DAT_PC LIKE '%" + arg1 + "%' OR QUNTITER LIKE '%" + arg1 + "%'");
    ui->tab_PC->setModel(model);

}

void MainWindow::on_B_convPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export PDF",
                                                            QString(), "*.pdf");
            if (!fileName.isEmpty()) {
                if (QFileInfo(fileName).suffix().isEmpty()) {
                    fileName.append(".pdf");
                }

                QPdfWriter writer(fileName);
                QPainter painter(&writer);

                int rowCount = ui->tab_PC->model()->rowCount();
                int columnCount = ui->tab_PC->model()->columnCount();

                QString strStream;
                QTextStream out(&strStream);

                out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("TITLE")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<style> table { font-size: 20px; } </style>\n"  // Adjust the font size here
                    "<table border=1 cellspacing=0 cellpadding=2 width='100%'>\n";

                // headers
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_PC->isColumnHidden(column))
                        out << QString("<th width='%1%'>%2</th>").arg(100/columnCount).arg(ui->tab_PC->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_PC->isColumnHidden(column)) {
                            QString data = ui->tab_PC->model()->data(ui->tab_PC->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0 width='%1%'>%2</td>").arg(100/columnCount).arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                // Scale the painter
                double scale = 15.0;  // Adjust the scale factor here
                painter.scale(scale, scale);

                document->drawContents(&painter);

                delete document;
            }
}


void MainWindow::on_tableView_ID_activated(const QModelIndex &index)
{
     QMessageBox msgBox;
    QString id=ui->tableView_ID->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM points_de_collectes where id_pc='"+id+"' ");
    if (qry.exec())
    {
        while (qry.next())
        {
            ui->lineEdit_idpc->setText(qry.value(0).toString());
            ui->lineEdit_lieu->setText(qry.value(1).toString());
            ui->dateEdit->setDate(qry.value(2).toDate());
            ui->lineEdit_quntite->setText(qry.value(3).toString());
        }

    }
    else
    {
        msgBox.setText("no  XD  ");
    }



}
