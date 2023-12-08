#ifndef REMPLIR_H
#define REMPLIR_H

#include <QWidget>
#include "arduino.h"
namespace Ui {
class remplir;
}

class remplir : public QWidget
{
    Q_OBJECT

public:
    explicit remplir(QWidget *parent = nullptr);
    ~remplir();

private slots:



    void on_push_id_2_clicked();

private:
    Ui::remplir *ui;
    QByteArray data;
    Arduino A;
};

#endif // REMPLIR_H
