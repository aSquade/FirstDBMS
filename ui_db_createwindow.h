/********************************************************************************
** Form generated from reading UI file 'db_createwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DB_CREATEWINDOW_H
#define UI_DB_CREATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DB_CreateWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DB_CreateWindow)
    {
        if (DB_CreateWindow->objectName().isEmpty())
            DB_CreateWindow->setObjectName(QString::fromUtf8("DB_CreateWindow"));
        DB_CreateWindow->resize(320, 229);
        centralwidget = new QWidget(DB_CreateWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(60, 90, 191, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 181, 31));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(60, 150, 80, 31));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(170, 150, 80, 31));
        DB_CreateWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DB_CreateWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 22));
        DB_CreateWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DB_CreateWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DB_CreateWindow->setStatusBar(statusbar);

        retranslateUi(DB_CreateWindow);

        QMetaObject::connectSlotsByName(DB_CreateWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DB_CreateWindow)
    {
        DB_CreateWindow->setWindowTitle(QCoreApplication::translate("DB_CreateWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("DB_CreateWindow", "\350\257\267\350\276\223\345\205\245\345\260\206\350\246\201\345\210\233\345\273\272\347\232\204\346\225\260\346\215\256\345\272\223\345\220\215\347\247\260\357\274\232", nullptr));
        confirmButton->setText(QCoreApplication::translate("DB_CreateWindow", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("DB_CreateWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DB_CreateWindow: public Ui_DB_CreateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_CREATEWINDOW_H
