#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "matiererecyclee.h"
#include <QMainWindow>
#include <QDir>
#include <QDebug>
#include <QRegExp>
#include <QEvent>
#include "qrcodegen.h"
#include "ui_mainwindow.h"
#include "pointdecollect.h"
#include "employe.h"
#include "arduino.h"



#include <QVariant>
#include <QtCharts>
#include <QtCharts/QChartView>
#include "conteneur.h"
#include "vehicules.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void updateQRImage();
    void setScale(int);

private slots:
    void on_b_update_clicked();

    void on_b_supp_p_clicked();

    void on_save_clicked();

    void on_b_modif_clicked();

    void  on_Binit_clicked();

    void on_Btri_clicked();

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_b_convPDF_clicked();

    void on_select_ID_currentIndexChanged(QString);

    void on_confirmer_login_clicked();

    void on_annuler_login_clicked();

    void on_pButtonSave_clicked();

    void on_sBoxScale_valueChanged(int arg1);

    void on_pTextEditQRText_textChanged();

    void on_pButtonQuit_clicked();

    void on_tabWidget_2_tabBarClicked(int index);




    void on_select_id2_currentIndexChanged(QString id_M);

    void on_b_ajouter_clicked();

    void on_B_supp_clicked();

    void on_pushButton_8_clicked();

    void on_B_modifier_clicked();

    void on_tableView_ID_activated(const QModelIndex &index);

    void on_tabWidget_tabBarClicked(int index);

    void on_b_trier_clicked();

    void on_lineEdit_RE_textChanged(const QString &arg1);

    void on_lineEdit__textChanged(const QString &arg1);

    void on_B_convPDF_clicked();

    void on_B_gestiondecollecte_clicked();

    void on_B_gestiondeproduit_clicked();



    //sabee
    void on_geajouter_clicked();

    void on_geafficher_clicked();

    void on_gesupprimer_clicked();

    void on_gemodifier_clicked();

    void on_getrier_clicked();

    void on_gechercher_clicked();

    void on_gePDF_clicked();

    void on_geExcel_clicked();

    void on_geselectii_currentIndexChanged( QString);


    void on_B_gestiondemployee_clicked();


    void on_Decon_clicked();

    void on_Decon_2_clicked();

    void on_Decon_3_clicked();

    void on_b_gest_emp_clicked();

    void on_B_gestiondeproduit_2_clicked();


   //void on_B_gestiondecollecte_3_clicked();
    void on_pushButton_4_clicked();
    void on_Decon_4_clicked();
    //integration conteneur
    void on_boutton_supprimer_clicked();

    void on_boutton_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pushButton_modifier_clicked();



    void RechercheID();
bool RechercheID2() ;
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_statt_btn_clicked();
    //int countType();
    //int countType1();
    //int countType2();
    int countType(const QString& type);



    void on_EMAIL_clicked();
    bool RechercheQuantiteUnder100();

    void on_remplir_clicked();

    void on_Decon_5_clicked();

    void on_pushButton_5_clicked();

    //gestion vehicules
    void on_pushButton_17_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_20_clicked();

    void on_texte_recherche_textChanged(const QString &var);

    void on_TRI_clicked();

    void on_PDF_clicked();

    void on_STAT_clicked();
    int count1();
    int count2();
    int count3();
    int count4();
    int count5();
    int count6();
   void on_notification_system();
private:
    Ui::MainWindow *ui;
    matiereRecyclee mR;
    Employe Emp;
    //integration conteneur

    Conteneur C ;

    CQR_Encode qrEncode;
    bool successfulEncoding;
    int encodeImageSize;
    QPoint lastPos;
    void updateMaterialStatisticsChart();
    QChartView *materialStatisticsChartView;
    void clearMaterialStatisticsChart();
    QChartView *ProdStatisticsChartView;
    QChartView *quntiteStatisticsChartView;
    void updatequntiterStatisticsChart();
    void clearquntiterStatisticsChart();


    void  updateProdStatisticsChart();
    void clearProdStatisticsChart();
protected:
    void closeEvent(QCloseEvent *);
    bool eventFilter( QObject * object, QEvent * event );

    /////////////////////////////////////// point collect
    ///////////////////
vehicules V;
Arduino A;
QByteArray data;
void on_pushButton_12_clicked();
void gestion_conteneur_2();
PointDeCollect p;

signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);


};
#endif // MAINWINDOW_H
