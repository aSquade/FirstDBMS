/********************************************************************************
** Form generated from reading UI file 'columndeletewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLUMNDELETEWINDOW_H
#define UI_COLUMNDELETEWINDOW_H

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

class Ui_ColumnDeleteWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QLabel *label_9;
    QLineEdit *DB_Name;
    QLabel *label_8;
    QLineEdit *TBL_Name;
    QLineEdit *columnName;
    QPushButton *alterMoreButton;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ColumnDeleteWindow)
    {
        if (ColumnDeleteWindow->objectName().isEmpty())
            ColumnDeleteWindow->setObjectName(QString::fromUtf8("ColumnDeleteWindow"));
        ColumnDeleteWindow->resize(463, 272);
        centralwidget = new QWidget(ColumnDeleteWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 100, 71, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(250, 20, 71, 16));
        DB_Name = new QLineEdit(centralwidget);
        DB_Name->setObjectName(QString::fromUtf8("DB_Name"));
        DB_Name->setGeometry(QRect(30, 50, 181, 31));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 20, 71, 16));
        TBL_Name = new QLineEdit(centralwidget);
        TBL_Name->setObjectName(QString::fromUtf8("TBL_Name"));
        TBL_Name->setGeometry(QRect(250, 50, 181, 31));
        columnName = new QLineEdit(centralwidget);
        columnName->setObjectName(QString::fromUtf8("columnName"));
        columnName->setGeometry(QRect(30, 130, 181, 31));
        alterMoreButton = new QPushButton(centralwidget);
        alterMoreButton->setObjectName(QString::fromUtf8("alterMoreButton"));
        alterMoreButton->setGeometry(QRect(30, 190, 101, 31));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(180, 190, 101, 31));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(329, 190, 101, 31));
        ColumnDeleteWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ColumnDeleteWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 463, 22));
        ColumnDeleteWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ColumnDeleteWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ColumnDeleteWindow->setStatusBar(statusbar);

        retranslateUi(ColumnDeleteWindow);

        QMetaObject::connectSlotsByName(ColumnDeleteWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ColumnDeleteWindow)
    {
        ColumnDeleteWindow->setWindowTitle(QCoreApplication::translate("ColumnDeleteWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("ColumnDeleteWindow", "\345\255\227\346\256\265\345\220\215\347\247\260\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("ColumnDeleteWindow", "\350\241\250\345\220\215\347\247\260\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("ColumnDeleteWindow", "\345\272\223\345\220\215\347\247\260\357\274\232", nullptr));
        alterMoreButton->setText(QCoreApplication::translate("ColumnDeleteWindow", "\347\273\247\347\273\255\344\277\256\346\224\271", nullptr));
        confirmButton->setText(QCoreApplication::translate("ColumnDeleteWindow", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("ColumnDeleteWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColumnDeleteWindow: public Ui_ColumnDeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLUMNDELETEWINDOW_H
