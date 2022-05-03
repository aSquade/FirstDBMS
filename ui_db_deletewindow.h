/********************************************************************************
** Form generated from reading UI file 'db_deletewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DB_DELETEWINDOW_H
#define UI_DB_DELETEWINDOW_H

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

class Ui_DB_DeleteWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DB_DeleteWindow)
    {
        if (DB_DeleteWindow->objectName().isEmpty())
            DB_DeleteWindow->setObjectName(QString::fromUtf8("DB_DeleteWindow"));
        DB_DeleteWindow->resize(320, 230);
        centralwidget = new QWidget(DB_DeleteWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 30, 181, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 90, 181, 31));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(70, 150, 80, 31));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(170, 150, 80, 31));
        DB_DeleteWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DB_DeleteWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 22));
        DB_DeleteWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DB_DeleteWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DB_DeleteWindow->setStatusBar(statusbar);

        retranslateUi(DB_DeleteWindow);

        QMetaObject::connectSlotsByName(DB_DeleteWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DB_DeleteWindow)
    {
        DB_DeleteWindow->setWindowTitle(QCoreApplication::translate("DB_DeleteWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("DB_DeleteWindow", "\350\257\267\350\276\223\345\205\245\345\260\206\350\246\201\345\210\240\351\231\244\347\232\204\346\225\260\346\215\256\345\272\223\345\220\215\347\247\260\357\274\232", nullptr));
        confirmButton->setText(QCoreApplication::translate("DB_DeleteWindow", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("DB_DeleteWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DB_DeleteWindow: public Ui_DB_DeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_DELETEWINDOW_H
