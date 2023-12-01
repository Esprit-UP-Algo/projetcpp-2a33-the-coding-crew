#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "matiererecyclee.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QFileDialog>
#include <QSqlError>


#include <QPieSeries>
#include <QPieSlice>
#include <QChart>
#include <QChartView>


#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMouseEvent>
#include <QScrollArea>
#include <QImageWriter>
#include <QScrollBar>
#include <QSettings>
#include <QApplication>
#include <QDebug>
#include "qrcodegen.h"

#include <QMap>

const QString getIniPath()
{
    const static QString iniPath( qApp->applicationDirPath() + "/settings.ini" );
    return iniPath;
}
QString saveFormats()
{
    static QString suffix;
    foreach ( const QByteArray & format , QImageWriter::supportedImageFormats() )
        suffix += QString( "%1 ( *.%2 )\n" )
                .arg( QString( format ).toUpper() )
                .arg( QString( format ) );

    return suffix;
}

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) , ui(new Ui::MainWindow)  , successfulEncoding(false)

{
    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/OneDrive/Bureau/img/LOGO");
    ui->label_pic->setPixmap(pix.scaled(150,150,Qt::KeepAspectRatio));
    //ui->select_ID->setModel(mR.afficher());
    //ui->table_matiereR->setModel(mR.afficher());
    ui->stackedWidget->setCurrentIndex(0);

ui->lineEdit_setId->setValidator(new QIntValidator(0,999999,this));
ui->lineEdit_prix->setValidator(new QIntValidator(0,999999,this));
ui->lineEdit_Quantite->setValidator(new QIntValidator(0,999999,this));

ui->scrollArea->installEventFilter( this );

QSettings ini( getIniPath(), QSettings::IniFormat );
ui->splitter_2->restoreState( ini.value( ui->splitter_2->objectName() ).toByteArray() );
ui->splitter->restoreState( ini.value( ui->splitter->objectName() ).toByteArray() );
ui->sBoxScale->setValue( ini.value( ui->sBoxScale->objectName(), 4 ).toInt() );
restoreState( ini.value( "State" ).toByteArray() );
restoreGeometry( ini.value( "Geometry" ).toByteArray() );

setScale( ui->sBoxScale->value() );
updateQRImage();
ProdStatisticsChartView=nullptr;

//arduino

int ret=A.connect_arduino();
switch (ret)
{case(0):qDebug()<<"arduino is available and connected to: "<<A.getarduino_port_name();
    break;
  case(1):qDebug()<<"arduino is available but not connected to: "<<A.getarduino_port_name();
    break;
case(-1):qDebug()<<"arduino is not available ";
}
//QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}


MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_b_update_clicked()
{
    ui->table_matiereR->setModel(mR.afficher());
    ui->select_ID->setModel(mR.afficher());

    ui->select_id2->setModel(mR.afficher());

}




void MainWindow::on_b_supp_p_clicked()
{
    matiereRecyclee m1;

    m1.setId_mr(ui->lineEdit_suppID->text().toInt());

    bool test=m1.supprimer(m1.getId_mr());
    QMessageBox msgBox;
    if(test)
    {
     msgBox.setText("suppression avec succès");
     ui->table_matiereR->setModel(mR.afficher());
     ui->select_ID->setModel(mR.afficher());
     ui->select_id2->setModel(mR.afficher());

    }
    else
    {
     msgBox.setText("l'identifiant n'existe pas");
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
    ui->select_id2->setModel(mR.afficher());

    ui->lineEdit_setId->clear();
    ui->lineEdit_prix->clear();
    ui->lineEdit_Quantite->clear();
    ui->lineEdit_setId->setReadOnly(false);

    ui->dateEdit_DE->setDate(QDate::currentDate());


   if(test)
   { //RefreShe


       QMessageBox::information(nullptr, QObject::tr("database is open"),
                   QObject::tr("un nouveau produit a été ajouté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
   else
       QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                   QObject::tr("L'identifiant existe déjà.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_Binit_clicked()
{
    ui->lineEdit_setId->clear();
    ui->lineEdit_prix->clear();
    ui->lineEdit_Quantite->clear();
    ui->lineEdit_setId->setReadOnly(false);

    ui->dateEdit_DE->setDate(QDate::currentDate());
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


            if(test)
            { //RefreShe


                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("modification avec succès.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

         }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("L'identifiant n'existe pas.\n"
                                        "Click Cancel to exit."), QMessageBox::Ok);
}



            ui->table_matiereR->setModel(mR.afficher());

            ui->lineEdit_setId->clear();
            ui->lineEdit_prix->clear();
            ui->lineEdit_Quantite->clear();
            ui->lineEdit_setId->setReadOnly(false);

            ui->dateEdit_DE->setDate(QDate::currentDate());



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
        QString fileName = QFileDialog::getSaveFileName(this, "Export PDF",QString(), "*.pdf");
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

            // scale the painter
            double scale = 15.0;
            painter.scale(scale, scale);

            document->drawContents(&painter);

            delete document;
        }


}



void MainWindow::on_select_ID_currentIndexChanged(QString id_M)
{

    /*QString*/ id_M = ui->select_ID->currentText();
    ui->lineEdit_setId->setReadOnly(true);

        QSqlQuery query;
        query.prepare("SELECT * FROM matiere_recyclee WHERE ID_MR='" + id_M + "'");

        if(query.exec())
        {
            while(query.next())
            {
                ui->lineEdit_setId->setText(query.value(0).toString());
                QString type = query.value(1).toString().trimmed();  // it removes the trailing spaces
                qDebug() << "Type: " << type;  // print out the type value

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






void MainWindow::on_confirmer_login_clicked()
{
    QString UserName = ui -> lineEdit_username->text();
    QString Password= ui-> lineEdit_password -> text();

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYEE WHERE ADRESSE_EMAIL = :username AND PASSWORD = :password");
    query.bindValue(":username", UserName);
    query.bindValue(":password", Password);

    if (query.exec() && query.next()) {
        QMessageBox::information(this,"CONNECTED","Connecté");
        clearProdStatisticsChart();
        updateProdStatisticsChart();


        ui->stackedWidget->setCurrentIndex(1);
        ui->select_ID->setModel(mR.afficher());
        ui->select_id2->setModel(mR.afficher());
        ui->table_matiereR->setModel(mR.afficher());
        ui->lineEdit_setId->clear();
        ui->lineEdit_prix->clear();
        ui->lineEdit_Quantite->clear();
        ui->lineEdit_setId->setReadOnly(false);

        ui->dateEdit_DE->setDate(QDate::currentDate());    }
    else {
        QMessageBox::warning(this,"INVALID","veuillez entrer un nom d'utilisateur ou un mot de passe valide");
    }
}



void MainWindow::on_annuler_login_clicked()
{
    QMessageBox::StandardButton reply;

    reply= QMessageBox::question(this,"close?","are you sure to close the app?");
    if(reply==QMessageBox::Yes)
    {
QApplication::quit();
    }
}




void MainWindow::updateQRImage()
{
    int sizeText = ui->pTextEditQRText->toPlainText().size();
    ui->labelSizeText->setText( QString::number( sizeText ) );

    int levelIndex = 1;
    int versionIndex = 0;
    bool bExtent = true;
    int maskIndex = -1;
    QString encodeString = ui->pTextEditQRText->toPlainText();

    successfulEncoding = qrEncode.EncodeData( levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data() );
    if ( !successfulEncoding )
    {
        ui->image_label->clear();
        ui->image_label->setText( tr("QR Code...") );
        ui->labelSize->clear();
        ui->pButtonSave->setEnabled( successfulEncoding );
        return;
    }

    int qrImageSize = qrEncode.m_nSymbleSize;

    encodeImageSize = qrImageSize + ( QR_MARGIN * 2 );
    QImage encodeImage( encodeImageSize, encodeImageSize, QImage::Format_Mono );
    encodeImage.fill( 1 );

    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncode.m_byModuleData[i][j] )
                encodeImage.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    ui->image_label->setPixmap( QPixmap::fromImage( encodeImage ) );

    setScale(ui->sBoxScale->value());
    ui->pButtonSave->setEnabled( successfulEncoding );
}
void MainWindow::setScale(int scale)
{
    if ( successfulEncoding )
    {
        int scale_size = encodeImageSize * scale;

        const QPixmap & scale_image = ui->image_label->pixmap()->scaled( scale_size, scale_size );
        ui->image_label->setPixmap( scale_image );

        const QString & size_info = QString( "%1x%2" ).arg( scale_size ).arg( scale_size );
        ui->labelSize->setText( size_info );
    }
}

void MainWindow::on_pButtonSave_clicked()
{
    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcode", saveFormats() );
    if ( path.isNull() )
        return;

    ui->image_label->pixmap()->save( path );
}
void MainWindow::on_sBoxScale_valueChanged(int arg1)
{
    setScale( arg1 );
}
void MainWindow::on_pTextEditQRText_textChanged()
{
    updateQRImage();
}
void MainWindow::on_pButtonQuit_clicked()
{
ui->pTextEditQRText->clear();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    QSettings ini( getIniPath(), QSettings::IniFormat );
    ini.setValue( ui->splitter->objectName(), ui->splitter->saveState() );
    ini.setValue( ui->splitter_2->objectName(), ui->splitter_2->saveState() );
    ini.setValue( ui->sBoxScale->objectName(), ui->sBoxScale->value() );
    ini.setValue( "State", saveState() );
    ini.setValue( "Geometry", saveGeometry() );

    qApp->quit();
}
bool MainWindow::eventFilter( QObject * object, QEvent * event )
{
    QScrollArea * scrollArea = ui->scrollArea;

    if ( object == scrollArea )
    {
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent * mouseEvent = static_cast < QMouseEvent * > ( event );
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                lastPos = mouseEvent->pos();

                if( scrollArea->horizontalScrollBar()->isVisible()
                        || scrollArea->verticalScrollBar()->isVisible() )
                    scrollArea->setCursor( Qt::ClosedHandCursor );
                else
                    scrollArea->setCursor( Qt::ArrowCursor );
            }

        }else if ( event->type() == QEvent::MouseMove )
        {
            QMouseEvent *mouseEvent = static_cast < QMouseEvent * > ( event );

            if ( mouseEvent->buttons() == Qt::LeftButton )
            {
                lastPos -= mouseEvent->pos();

                int hValue = scrollArea->horizontalScrollBar()->value();
                int vValue = scrollArea->verticalScrollBar()->value();

                scrollArea->horizontalScrollBar()->setValue( lastPos.x() + hValue );
                scrollArea->verticalScrollBar()->setValue( lastPos.y() + vValue );

                lastPos = mouseEvent->pos();
            }

        }else if ( event->type() == QEvent::MouseButtonRelease )
            scrollArea->setCursor( Qt::ArrowCursor );
    }

    return QWidget::eventFilter(object, event);
}



void MainWindow::on_tabWidget_2_tabBarClicked(int index)
{
    // Récupérer l'index de l'onglet "Statistiques" sous l'onglet "CRUD"
       int statisticsTabIndex = ui->tabWidget_2->indexOf(ui->tab);  // Remplacez "statistiquesTab" par le nom réel de votre onglet "Statistiques"

       // Vérifier si l'onglet "Statistiques" a été cliqué
       if (index == statisticsTabIndex) {
           // Mettre à jour les statistiques ici
          updateProdStatisticsChart();
       } else {
           // Si l'onglet actif n'est pas "Statistiques", supprimer le graphique s'il existe
          clearProdStatisticsChart();

       }

}

void MainWindow::updateProdStatisticsChart()
{
    // Récupérer les statistiques réelles
    QMap<QString, int> statistics = mR.getProdStatistics();
    int totaleproduit = 0;

    // Calculer le nombre total de produit
    for (const QString &prodGroup : statistics.keys()) {
        totaleproduit += statistics[prodGroup];
    }

    // Créer une série pour le graphique circulaire
    QPieSeries *series = new QPieSeries();

    // Définir différentes nuances de vert pour chaque tranche
    QStringList greenColors = {"#55AA00", "#458C68", "#005500"};

    int colorIndex = 0;

    // Ajouter des tranches au graphique circulaire pour chaque groupe de produit
    for (const QString &prodGroup : statistics.keys()) {
        int count = statistics[prodGroup];
        QPieSlice *slice = series->append(prodGroup, count);

        // Afficher le pourcentage sur chaque tranche
        slice->setLabel(prodGroup + ": " + QString::number(static_cast<double>(count) / totaleproduit * 100, 'f', 2) + "%");

        // Définir la couleur des tranches
        if (colorIndex < greenColors.size()) {
            slice->setBrush(QColor(greenColors[colorIndex]));
        } else {
            slice->setBrush(QColor(Qt::green));  // Utiliser une couleur par défaut si vous avez épuisé les nuances de vert
        }

        // Passer à la prochaine nuance de vert
        colorIndex++;
    }

    // Supprimer le graphique précédent s'il existe
     clearProdStatisticsChart();

    // Créer un graphique circulaire et le configurer
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition par groupe de matiere");

    // Définir le fond du graphique comme beige
    chart->setBackgroundBrush(QBrush(QColor("#F5F5DC")));  // Couleur beige

    // Créer une vue de graphique et l'ajouter à votre interface utilisateur
    ProdStatisticsChartView = new QChartView(chart);
    ProdStatisticsChartView->setRenderHint(QPainter::Antialiasing);
    ProdStatisticsChartView->setParent(ui->tab);

    // Ajuster la taille du graphique (par exemple, 600x400 pixels)
    ProdStatisticsChartView->setGeometry(70, 50, 600, 400);

    // Afficher le graphique
    ProdStatisticsChartView->show();
}

void MainWindow::clearProdStatisticsChart()
{
    if (ProdStatisticsChartView)
    {
        delete ProdStatisticsChartView;
        ProdStatisticsChartView = nullptr;
    }
}



void MainWindow::on_select_id2_currentIndexChanged( QString id_M)
{

        id_M = ui->select_id2->currentText();

        QSqlQuery query;
        query.prepare("SELECT * FROM matiere_recyclee WHERE ID_MR='" + id_M + "'");

        if(query.exec())
        {
            while(query.next())
            {
                ui->pTextEditQRText->clear(); // Clear the text edit before adding new text

                ui->pTextEditQRText->appendPlainText(query.value(0).toString());


               /* ui->pTextEditQRText->clear(); // Clear the text edit before adding new text
                ui->pTextEditQRText->appendPlainText("ID: " + query.value(0).toString());
                QString type = query.value(1).toString().trimmed();  // it removes the trailing spaces
                qDebug() << "Type: " << type;  // print out the type value

                ui->pTextEditQRText->appendPlainText("Type: " + type);
                ui->pTextEditQRText->appendPlainText("Prix: " +query.value(2).toString());
                // ui->pTextEditQRText->setDate(query.value(3).toDate()); // QPlainTextEdit does not have a setDate() method
                ui->pTextEditQRText->appendPlainText("Quantité: " +query.value(4).toString());*/

            }
        }
   }

void MainWindow::on_LCDBUTTON_clicked()
{



    QString id = "122";

        QSqlQuery query;
        query.prepare("SELECT * FROM matiere_recyclee WHERE ID_MR = :id");
        query.bindValue(":id", id);
        query.exec();

        if (query.next()) {
            QString type_prod = query.value(1).toString().trimmed();
            float prix = query.value(2).toFloat();
            QDate date_entree = query.value(3).toDate();
            int quantites = query.value(4).toInt();

            QByteArray data;
            data.append("existe,");
            data.append(id + ",");
            data.append(type_prod + ",");
            data.append(QString::number(prix) + ",");
            data.append(date_entree.toString() + ",");
            data.append(QString::number(quantites) + "\n");

            // Assuming A is an instance of your class for Arduino communication
            A.write_to_arduino(data);
        } else {
            QByteArray data;
            data.append("existe not\n");
            // Assuming A is an instance of your class for Arduino communication
            A.write_to_arduino(data);
        }
}
