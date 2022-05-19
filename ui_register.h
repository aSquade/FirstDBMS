/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLineEdit *confirmpasswordEdit;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLineEdit *passwordEdit;
    QLineEdit *usernameEdit;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(375, 297);
        confirmpasswordEdit = new QLineEdit(Register);
        confirmpasswordEdit->setObjectName(QString::fromUtf8("confirmpasswordEdit"));
        confirmpasswordEdit->setGeometry(QRect(30, 160, 311, 41));
        confirmpasswordEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        confirmButton = new QPushButton(Register);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(50, 240, 91, 31));
        confirmButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        cancelButton = new QPushButton(Register);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(220, 240, 91, 31));
        cancelButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        passwordEdit = new QLineEdit(Register);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(30, 90, 311, 41));
        passwordEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        usernameEdit = new QLineEdit(Register);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setGeometry(QRect(30, 20, 311, 41));
        usernameEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Form", nullptr));
        confirmpasswordEdit->setPlaceholderText(QCoreApplication::translate("Register", "\350\276\223\345\205\245\347\241\256\350\256\244\346\263\250\345\206\214\345\257\206\347\240\201", nullptr));
        confirmButton->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("Register", "\345\217\226\346\266\210", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("Register", "\350\276\223\345\205\245\346\263\250\345\206\214\345\257\206\347\240\201", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("Register", "\350\276\223\345\205\245\346\263\250\345\206\214\347\224\250\346\210\267\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
