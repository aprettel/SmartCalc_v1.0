/********************************************************************************
** Form generated from reading UI file 'creditwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITWINDOW_H
#define UI_CREDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnotherWindow
{
public:
    QRadioButton *mainButton;
    QComboBox *comboBox;
    QLineEdit *lineEdit_1;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *radioButton_D;
    QRadioButton *radioButton_A;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_equal;
    QLabel *label_8;
    QLabel *label_9;
    QTextBrowser *textBrowser_monthly;
    QTextBrowser *textBrowser_overpay;
    QTextBrowser *textBrowser_total;

    void setupUi(QWidget *AnotherWindow)
    {
        if (AnotherWindow->objectName().isEmpty())
            AnotherWindow->setObjectName(QString::fromUtf8("AnotherWindow"));
        AnotherWindow->resize(650, 492);
        mainButton = new QRadioButton(AnotherWindow);
        mainButton->setObjectName(QString::fromUtf8("mainButton"));
        mainButton->setGeometry(QRect(30, 10, 180, 20));
        comboBox = new QComboBox(AnotherWindow);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(390, 80, 100, 40));
        lineEdit_1 = new QLineEdit(AnotherWindow);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(230, 45, 160, 30));
        label_4 = new QLabel(AnotherWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 130, 120, 20));
        lineEdit_3 = new QLineEdit(AnotherWindow);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(230, 125, 160, 30));
        lineEdit_2 = new QLineEdit(AnotherWindow);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(230, 85, 160, 30));
        label_2 = new QLabel(AnotherWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 50, 120, 20));
        label_3 = new QLabel(AnotherWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 90, 120, 20));
        radioButton_D = new QRadioButton(AnotherWindow);
        radioButton_D->setObjectName(QString::fromUtf8("radioButton_D"));
        radioButton_D->setGeometry(QRect(230, 200, 170, 20));
        radioButton_A = new QRadioButton(AnotherWindow);
        radioButton_A->setObjectName(QString::fromUtf8("radioButton_A"));
        radioButton_A->setGeometry(QRect(230, 170, 120, 20));
        label_5 = new QLabel(AnotherWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(400, 130, 20, 20));
        label_6 = new QLabel(AnotherWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 170, 120, 40));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(AnotherWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 250, 160, 40));
        label_7->setAlignment(Qt::AlignCenter);
        pushButton_equal = new QPushButton(AnotherWindow);
        pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
        pushButton_equal->setGeometry(QRect(410, 260, 100, 32));
        label_8 = new QLabel(AnotherWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 295, 160, 40));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(AnotherWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 345, 160, 40));
        label_9->setAlignment(Qt::AlignCenter);
        textBrowser_monthly = new QTextBrowser(AnotherWindow);
        textBrowser_monthly->setObjectName(QString::fromUtf8("textBrowser_monthly"));
        textBrowser_monthly->setGeometry(QRect(230, 255, 160, 30));
        textBrowser_overpay = new QTextBrowser(AnotherWindow);
        textBrowser_overpay->setObjectName(QString::fromUtf8("textBrowser_overpay"));
        textBrowser_overpay->setGeometry(QRect(230, 300, 160, 30));
        textBrowser_total = new QTextBrowser(AnotherWindow);
        textBrowser_total->setObjectName(QString::fromUtf8("textBrowser_total"));
        textBrowser_total->setGeometry(QRect(230, 350, 160, 30));

        retranslateUi(AnotherWindow);

        QMetaObject::connectSlotsByName(AnotherWindow);
    } // setupUi

    void retranslateUi(QWidget *AnotherWindow)
    {
        AnotherWindow->setWindowTitle(QCoreApplication::translate("AnotherWindow", "CreditCalc", nullptr));
        mainButton->setText(QCoreApplication::translate("AnotherWindow", "\320\237\321\200\320\276\321\201\321\202\320\276\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AnotherWindow", "\320\273\320\265\321\202", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AnotherWindow", "\320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));

        label_4->setText(QCoreApplication::translate("AnotherWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("AnotherWindow", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("AnotherWindow", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        radioButton_D->setText(QCoreApplication::translate("AnotherWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265", nullptr));
        radioButton_A->setText(QCoreApplication::translate("AnotherWindow", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\265", nullptr));
        label_5->setText(QCoreApplication::translate("AnotherWindow", "%", nullptr));
        label_6->setText(QCoreApplication::translate("AnotherWindow", "\320\242\320\270\320\277 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\321\205 \n"
" \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271", nullptr));
        label_7->setText(QCoreApplication::translate("AnotherWindow", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266:", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("AnotherWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("AnotherWindow", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202:", nullptr));
        label_9->setText(QCoreApplication::translate("AnotherWindow", "\320\224\320\276\320\273\320\263 + \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnotherWindow: public Ui_AnotherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITWINDOW_H
