#ifndef ACTIVITYDIALOG_H
#define ACTIVITYDIALOG_H

#include <QDialog>

namespace Ui {
class activitydialog;
}

class activitydialog : public QDialog
{
    Q_OBJECT

public:
    explicit activitydialog(QWidget *parent = nullptr);
    ~activitydialog();

private:
    Ui::activitydialog *ui;
};

#endif // ACTIVITYDIALOG_H
