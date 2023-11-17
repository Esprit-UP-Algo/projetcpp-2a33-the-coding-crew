/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_pic;
    QPushButton *pushButton_7;
    QTabWidget *tabWidget;
    QWidget *crud;
    QTabWidget *tabWidget_2;
    QWidget *ajou;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *L_idpc;
    QLineEdit *lineEdit_quntite;
    QLabel *L_lieu;
    QLineEdit *lineEdit_lieu;
    QLabel *L_date;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_idpc;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QLabel *L_quntite;
    QDateEdit *dateEdit;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_8;
    QPushButton *B_ajouter;
    QPushButton *B_supp;
    QPushButton *B_modifier;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_ID;
    QLineEdit *lineEdit_RE;
    QLabel *label;
    QTableView *tableView_ID;
    QWidget *tab_8;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tab_PC;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_;
    QPushButton *b_trier;
    QPushButton *B_convPDF;
    QSpacerItem *verticalSpacer_3;
    QWidget *STATISTIQUE;
    QWidget *tab_3;
    QListWidget *listWidget;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1197, 608);
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(86, 197, 150);"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 220, 171, 41));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(207, 244, 210);"));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 260, 171, 41));
        pushButton_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(50, 157, 156);"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 300, 171, 41));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgb(207, 244, 210);"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 340, 171, 41));
        pushButton_4->setStyleSheet(QStringLiteral("background-color: rgb(207, 244, 210);"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 380, 171, 41));
        pushButton_5->setStyleSheet(QStringLiteral("background-color: rgb(207, 244, 210);"));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 420, 171, 41));
        pushButton_6->setStyleSheet(QStringLiteral("background-color: rgb(207, 244, 210);"));
        label_pic = new QLabel(groupBox);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(20, 20, 151, 131));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 180, 171, 41));
        pushButton_7->setStyleSheet(QStringLiteral("background-color: rgb(207, 244, 210);"));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(210, 30, 901, 491));
        tabWidget->setStyleSheet(QLatin1String("background-color: rgb(86, 197, 150);\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #c3c3c3;\n"
"    background-color: #f0f0f0;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #c3c3c3;\n"
"    color: #333333;\n"
"    padding: 2px 12px;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #007acc;\n"
"    color: #ffffff;\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);
        crud = new QWidget();
        crud->setObjectName(QStringLiteral("crud"));
        tabWidget_2 = new QTabWidget(crud);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 40, 911, 431));
        tabWidget_2->setLayoutDirection(Qt::LeftToRight);
        tabWidget_2->setStyleSheet(QLatin1String("background-color: rgb(86, 197, 150);\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #c3c3c3;\n"
"    background-color: #f0f0f0;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #c3c3c3;\n"
"    color: #333333;\n"
"    padding: 2px 12px;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #007acc;\n"
"    color: #ffffff;\n"
"}"));
        tabWidget_2->setTabShape(QTabWidget::Rounded);
        ajou = new QWidget();
        ajou->setObjectName(QStringLiteral("ajou"));
        gridLayout_2 = new QGridLayout(ajou);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, 0, 0, 0);
        groupBox_2 = new QGroupBox(ajou);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(401, 16777215));
        groupBox_2->setStyleSheet(QLatin1String("QTabWidget\n"
"{\n"
"background-color: rgb(123, 228, 149);\n"
"\n"
"}\n"
"\n"
"QTabWidget:tab-bar\n"
"{\n"
"alignment:center;\n"
"}\n"
"\n"
"QTabBar:tab\n"
"{\n"
"width:100px;\n"
"height:50px;\n"
"}\n"
"\n"
"QTabBar:tab:selected\n"
"{\n"
"    \n"
"	background-color: rgb(50, 155, 156);\n"
"    color:rgb(0,255,0);\n"
"}\n"
"\n"
"QTabBar:tab:hover\n"
"{\n"
"	background-color: rgb(109, 202, 131);\n"
"}"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        L_idpc = new QLabel(groupBox_2);
        L_idpc->setObjectName(QStringLiteral("L_idpc"));

        gridLayout->addWidget(L_idpc, 0, 0, 1, 1);

        lineEdit_quntite = new QLineEdit(groupBox_2);
        lineEdit_quntite->setObjectName(QStringLiteral("lineEdit_quntite"));

        gridLayout->addWidget(lineEdit_quntite, 5, 2, 1, 1);

        L_lieu = new QLabel(groupBox_2);
        L_lieu->setObjectName(QStringLiteral("L_lieu"));

        gridLayout->addWidget(L_lieu, 4, 0, 1, 1);

        lineEdit_lieu = new QLineEdit(groupBox_2);
        lineEdit_lieu->setObjectName(QStringLiteral("lineEdit_lieu"));

        gridLayout->addWidget(lineEdit_lieu, 4, 2, 1, 2);

        L_date = new QLabel(groupBox_2);
        L_date->setObjectName(QStringLiteral("L_date"));

        gridLayout->addWidget(L_date, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 5, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 4, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        lineEdit_idpc = new QLineEdit(groupBox_2);
        lineEdit_idpc->setObjectName(QStringLiteral("lineEdit_idpc"));
        lineEdit_idpc->setInputMethodHints(Qt::ImhNone);
        lineEdit_idpc->setMaxLength(8);

        gridLayout->addWidget(lineEdit_idpc, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 5, 1, 1, 1);

        L_quntite = new QLabel(groupBox_2);
        L_quntite->setObjectName(QStringLiteral("L_quntite"));

        gridLayout->addWidget(L_quntite, 5, 0, 1, 1);

        dateEdit = new QDateEdit(groupBox_2);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 1, 2, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_4->setContentsMargins(61, 34, -1, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_4->addItem(verticalSpacer_2, 2, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(12);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton_8 = new QPushButton(ajou);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setEnabled(true);

        verticalLayout_5->addWidget(pushButton_8);

        B_ajouter = new QPushButton(ajou);
        B_ajouter->setObjectName(QStringLiteral("B_ajouter"));
        B_ajouter->setSizeIncrement(QSize(0, 0));

        verticalLayout_5->addWidget(B_ajouter);

        B_supp = new QPushButton(ajou);
        B_supp->setObjectName(QStringLiteral("B_supp"));

        verticalLayout_5->addWidget(B_supp);

        B_modifier = new QPushButton(ajou);
        B_modifier->setObjectName(QStringLiteral("B_modifier"));

        verticalLayout_5->addWidget(B_modifier);


        gridLayout_4->addLayout(verticalLayout_5, 1, 0, 1, 1);

        gridLayout_4->setColumnStretch(0, 2);

        gridLayout_2->addLayout(gridLayout_4, 0, 2, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(13);
        comboBox_ID = new QComboBox(ajou);
        comboBox_ID->setObjectName(QStringLiteral("comboBox_ID"));
        comboBox_ID->setEnabled(true);
        comboBox_ID->setToolTipDuration(3);
        comboBox_ID->setEditable(true);

        gridLayout_3->addWidget(comboBox_ID, 1, 0, 1, 2);

        lineEdit_RE = new QLineEdit(ajou);
        lineEdit_RE->setObjectName(QStringLiteral("lineEdit_RE"));

        gridLayout_3->addWidget(lineEdit_RE, 4, 0, 1, 1);

        label = new QLabel(ajou);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_3->addWidget(label, 2, 0, 1, 1);

        tableView_ID = new QTableView(ajou);
        tableView_ID->setObjectName(QStringLiteral("tableView_ID"));

        gridLayout_3->addWidget(tableView_ID, 5, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 1, 1, 1);

        tabWidget_2->addTab(ajou, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        layoutWidget = new QWidget(tab_8);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 20, 801, 391));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tab_PC = new QTableView(layoutWidget);
        tab_PC->setObjectName(QStringLiteral("tab_PC"));

        horizontalLayout_3->addWidget(tab_PC);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit_ = new QLineEdit(layoutWidget);
        lineEdit_->setObjectName(QStringLiteral("lineEdit_"));

        verticalLayout_2->addWidget(lineEdit_);

        b_trier = new QPushButton(layoutWidget);
        b_trier->setObjectName(QStringLiteral("b_trier"));

        verticalLayout_2->addWidget(b_trier);

        B_convPDF = new QPushButton(layoutWidget);
        B_convPDF->setObjectName(QStringLiteral("B_convPDF"));

        verticalLayout_2->addWidget(B_convPDF);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 6);
        horizontalLayout_3->setStretch(1, 2);
        tabWidget_2->addTab(tab_8, QString());
        STATISTIQUE = new QWidget();
        STATISTIQUE->setObjectName(QStringLiteral("STATISTIQUE"));
        tabWidget_2->addTab(STATISTIQUE, QString());
        tabWidget->addTab(crud, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        listWidget = new QListWidget(tab_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(110, 110, 256, 192));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabWidget->addTab(tab_6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        label_pic->raise();
        tabWidget->raise();
        pushButton_7->raise();
        pushButton->raise();
        pushButton_3->raise();
        pushButton_2->raise();

        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1197, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Gestion d'employ\303\251s", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Gestion de Produits", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Gestion de collectes", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Rapport et Analyse", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label_pic->setText(QString());
        pushButton_7->setText(QApplication::translate("MainWindow", "Accueil", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        L_idpc->setText(QApplication::translate("MainWindow", "ID pc", Q_NULLPTR));
        L_lieu->setText(QApplication::translate("MainWindow", "lieu", Q_NULLPTR));
        L_date->setText(QApplication::translate("MainWindow", "date", Q_NULLPTR));
        lineEdit_idpc->setText(QString());
        L_quntite->setText(QApplication::translate("MainWindow", "quntite", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "mise \303\240 jour", Q_NULLPTR));
        B_ajouter->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        B_supp->setText(QApplication::translate("MainWindow", "supprime", Q_NULLPTR));
        B_modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "donne ID", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(ajou), QApplication::translate("MainWindow", "ajou/sup", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "recharche par id", Q_NULLPTR));
        b_trier->setText(QApplication::translate("MainWindow", "trier par lieu", Q_NULLPTR));
        B_convPDF->setText(QApplication::translate("MainWindow", "convetir PDF", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "affich/PDF", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(STATISTIQUE), QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(crud), QApplication::translate("MainWindow", "CRUD", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
