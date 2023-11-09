#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "matiererecyclee.h"
#include "login.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QFileDialog>
#include <QSqlError>



MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/OneDrive/Bureau/img/LOGO");
    ui->label_pic->setPixmap(pix.scaled(150,150,Qt::KeepAspectRatio));
    ui->select_ID->setModel(mR.afficher());



}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_b_update_clicked()
{
    ui->table_matiereR->setModel(mR.afficher());
    ui->select_ID->setModel(mR.afficher());


}

void MainWindow::on_b_supp_p_clicked()
{
    matiereRecyclee m1;

    m1.setId_mr(ui->lineEdit_suppID->text().toInt());

    bool test=m1.supprimer(m1.getId_mr());
    QMessageBox msgBox;
    if(test)
    {
     msgBox.setText("suppression avec succes");
     ui->table_matiereR->setModel(mR.afficher());
     ui->select_ID->setModel(mR.afficher());

    }
    else
    {
     msgBox.setText("Echec de suppression");
    }
    ui->lineEdit_suppID->clear();

    msgBox.exec();
}



void MainWindow::on_save_clicked()
{
    int id=ui->lineEdit_setId->text().toInt();

    QString type1;
        if (ui->r_carton->isChecked()) {
            type1 = "Carton";
        } else if (ui->r_plastique->isChecked()) {
            type1 = "Plastique";
        } else if (ui->r_verre->isChecked()) {
            type1 = "Verre";
        } else {
            // Handle the case where no radio button is selected or an unknown option
            type1 = "Unknown";
        }

    QDate date=ui->dateEdit_DE->date();

    float pr=ui->lineEdit_prix->text().toFloat();

    int qt=ui->lineEdit_Quantite->text().toInt();

    matiereRecyclee m(id,type1,pr,date,qt);

   bool test=m.ajouter();
   ui->table_matiereR->setModel(mR.afficher());
   ui->select_ID->setModel(mR.afficher());


   if(test)
   { //RefreShe


       QMessageBox::information(nullptr, QObject::tr("database is open"),
                   QObject::tr("add is done.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
   else
       QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                   QObject::tr("add isn't done.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}




void MainWindow::on_tabWidget_2_currentChanged()
{
    ui->table_matiereR->setModel(mR.afficher());
    ui->select_ID->setModel(mR.afficher());


}



void MainWindow::on_Binit_clicked()
{
    // Clear line edits
    ui->lineEdit_setId->clear();
    ui->lineEdit_prix->clear();
    ui->lineEdit_Quantite->clear();

    // Reset the date picker
    ui->dateEdit_DE->setDate(QDate::currentDate()); // Set it to the current date or your desired default date
}


void MainWindow::on_b_modif_clicked()
{
            QMessageBox msgBox;
            int id=ui->lineEdit_setId->text().toInt();

            QString type1;
                if (ui->r_carton->isChecked()) {
                    type1 = "Carton";
                } else if (ui->r_plastique->isChecked()) {
                    type1 = "Plastique";
                } else if (ui->r_verre->isChecked()) {
                    type1 = "Verre";
                } else {
                    // Handle the case where no radio button is selected or an unknown option
                    type1 = "Unknown";
                }

            QDate date=ui->dateEdit_DE->date();

            float pr=ui->lineEdit_prix->text().toFloat();

            int qt=ui->lineEdit_Quantite->text().toInt();

            matiereRecyclee m(id,type1,pr,date,qt);

           bool test=m.modif();

            if (test)
            msgBox.setText("modifier avec succe");
            else
                msgBox.setText("Echec de modifier");
            msgBox.exec();


}

void MainWindow::on_Btri_clicked()
{
  ui->table_matiereR->setModel(mR.sortTableByQTT());


}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    QSqlQueryModel *model = new QSqlQueryModel();
       model->setQuery("SELECT ID_MR, TYPE_PROD, PRIX, DATE_ENTREE, QUANTITÉS FROM matiere_recyclee WHERE TYPE_PROD LIKE '%" + arg1 + "%' OR ID_MR LIKE '%" + arg1 + "%' OR PRIX LIKE '%" + arg1 + "%' OR DATE_ENTREE LIKE '%" + arg1 + "%' OR QUANTITÉS LIKE '%" + arg1 + "%'");
       ui->table_matiereR->setModel(model);
}

void MainWindow::on_b_convPDF_clicked()
{
        QString fileName = QFileDialog::getSaveFileName(this, "Export PDF",
                                                        QString(), "*.pdf");
        if (!fileName.isEmpty()) {
            if (QFileInfo(fileName).suffix().isEmpty()) {
                fileName.append(".pdf");
            }

            QPdfWriter writer(fileName);
            QPainter painter(&writer);

            int rowCount = ui->table_matiereR->model()->rowCount();
            int columnCount = ui->table_matiereR->model()->columnCount();

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
                if (!ui->table_matiereR->isColumnHidden(column))
                    out << QString("<th width='%1%'>%2</th>").arg(100/columnCount).arg(ui->table_matiereR->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->table_matiereR->isColumnHidden(column)) {
                        QString data = ui->table_matiereR->model()->data(ui->table_matiereR->model()->index(row, column)).toString().simplified();
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



void MainWindow::on_select_ID_currentIndexChanged()
{

        QString id_M = ui->select_ID->currentText();
        QSqlQuery query;
        query.prepare("SELECT * FROM matiere_recyclee WHERE ID_MR='" + id_M + "'");

        if(query.exec())
        {
            while(query.next())
            {
                ui->lineEdit_setId->setText(query.value(0).toString());
                QString type = query.value(1).toString().trimmed();  // Remove trailing spaces
                qDebug() << "Type: " << type;  // Print out the type value

                if (type == "Carton") {
                    ui->r_carton->setChecked(true);
                } else if (type == "Plastique") {
                    ui->r_plastique->setChecked(true);
                } else if (type == "Verre") {
                    ui->r_verre->setChecked(true);
                }

                ui->lineEdit_prix->setText(query.value(2).toString());
                ui->dateEdit_DE->setDate(query.value(3).toDate());
                ui->lineEdit_Quantite->setText(query.value(4).toString());
            }
        }



}
