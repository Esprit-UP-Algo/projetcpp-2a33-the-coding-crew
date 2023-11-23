 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conteneur.h"
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
    void on_boutton_supprimer_clicked();

    void on_boutton_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pushButton_modifier_clicked();



    void RechercheID();
bool RechercheID2() ;
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    //int countType();
    //int countType1();
    //int countType2();
    int countType(const QString& type);



    void on_EMAIL_clicked();
    bool RechercheQuantiteUnder100();

private:
    Ui::MainWindow *ui;
    Conteneur C ;
};
#endif // MAINWINDOW_H
