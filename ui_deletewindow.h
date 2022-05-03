/********************************************************************************
** Form generated from reading UI file 'deletewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEWINDOW_H
#define UI_DELETEWINDOW_H

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

class Ui_DeleteWindow
{
public:
    QWidget *centralwidget;
    QPushButton *DB_DeleteButton;
    QPushButton *TBL_DeleteButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DeleteWindow)
    {
        if (DeleteWindow->objectName().isEmpty())
            DeleteWindow->setObjectName(QString::fromUtf8("DeleteWindow"));
        DeleteWindow->resize(383, 296);
        centralwidget = new QWidget(DeleteWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DB_DeleteButton = new QPushButton(centralwidget);
        DB_DeleteButton->setObjectName(QString::fromUtf8("DB_DeleteButton"));
        DB_DeleteButton->setGeometry(QRect(120, 50, 121, 51));
        TBL_DeleteButton = new QPushButton(centralwidget);
        TBL_DeleteButton->setObjectName(QString::fromUtf8("TBL_DeleteButton"));
        TBL_DeleteButton->setGeometry(QRect(120, 130, 121, 51));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(140, 210, 80, 31));
        DeleteWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DeleteWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 383, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        DeleteWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DeleteWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DeleteWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(DeleteWindow);

        QMetaObject::connectSlotsByName(DeleteWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DeleteWindow)
    {
        DeleteWindow->setWindowTitle(QCoreApplication::translate("DeleteWindow", "MainWindow", nullptr));
        DB_DeleteButton->setText(QCoreApplication::translate("DeleteWindow", "\345\210\240\351\231\244\345\272\223", nullptr));
        TBL_DeleteButton->setText(QCoreApplication::translate("DeleteWindow", "\345\210\240\351\231\244\350\241\250", nullptr));
        cancelButton->setText(QCoreApplication::translate("DeleteWindow", "\345\217\226\346\266\210", nullptr));
        menu->setTitle(QCoreApplication::translate("DeleteWindow", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteWindow: public Ui_DeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEWINDOW_H
