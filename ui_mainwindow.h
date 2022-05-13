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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollBar *verticalScrollBar;
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
    QTextEdit *textOutput;
    QMenuBar *menubar;
    QMenu *menuMainWindow;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1083, 869);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 20, 261, 531));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 259, 529));
        verticalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(230, 0, 16, 551));
        verticalScrollBar->setOrientation(Qt::Vertical);
        scrollArea->setWidget(scrollAreaWidgetContents);
        createButton = new QPushButton(centralwidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(340, 50, 111, 41));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(480, 50, 111, 41));
        addColumnButton = new QPushButton(centralwidget);
        addColumnButton->setObjectName(QString::fromUtf8("addColumnButton"));
        addColumnButton->setGeometry(QRect(340, 150, 111, 41));
        textInput = new QTextEdit(centralwidget);
        textInput->setObjectName(QString::fromUtf8("textInput"));
        textInput->setGeometry(QRect(300, 270, 761, 231));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 120, 61, 16));
        alterColumnBotton = new QPushButton(centralwidget);
        alterColumnBotton->setObjectName(QString::fromUtf8("alterColumnBotton"));
        alterColumnBotton->setGeometry(QRect(490, 150, 111, 41));
        deleteColumnButton = new QPushButton(centralwidget);
        deleteColumnButton->setObjectName(QString::fromUtf8("deleteColumnButton"));
        deleteColumnButton->setGeometry(QRect(640, 150, 111, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 20, 81, 16));
        insertDataButton = new QPushButton(centralwidget);
        insertDataButton->setObjectName(QString::fromUtf8("insertDataButton"));
        insertDataButton->setGeometry(QRect(340, 210, 111, 41));
        deleteDataButton = new QPushButton(centralwidget);
        deleteDataButton->setObjectName(QString::fromUtf8("deleteDataButton"));
        deleteDataButton->setGeometry(QRect(490, 210, 111, 41));
        comfirmButton = new QPushButton(centralwidget);
        comfirmButton->setObjectName(QString::fromUtf8("comfirmButton"));
        comfirmButton->setGeometry(QRect(950, 510, 111, 41));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(810, 510, 111, 41));
        textOutput = new QTextEdit(centralwidget);
        textOutput->setObjectName(QString::fromUtf8("textOutput"));
        textOutput->setGeometry(QRect(20, 560, 1041, 261));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1083, 22));
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
        createButton->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        addColumnButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\241\250\345\255\227\346\256\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\241\250\346\223\215\344\275\234\357\274\232", nullptr));
        alterColumnBotton->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\350\241\250\345\255\227\346\256\265", nullptr));
        deleteColumnButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\250\345\255\227\346\256\265", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\272\223/\350\241\250\357\274\232", nullptr));
        insertDataButton->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\346\225\260\346\215\256", nullptr));
        deleteDataButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        comfirmButton->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        menuMainWindow->setTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
