/********************************************************************************
** Form generated from reading UI file 'datadeletewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATADELETEWINDOW_H
#define UI_DATADELETEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataDeleteWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QLineEdit *db_name;
    QLineEdit *tbl_name;
    QLabel *label;
    QLineEdit *datas;
    QLineEdit *col_name_3;
    QLineEdit *datas_2;
    QLineEdit *col_name_2;
    QPushButton *confirmButton;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *cancelButton;
    QLineEdit *col_name;
    QLineEdit *datas_3;
    QPushButton *continueButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DataDeleteWindow)
    {
        if (DataDeleteWindow->objectName().isEmpty())
            DataDeleteWindow->setObjectName(QString::fromUtf8("DataDeleteWindow"));
        DataDeleteWindow->resize(341, 333);
        centralwidget = new QWidget(DataDeleteWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 100, 51, 21));
        db_name = new QLineEdit(centralwidget);
        db_name->setObjectName(QString::fromUtf8("db_name"));
        db_name->setGeometry(QRect(90, 20, 171, 21));
        tbl_name = new QLineEdit(centralwidget);
        tbl_name->setObjectName(QString::fromUtf8("tbl_name"));
        tbl_name->setGeometry(QRect(90, 60, 171, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 41, 21));
        datas = new QLineEdit(centralwidget);
        datas->setObjectName(QString::fromUtf8("datas"));
        datas->setGeometry(QRect(140, 120, 161, 21));
        col_name_3 = new QLineEdit(centralwidget);
        col_name_3->setObjectName(QString::fromUtf8("col_name_3"));
        col_name_3->setGeometry(QRect(40, 200, 81, 21));
        datas_2 = new QLineEdit(centralwidget);
        datas_2->setObjectName(QString::fromUtf8("datas_2"));
        datas_2->setGeometry(QRect(140, 160, 161, 21));
        col_name_2 = new QLineEdit(centralwidget);
        col_name_2->setObjectName(QString::fromUtf8("col_name_2"));
        col_name_2->setGeometry(QRect(40, 160, 81, 21));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(130, 250, 80, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 100, 51, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 60, 51, 21));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(230, 250, 80, 31));
        col_name = new QLineEdit(centralwidget);
        col_name->setObjectName(QString::fromUtf8("col_name"));
        col_name->setGeometry(QRect(40, 120, 81, 21));
        datas_3 = new QLineEdit(centralwidget);
        datas_3->setObjectName(QString::fromUtf8("datas_3"));
        datas_3->setGeometry(QRect(140, 200, 161, 21));
        continueButton = new QPushButton(centralwidget);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setGeometry(QRect(30, 250, 81, 31));
        DataDeleteWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DataDeleteWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 341, 22));
        DataDeleteWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DataDeleteWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DataDeleteWindow->setStatusBar(statusbar);

        retranslateUi(DataDeleteWindow);

        QMetaObject::connectSlotsByName(DataDeleteWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DataDeleteWindow)
    {
        DataDeleteWindow->setWindowTitle(QCoreApplication::translate("DataDeleteWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("DataDeleteWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\210\227\345\220\215\357\274\232</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("DataDeleteWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\272\223\345\220\215\357\274\232</span></p></body></html>", nullptr));
        confirmButton->setText(QCoreApplication::translate("DataDeleteWindow", "\347\241\256\345\256\232", nullptr));
        label_4->setText(QCoreApplication::translate("DataDeleteWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\225\260\346\215\256\357\274\232</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("DataDeleteWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\350\241\250\345\220\215\357\274\232</span></p></body></html>", nullptr));
        cancelButton->setText(QCoreApplication::translate("DataDeleteWindow", "\345\217\226\346\266\210", nullptr));
        continueButton->setText(QCoreApplication::translate("DataDeleteWindow", "\347\273\247\347\273\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataDeleteWindow: public Ui_DataDeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATADELETEWINDOW_H
