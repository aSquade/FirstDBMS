/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *createButton;
    QPushButton *deleteButton;
    QPushButton *addColumnButton;
    QTextEdit *textInput;
    QLabel *label;
    QPushButton *alterColumnBotton;
    QPushButton *deleteColumnButton;
    QLabel *label_2;
    QPushButton *insertDataButton;
    QPushButton *deleteDataButton;
    QPushButton *comfirmButton;
    QPushButton *clearButton;
    QTextEdit *fileDisplay;
    QPushButton *refreshButton;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuMainWindow;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(793, 702);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        createButton = new QPushButton(centralwidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(230, 30, 111, 41));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(230, 90, 111, 41));
        addColumnButton = new QPushButton(centralwidget);
        addColumnButton->setObjectName(QString::fromUtf8("addColumnButton"));
        addColumnButton->setGeometry(QRect(380, 30, 111, 41));
        textInput = new QTextEdit(centralwidget);
        textInput->setObjectName(QString::fromUtf8("textInput"));
        textInput->setGeometry(QRect(220, 150, 551, 231));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 0, 61, 16));
        alterColumnBotton = new QPushButton(centralwidget);
        alterColumnBotton->setObjectName(QString::fromUtf8("alterColumnBotton"));
        alterColumnBotton->setGeometry(QRect(520, 30, 111, 41));
        deleteColumnButton = new QPushButton(centralwidget);
        deleteColumnButton->setObjectName(QString::fromUtf8("deleteColumnButton"));
        deleteColumnButton->setGeometry(QRect(660, 30, 111, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 0, 81, 16));
        insertDataButton = new QPushButton(centralwidget);
        insertDataButton->setObjectName(QString::fromUtf8("insertDataButton"));
        insertDataButton->setGeometry(QRect(380, 90, 111, 41));
        deleteDataButton = new QPushButton(centralwidget);
        deleteDataButton->setObjectName(QString::fromUtf8("deleteDataButton"));
        deleteDataButton->setGeometry(QRect(520, 90, 111, 41));
        comfirmButton = new QPushButton(centralwidget);
        comfirmButton->setObjectName(QString::fromUtf8("comfirmButton"));
        comfirmButton->setGeometry(QRect(660, 400, 111, 41));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(520, 400, 111, 41));
        fileDisplay = new QTextEdit(centralwidget);
        fileDisplay->setObjectName(QString::fromUtf8("fileDisplay"));
        fileDisplay->setGeometry(QRect(20, 0, 181, 441));
        refreshButton = new QPushButton(centralwidget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setGeometry(QRect(100, 410, 101, 31));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 460, 751, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 793, 22));
        menuMainWindow = new QMenu(menubar);
        menuMainWindow->setObjectName(QString::fromUtf8("menuMainWindow"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMainWindow->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        createButton->setText(QString());
        deleteButton->setText(QString());
        addColumnButton->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\350\241\250\346\223\215\344\275\234\357\274\232", nullptr));
        alterColumnBotton->setText(QString());
        deleteColumnButton->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\272\223/\350\241\250\357\274\232", nullptr));
        insertDataButton->setText(QString());
        deleteDataButton->setText(QString());
        comfirmButton->setText(QString());
        clearButton->setText(QString());
        refreshButton->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        menuMainWindow->setTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
