/********************************************************************************
** Form generated from reading UI file 'createwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWINDOW_H
#define UI_CREATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateWindow
{
public:
    QWidget *centralwidget;
    QPushButton *DB_CreateButton;
    QPushButton *TBL_CreateButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateWindow)
    {
        if (CreateWindow->objectName().isEmpty())
            CreateWindow->setObjectName(QString::fromUtf8("CreateWindow"));
        CreateWindow->resize(374, 300);
        centralwidget = new QWidget(CreateWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DB_CreateButton = new QPushButton(centralwidget);
        DB_CreateButton->setObjectName(QString::fromUtf8("DB_CreateButton"));
        DB_CreateButton->setGeometry(QRect(120, 50, 121, 51));
        TBL_CreateButton = new QPushButton(centralwidget);
        TBL_CreateButton->setObjectName(QString::fromUtf8("TBL_CreateButton"));
        TBL_CreateButton->setGeometry(QRect(120, 130, 121, 51));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(140, 210, 80, 31));
        CreateWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 374, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        CreateWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CreateWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(CreateWindow);

        QMetaObject::connectSlotsByName(CreateWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CreateWindow)
    {
        CreateWindow->setWindowTitle(QCoreApplication::translate("CreateWindow", "MainWindow", nullptr));
        DB_CreateButton->setText(QCoreApplication::translate("CreateWindow", "\345\210\233\345\273\272\345\272\223", nullptr));
        TBL_CreateButton->setText(QCoreApplication::translate("CreateWindow", "\345\210\233\345\273\272\350\241\250", nullptr));
        cancelButton->setText(QCoreApplication::translate("CreateWindow", "\345\217\226\346\266\210", nullptr));
        menu->setTitle(QCoreApplication::translate("CreateWindow", "\345\210\233\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateWindow: public Ui_CreateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWINDOW_H
