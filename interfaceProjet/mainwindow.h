#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "pointdecollect.h"
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
    void on_pushButton_8_clicked();



    void on_B_ajouter_clicked();

    void on_B_supp_clicked();

    void on_B_modifier_clicked();

private:
    Ui::MainWindow *ui;
    PointDeCollect p;
};
#endif // MAINWINDOW_H
