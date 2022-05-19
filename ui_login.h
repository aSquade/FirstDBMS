/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *registerButton;
    QPushButton *loginButton;
    QLineEdit *UsernameEdit;
    QLineEdit *passwordEdit;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(422, 307);
        registerButton = new QPushButton(Login);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(240, 210, 111, 41));
        registerButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(70, 210, 111, 41));
        loginButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        UsernameEdit = new QLineEdit(Login);
        UsernameEdit->setObjectName(QString::fromUtf8("UsernameEdit"));
        UsernameEdit->setGeometry(QRect(60, 50, 311, 41));
        UsernameEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        passwordEdit = new QLineEdit(Login);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(60, 130, 311, 41));
        passwordEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        registerButton->setText(QString());
        loginButton->setText(QString());
        UsernameEdit->setPlaceholderText(QCoreApplication::translate("Login", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("Login", "\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
