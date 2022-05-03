/********************************************************************************
** Form generated from reading UI file 'columnaddwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLUMNADDWINDOW_H
#define UI_COLUMNADDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColumnAddWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *check;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QPushButton *addMoreButton;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_4;
    QLineEdit *DB_Name;
    QLabel *label_8;
    QLineEdit *checkName;
    QLineEdit *TBL_Name;
    QLineEdit *columnName;
    QLabel *label_5;
    QComboBox *columnType;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ColumnAddWindow)
    {
        if (ColumnAddWindow->objectName().isEmpty())
            ColumnAddWindow->setObjectName(QString::fromUtf8("ColumnAddWindow"));
        ColumnAddWindow->resize(460, 493);
        centralwidget = new QWidget(ColumnAddWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        check = new QTextEdit(centralwidget);
        check->setObjectName(QString::fromUtf8("check"));
        check->setGeometry(QRect(30, 290, 401, 91));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(180, 410, 101, 31));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(330, 410, 101, 31));
        addMoreButton = new QPushButton(centralwidget);
        addMoreButton->setObjectName(QString::fromUtf8("addMoreButton"));
        addMoreButton->setGeometry(QRect(30, 410, 101, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 250, 121, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 100, 71, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(250, 5, 121, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 180, 121, 31));
        DB_Name = new QLineEdit(centralwidget);
        DB_Name->setObjectName(QString::fromUtf8("DB_Name"));
        DB_Name->setGeometry(QRect(30, 50, 181, 31));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 0, 131, 51));
        checkName = new QLineEdit(centralwidget);
        checkName->setObjectName(QString::fromUtf8("checkName"));
        checkName->setGeometry(QRect(250, 210, 181, 31));
        TBL_Name = new QLineEdit(centralwidget);
        TBL_Name->setObjectName(QString::fromUtf8("TBL_Name"));
        TBL_Name->setGeometry(QRect(250, 50, 181, 31));
        columnName = new QLineEdit(centralwidget);
        columnName->setObjectName(QString::fromUtf8("columnName"));
        columnName->setGeometry(QRect(30, 130, 181, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 180, 121, 31));
        columnType = new QComboBox(centralwidget);
        columnType->addItem(QString());
        columnType->addItem(QString());
        columnType->addItem(QString());
        columnType->addItem(QString());
        columnType->addItem(QString());
        columnType->setObjectName(QString::fromUtf8("columnType"));
        columnType->setGeometry(QRect(30, 210, 181, 31));
        ColumnAddWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ColumnAddWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 460, 22));
        ColumnAddWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ColumnAddWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ColumnAddWindow->setStatusBar(statusbar);

        retranslateUi(ColumnAddWindow);

        QMetaObject::connectSlotsByName(ColumnAddWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ColumnAddWindow)
    {
        ColumnAddWindow->setWindowTitle(QCoreApplication::translate("ColumnAddWindow", "MainWindow", nullptr));
        confirmButton->setText(QCoreApplication::translate("ColumnAddWindow", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("ColumnAddWindow", "\345\217\226\346\266\210", nullptr));
        addMoreButton->setText(QCoreApplication::translate("ColumnAddWindow", "\347\273\247\347\273\255\346\267\273\345\212\240", nullptr));
        label_6->setText(QCoreApplication::translate("ColumnAddWindow", "\347\272\246\346\235\237\345\206\205\345\256\271\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("ColumnAddWindow", "\345\255\227\346\256\265\345\220\215\347\247\260\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("ColumnAddWindow", "\350\241\250\345\220\215\347\247\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("ColumnAddWindow", "\345\255\227\346\256\265\347\261\273\345\236\213\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("ColumnAddWindow", "\345\272\223\345\220\215\347\247\260\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("ColumnAddWindow", "\347\272\246\346\235\237\345\220\215\347\247\260\357\274\232", nullptr));
        columnType->setItemText(0, QCoreApplication::translate("ColumnAddWindow", "int", nullptr));
        columnType->setItemText(1, QCoreApplication::translate("ColumnAddWindow", "double", nullptr));
        columnType->setItemText(2, QCoreApplication::translate("ColumnAddWindow", "varchar", nullptr));
        columnType->setItemText(3, QCoreApplication::translate("ColumnAddWindow", "bool", nullptr));
        columnType->setItemText(4, QCoreApplication::translate("ColumnAddWindow", "datetime", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ColumnAddWindow: public Ui_ColumnAddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLUMNADDWINDOW_H
