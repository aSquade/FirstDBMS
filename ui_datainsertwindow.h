/********************************************************************************
** Form generated from reading UI file 'datainsertwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAINSERTWINDOW_H
#define UI_DATAINSERTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataInsertWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *tbl_name;
    QLabel *label_3;
    QPushButton *continueButton;
    QPushButton *cancelButton;
    QPushButton *confirmButton;
    QLabel *label;
    QLineEdit *col_name;
    QLineEdit *datas;
    QLineEdit *db_name;
    QPushButton *completeButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *DataInsertWindow)
    {
        if (DataInsertWindow->objectName().isEmpty())
            DataInsertWindow->setObjectName(QString::fromUtf8("DataInsertWindow"));
        DataInsertWindow->setEnabled(true);
        DataInsertWindow->resize(520, 556);
        DataInsertWindow->setMinimumSize(QSize(520, 556));
        DataInsertWindow->setMaximumSize(QSize(520, 556));
        centralwidget = new QWidget(DataInsertWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 100, 51, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 260, 81, 41));
        tbl_name = new QLineEdit(centralwidget);
        tbl_name->setObjectName(QString::fromUtf8("tbl_name"));
        tbl_name->setGeometry(QRect(130, 80, 261, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 170, 91, 31));
        continueButton = new QPushButton(centralwidget);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setGeometry(QRect(90, 340, 121, 51));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(280, 430, 111, 51));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(280, 340, 111, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 91, 31));
        col_name = new QLineEdit(centralwidget);
        col_name->setObjectName(QString::fromUtf8("col_name"));
        col_name->setGeometry(QRect(130, 160, 261, 51));
        datas = new QLineEdit(centralwidget);
        datas->setObjectName(QString::fromUtf8("datas"));
        datas->setGeometry(QRect(130, 250, 261, 61));
        db_name = new QLineEdit(centralwidget);
        db_name->setObjectName(QString::fromUtf8("db_name"));
        db_name->setGeometry(QRect(130, 10, 261, 51));
        completeButton = new QPushButton(centralwidget);
        completeButton->setObjectName(QString::fromUtf8("completeButton"));
        completeButton->setGeometry(QRect(90, 430, 121, 51));
        DataInsertWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DataInsertWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 520, 21));
        DataInsertWindow->setMenuBar(menubar);

        retranslateUi(DataInsertWindow);

        QMetaObject::connectSlotsByName(DataInsertWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DataInsertWindow)
    {
        DataInsertWindow->setWindowTitle(QCoreApplication::translate("DataInsertWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("DataInsertWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\350\241\250\345\220\215\357\274\232</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("DataInsertWindow", "<html><head/><body><p><span style=\" font-size:12pt;\"> \346\225\260\346\215\256\357\274\232</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("DataInsertWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">	\345\210\227\345\220\215\357\274\232</span></p></body></html>", nullptr));
        continueButton->setText(QCoreApplication::translate("DataInsertWindow", "\347\273\247\347\273\255", nullptr));
        cancelButton->setText(QCoreApplication::translate("DataInsertWindow", "\345\217\226\346\266\210", nullptr));
        confirmButton->setText(QCoreApplication::translate("DataInsertWindow", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("DataInsertWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\272\223\345\220\215\357\274\232</span></p></body></html>", nullptr));
        completeButton->setText(QCoreApplication::translate("DataInsertWindow", "\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataInsertWindow: public Ui_DataInsertWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAINSERTWINDOW_H
