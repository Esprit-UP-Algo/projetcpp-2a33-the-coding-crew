#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_confirmer_login_clicked();

    void on_annuler_login_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
