/********************************************************************************
** Form generated from reading UI file 'tbl_deletewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TBL_DELETEWINDOW_H
#define UI_TBL_DELETEWINDOW_H

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

class Ui_TBL_DeleteWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TBL_DeleteWindow)
    {
        if (TBL_DeleteWindow->objectName().isEmpty())
            TBL_DeleteWindow->setObjectName(QString::fromUtf8("TBL_DeleteWindow"));
        TBL_DeleteWindow->resize(320, 263);
        centralwidget = new QWidget(TBL_DeleteWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 90, 171, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 120, 181, 31));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(70, 180, 80, 31));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(170, 180, 80, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 10, 171, 16));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 40, 181, 31));
        TBL_DeleteWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TBL_DeleteWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 22));
        TBL_DeleteWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TBL_DeleteWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TBL_DeleteWindow->setStatusBar(statusbar);

        retranslateUi(TBL_DeleteWindow);

        QMetaObject::connectSlotsByName(TBL_DeleteWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TBL_DeleteWindow)
    {
        TBL_DeleteWindow->setWindowTitle(QCoreApplication::translate("TBL_DeleteWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("TBL_DeleteWindow", "\350\241\250\345\220\215\347\247\260\357\274\232", nullptr));
        confirmButton->setText(QCoreApplication::translate("TBL_DeleteWindow", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("TBL_DeleteWindow", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("TBL_DeleteWindow", "\345\272\223\345\220\215\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TBL_DeleteWindow: public Ui_TBL_DeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TBL_DELETEWINDOW_H
