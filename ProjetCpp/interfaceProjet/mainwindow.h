#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "matiererecyclee.h"
#include "login.h"
#include <QMainWindow>
#include <QDir>
#include <QDebug>
#include <QRegExp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_b_update_clicked();

    void on_b_supp_p_clicked();

    void on_save_clicked();

    void on_b_modif_clicked();

    void  on_Binit_clicked();

    void on_tabWidget_2_currentChanged();


    void on_Btri_clicked();


    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_b_convPDF_clicked();

    void on_select_ID_currentIndexChanged();

private:
    Ui::MainWindow *ui;
    matiereRecyclee mR;
    login log;
};
#endif // MAINWINDOW_H
