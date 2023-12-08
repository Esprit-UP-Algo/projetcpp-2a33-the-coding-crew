#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vehicules.h"
#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

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


private:
    Ui::MainWindow *ui;
    vehicules V;
};
#endif // MAINWINDOW_H
