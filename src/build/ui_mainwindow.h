/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QRadioButton *creditButton;
    QPushButton *pushButton_div;
    QPushButton *pushButton_3;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_1;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_log;
    QPushButton *pushButton_left;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_2;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_5;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_right;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_7;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_C;
    QPushButton *pushButton_0;
    QPushButton *pushButton_4;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit;
    QPushButton *pushButton_X;
    QLineEdit *lineEdit_2;
    QPushButton *graphButton;
    QLineEdit *lineEdit_3;
    QCustomPlot *plot;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(887, 376);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(150, 200));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        creditButton = new QRadioButton(centralwidget);
        creditButton->setObjectName(QString::fromUtf8("creditButton"));
        creditButton->setGeometry(QRect(10, 20, 180, 20));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setEnabled(true);
        pushButton_div->setGeometry(QRect(341, 190, 41, 32));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_div->sizePolicy().hasHeightForWidth());
        pushButton_div->setSizePolicy(sizePolicy1);
        pushButton_div->setMaximumSize(QSize(16777215, 16777215));
        pushButton_div->setSizeIncrement(QSize(0, 0));
        pushButton_div->setBaseSize(QSize(0, 0));
        pushButton_div->setAutoDefault(false);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(true);
        pushButton_3->setGeometry(QRect(290, 250, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMaximumSize(QSize(16777215, 16777215));
        pushButton_3->setSizeIncrement(QSize(0, 0));
        pushButton_3->setBaseSize(QSize(0, 0));
        pushButton_3->setAutoDefault(false);
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setEnabled(true);
        pushButton_asin->setGeometry(QRect(24, 220, 75, 32));
        sizePolicy1.setHeightForWidth(pushButton_asin->sizePolicy().hasHeightForWidth());
        pushButton_asin->setSizePolicy(sizePolicy1);
        pushButton_asin->setMaximumSize(QSize(16777215, 16777215));
        pushButton_asin->setSizeIncrement(QSize(0, 0));
        pushButton_asin->setBaseSize(QSize(0, 0));
        pushButton_asin->setAutoDefault(false);
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setEnabled(true);
        pushButton_acos->setGeometry(QRect(24, 190, 75, 32));
        sizePolicy1.setHeightForWidth(pushButton_acos->sizePolicy().hasHeightForWidth());
        pushButton_acos->setSizePolicy(sizePolicy1);
        pushButton_acos->setMaximumSize(QSize(16777215, 16777215));
        pushButton_acos->setSizeIncrement(QSize(0, 0));
        pushButton_acos->setBaseSize(QSize(0, 0));
        pushButton_acos->setAutoDefault(false);
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setEnabled(true);
        pushButton_1->setGeometry(QRect(187, 250, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy1);
        pushButton_1->setMaximumSize(QSize(16777215, 16777215));
        pushButton_1->setSizeIncrement(QSize(0, 0));
        pushButton_1->setBaseSize(QSize(0, 0));
        pushButton_1->setAutoDefault(false);
        pushButton_AC = new QPushButton(centralwidget);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        pushButton_AC->setGeometry(QRect(392, 160, 71, 32));
        sizePolicy1.setHeightForWidth(pushButton_AC->sizePolicy().hasHeightForWidth());
        pushButton_AC->setSizePolicy(sizePolicy1);
        pushButton_AC->setMaximumSize(QSize(16777215, 16777215));
        pushButton_AC->setSizeIncrement(QSize(0, 0));
        pushButton_AC->setBaseSize(QSize(0, 0));
        pushButton_AC->setAutoDefault(false);
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setEnabled(true);
        pushButton_log->setGeometry(QRect(24, 280, 75, 32));
        sizePolicy1.setHeightForWidth(pushButton_log->sizePolicy().hasHeightForWidth());
        pushButton_log->setSizePolicy(sizePolicy1);
        pushButton_log->setMaximumSize(QSize(16777215, 16777215));
        pushButton_log->setSizeIncrement(QSize(0, 0));
        pushButton_log->setBaseSize(QSize(0, 0));
        pushButton_log->setAutoDefault(false);
        pushButton_left = new QPushButton(centralwidget);
        pushButton_left->setObjectName(QString::fromUtf8("pushButton_left"));
        pushButton_left->setEnabled(true);
        pushButton_left->setGeometry(QRect(24, 160, 75, 32));
        sizePolicy1.setHeightForWidth(pushButton_left->sizePolicy().hasHeightForWidth());
        pushButton_left->setSizePolicy(sizePolicy1);
        pushButton_left->setMaximumSize(QSize(16777215, 16777215));
        pushButton_left->setSizeIncrement(QSize(0, 0));
        pushButton_left->setBaseSize(QSize(0, 0));
        pushButton_left->setAutoDefault(false);
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setEnabled(true);
        pushButton_ln->setGeometry(QRect(109, 280, 68, 32));
        sizePolicy1.setHeightForWidth(pushButton_ln->sizePolicy().hasHeightForWidth());
        pushButton_ln->setSizePolicy(sizePolicy1);
        pushButton_ln->setMaximumSize(QSize(16777215, 16777215));
        pushButton_ln->setSizeIncrement(QSize(0, 0));
        pushButton_ln->setBaseSize(QSize(0, 0));
        pushButton_ln->setAutoDefault(false);
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setEnabled(true);
        pushButton_sin->setGeometry(QRect(109, 220, 68, 32));
        sizePolicy1.setHeightForWidth(pushButton_sin->sizePolicy().hasHeightForWidth());
        pushButton_sin->setSizePolicy(sizePolicy1);
        pushButton_sin->setMaximumSize(QSize(16777215, 16777215));
        pushButton_sin->setSizeIncrement(QSize(0, 0));
        pushButton_sin->setBaseSize(QSize(0, 0));
        pushButton_sin->setAutoDefault(false);
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setEnabled(true);
        pushButton_atan->setGeometry(QRect(24, 250, 75, 32));
        sizePolicy1.setHeightForWidth(pushButton_atan->sizePolicy().hasHeightForWidth());
        pushButton_atan->setSizePolicy(sizePolicy1);
        pushButton_atan->setMaximumSize(QSize(16777215, 16777215));
        pushButton_atan->setSizeIncrement(QSize(0, 0));
        pushButton_atan->setBaseSize(QSize(0, 0));
        pushButton_atan->setAutoDefault(false);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setGeometry(QRect(238, 250, 42, 32));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMaximumSize(QSize(16777215, 16777215));
        pushButton_2->setSizeIncrement(QSize(0, 0));
        pushButton_2->setBaseSize(QSize(0, 0));
        pushButton_2->setAutoDefault(false);
        pushButton_equal = new QPushButton(centralwidget);
        pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
        pushButton_equal->setEnabled(true);
        pushButton_equal->setGeometry(QRect(392, 280, 71, 32));
        sizePolicy1.setHeightForWidth(pushButton_equal->sizePolicy().hasHeightForWidth());
        pushButton_equal->setSizePolicy(sizePolicy1);
        pushButton_equal->setMaximumSize(QSize(16777215, 16777215));
        pushButton_equal->setSizeIncrement(QSize(0, 0));
        pushButton_equal->setBaseSize(QSize(0, 0));
        QFont font;
        font.setBold(false);
        pushButton_equal->setFont(font);
        pushButton_equal->setAutoDefault(false);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setEnabled(true);
        pushButton_5->setGeometry(QRect(187, 220, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMaximumSize(QSize(16777215, 16777215));
        pushButton_5->setSizeIncrement(QSize(0, 0));
        pushButton_5->setBaseSize(QSize(0, 0));
        pushButton_5->setAutoDefault(false);
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setEnabled(true);
        pushButton_mod->setGeometry(QRect(392, 250, 71, 32));
        sizePolicy1.setHeightForWidth(pushButton_mod->sizePolicy().hasHeightForWidth());
        pushButton_mod->setSizePolicy(sizePolicy1);
        pushButton_mod->setMaximumSize(QSize(16777215, 16777215));
        pushButton_mod->setSizeIncrement(QSize(0, 0));
        pushButton_mod->setBaseSize(QSize(0, 0));
        pushButton_mod->setAutoDefault(false);
        pushButton_right = new QPushButton(centralwidget);
        pushButton_right->setObjectName(QString::fromUtf8("pushButton_right"));
        pushButton_right->setEnabled(true);
        pushButton_right->setGeometry(QRect(109, 160, 68, 32));
        sizePolicy1.setHeightForWidth(pushButton_right->sizePolicy().hasHeightForWidth());
        pushButton_right->setSizePolicy(sizePolicy1);
        pushButton_right->setMaximumSize(QSize(16777215, 16777215));
        pushButton_right->setSizeIncrement(QSize(0, 0));
        pushButton_right->setBaseSize(QSize(0, 0));
        pushButton_right->setAutoDefault(false);
        pushButton_pow = new QPushButton(centralwidget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setEnabled(true);
        pushButton_pow->setGeometry(QRect(392, 220, 71, 32));
        sizePolicy1.setHeightForWidth(pushButton_pow->sizePolicy().hasHeightForWidth());
        pushButton_pow->setSizePolicy(sizePolicy1);
        pushButton_pow->setMaximumSize(QSize(16777215, 16777215));
        pushButton_pow->setSizeIncrement(QSize(0, 0));
        pushButton_pow->setBaseSize(QSize(0, 0));
        pushButton_pow->setAutoDefault(false);
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setEnabled(true);
        pushButton_minus->setGeometry(QRect(341, 250, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_minus->sizePolicy().hasHeightForWidth());
        pushButton_minus->setSizePolicy(sizePolicy1);
        pushButton_minus->setMaximumSize(QSize(16777215, 16777215));
        pushButton_minus->setSizeIncrement(QSize(0, 0));
        pushButton_minus->setBaseSize(QSize(0, 0));
        pushButton_minus->setAutoDefault(false);
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setEnabled(true);
        pushButton_tan->setGeometry(QRect(109, 250, 68, 32));
        sizePolicy1.setHeightForWidth(pushButton_tan->sizePolicy().hasHeightForWidth());
        pushButton_tan->setSizePolicy(sizePolicy1);
        pushButton_tan->setMaximumSize(QSize(16777215, 16777215));
        pushButton_tan->setSizeIncrement(QSize(0, 0));
        pushButton_tan->setBaseSize(QSize(0, 0));
        pushButton_tan->setAutoDefault(false);
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setEnabled(true);
        pushButton_7->setGeometry(QRect(238, 190, 42, 32));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMaximumSize(QSize(16777215, 16777215));
        pushButton_7->setSizeIncrement(QSize(0, 0));
        pushButton_7->setBaseSize(QSize(0, 0));
        pushButton_7->setAutoDefault(false);
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setEnabled(true);
        pushButton_sqrt->setGeometry(QRect(392, 190, 71, 32));
        sizePolicy1.setHeightForWidth(pushButton_sqrt->sizePolicy().hasHeightForWidth());
        pushButton_sqrt->setSizePolicy(sizePolicy1);
        pushButton_sqrt->setMaximumSize(QSize(16777215, 16777215));
        pushButton_sqrt->setSizeIncrement(QSize(0, 0));
        pushButton_sqrt->setBaseSize(QSize(0, 0));
        pushButton_sqrt->setAutoDefault(false);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setEnabled(true);
        pushButton_8->setGeometry(QRect(187, 190, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setMaximumSize(QSize(16777215, 16777215));
        pushButton_8->setSizeIncrement(QSize(0, 0));
        pushButton_8->setBaseSize(QSize(0, 0));
        pushButton_8->setAutoDefault(false);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setEnabled(true);
        pushButton_6->setGeometry(QRect(290, 220, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMaximumSize(QSize(16777215, 16777215));
        pushButton_6->setSizeIncrement(QSize(0, 0));
        pushButton_6->setBaseSize(QSize(0, 0));
        pushButton_6->setAutoDefault(false);
        pushButton_mult = new QPushButton(centralwidget);
        pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
        pushButton_mult->setEnabled(true);
        pushButton_mult->setGeometry(QRect(341, 220, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_mult->sizePolicy().hasHeightForWidth());
        pushButton_mult->setSizePolicy(sizePolicy1);
        pushButton_mult->setMaximumSize(QSize(16777215, 16777215));
        pushButton_mult->setSizeIncrement(QSize(0, 0));
        pushButton_mult->setBaseSize(QSize(0, 0));
        pushButton_mult->setAutoDefault(false);
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setEnabled(true);
        pushButton_dot->setGeometry(QRect(238, 280, 42, 32));
        sizePolicy1.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy1);
        pushButton_dot->setMaximumSize(QSize(16777215, 16777215));
        pushButton_dot->setSizeIncrement(QSize(0, 0));
        pushButton_dot->setBaseSize(QSize(0, 0));
        pushButton_dot->setAutoDefault(false);
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setEnabled(true);
        pushButton_plus->setGeometry(QRect(341, 280, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_plus->sizePolicy().hasHeightForWidth());
        pushButton_plus->setSizePolicy(sizePolicy1);
        pushButton_plus->setMaximumSize(QSize(16777215, 16777215));
        pushButton_plus->setSizeIncrement(QSize(0, 0));
        pushButton_plus->setBaseSize(QSize(0, 0));
        pushButton_plus->setAutoDefault(false);
        pushButton_C = new QPushButton(centralwidget);
        pushButton_C->setObjectName(QString::fromUtf8("pushButton_C"));
        pushButton_C->setGeometry(QRect(341, 160, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_C->sizePolicy().hasHeightForWidth());
        pushButton_C->setSizePolicy(sizePolicy1);
        pushButton_C->setMaximumSize(QSize(16777215, 16777215));
        pushButton_C->setSizeIncrement(QSize(0, 0));
        pushButton_C->setBaseSize(QSize(0, 0));
        pushButton_C->setAutoDefault(false);
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setEnabled(true);
        pushButton_0->setGeometry(QRect(187, 280, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy1);
        pushButton_0->setMaximumSize(QSize(16777215, 16777215));
        pushButton_0->setSizeIncrement(QSize(0, 0));
        pushButton_0->setBaseSize(QSize(0, 0));
        pushButton_0->setAutoDefault(false);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(true);
        pushButton_4->setGeometry(QRect(238, 220, 42, 32));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMaximumSize(QSize(16777215, 16777215));
        pushButton_4->setSizeIncrement(QSize(0, 0));
        pushButton_4->setBaseSize(QSize(0, 0));
        pushButton_4->setAutoDefault(false);
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setEnabled(true);
        pushButton_cos->setGeometry(QRect(109, 190, 68, 32));
        sizePolicy1.setHeightForWidth(pushButton_cos->sizePolicy().hasHeightForWidth());
        pushButton_cos->setSizePolicy(sizePolicy1);
        pushButton_cos->setMaximumSize(QSize(16777215, 16777215));
        pushButton_cos->setSizeIncrement(QSize(0, 0));
        pushButton_cos->setBaseSize(QSize(0, 0));
        pushButton_cos->setAutoDefault(false);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setEnabled(true);
        pushButton_9->setGeometry(QRect(290, 190, 41, 32));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setMaximumSize(QSize(16777215, 16777215));
        pushButton_9->setSizeIncrement(QSize(0, 0));
        pushButton_9->setBaseSize(QSize(0, 0));
        pushButton_9->setAutoDefault(false);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 439, 40));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(0, 0));
        lineEdit->setMaximumSize(QSize(16777215, 40));
        pushButton_X = new QPushButton(centralwidget);
        pushButton_X->setObjectName(QString::fromUtf8("pushButton_X"));
        pushButton_X->setEnabled(true);
        pushButton_X->setGeometry(QRect(180, 120, 42, 32));
        sizePolicy1.setHeightForWidth(pushButton_X->sizePolicy().hasHeightForWidth());
        pushButton_X->setSizePolicy(sizePolicy1);
        pushButton_X->setMaximumSize(QSize(16777215, 16777215));
        pushButton_X->setSizeIncrement(QSize(0, 0));
        pushButton_X->setBaseSize(QSize(0, 0));
        pushButton_X->setAutoDefault(false);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 120, 91, 31));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(0, 0));
        lineEdit_2->setMaximumSize(QSize(16777215, 40));
        graphButton = new QPushButton(centralwidget);
        graphButton->setObjectName(QString::fromUtf8("graphButton"));
        graphButton->setEnabled(true);
        graphButton->setGeometry(QRect(330, 120, 61, 32));
        sizePolicy1.setHeightForWidth(graphButton->sizePolicy().hasHeightForWidth());
        graphButton->setSizePolicy(sizePolicy1);
        graphButton->setMaximumSize(QSize(16777215, 16777215));
        graphButton->setSizeIncrement(QSize(0, 0));
        graphButton->setBaseSize(QSize(0, 0));
        graphButton->setAutoDefault(false);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(240, 120, 81, 31));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);
        lineEdit_3->setMinimumSize(QSize(0, 0));
        lineEdit_3->setMaximumSize(QSize(16777215, 40));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(490, 30, 371, 281));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_acos->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SmartCalc", nullptr));
        creditButton->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin(x)", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos(x)", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log(x)", nullptr));
        pushButton_left->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln(x)", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin(x)", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan(x)", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_right->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan(x)", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt(x)", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_C->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos(x)", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_X->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_2->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "min X", nullptr));
        graphButton->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "max X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
