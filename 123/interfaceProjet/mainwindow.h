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

    void on_comboBox_ID_currentIndexChanged(const QString &arg1);

    void on_lineEdit_RE_textChanged(const QString &arg1);

    void on_b_trier_clicked();

    void on_lineEdit__textChanged(const QString &arg1);

    void on_B_convPDF_clicked();

    void on_tableView_ID_activated(const QModelIndex &index);

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_tabBarClicked(int index);


private:
    Ui::MainWindow *ui;
    PointDeCollect p;
};
#endif // MAINWINDOW_H
