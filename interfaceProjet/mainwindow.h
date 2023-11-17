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


private:
    Ui::MainWindow *ui;
    matiereRecyclee mR;

    CQR_Encode qrEncode;
    bool successfulEncoding;
    int encodeImageSize;
    QPoint lastPos;
    void updateMaterialStatisticsChart();
    QChartView *materialStatisticsChartView;
    void clearMaterialStatisticsChart();
    QChartView *ProdStatisticsChartView;

    void  updateProdStatisticsChart();
    void clearProdStatisticsChart();
protected:
    void closeEvent(QCloseEvent *);
    bool eventFilter( QObject * object, QEvent * event );

};
#endif // MAINWINDOW_H
