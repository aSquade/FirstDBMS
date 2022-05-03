/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QFrame *frame;
    QLineEdit *usernameEdit;
    QLabel *usernameLabel;
    QLineEdit *passwordEdit;
    QLabel *passwordLabel;
    QLabel *confirmpasswordLabel;
    QLineEdit *confirmpasswordEdit;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(648, 540);
        frame = new QFrame(Register);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setGeometry(QRect(20, 10, 611, 511));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        usernameEdit = new QLineEdit(frame);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setGeometry(QRect(230, 60, 311, 41));
        usernameEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        usernameLabel = new QLabel(frame);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setGeometry(QRect(100, 70, 81, 21));
        usernameLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        passwordEdit = new QLineEdit(frame);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(230, 160, 311, 41));
        passwordEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        passwordLabel = new QLabel(frame);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(110, 170, 81, 21));
        passwordLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        confirmpasswordLabel = new QLabel(frame);
        confirmpasswordLabel->setObjectName(QString::fromUtf8("confirmpasswordLabel"));
        confirmpasswordLabel->setGeometry(QRect(100, 280, 111, 21));
        confirmpasswordLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        confirmpasswordEdit = new QLineEdit(frame);
        confirmpasswordEdit->setObjectName(QString::fromUtf8("confirmpasswordEdit"));
        confirmpasswordEdit->setGeometry(QRect(230, 270, 311, 41));
        confirmpasswordEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        confirmButton = new QPushButton(frame);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(130, 380, 91, 31));
        confirmButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        cancelButton = new QPushButton(frame);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(330, 380, 91, 31));
        cancelButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Form", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("Register", "\350\276\223\345\205\245\346\263\250\345\206\214\347\224\250\346\210\267\345\220\215", nullptr));
        usernameLabel->setText(QCoreApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("Register", "\350\276\223\345\205\245\346\263\250\345\206\214\345\257\206\347\240\201", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Register", "\345\257\206\347\240\201", nullptr));
        confirmpasswordLabel->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        confirmpasswordEdit->setPlaceholderText(QCoreApplication::translate("Register", "\350\276\223\345\205\245\347\241\256\350\256\244\346\263\250\345\206\214\345\257\206\347\240\201", nullptr));
        confirmButton->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("Register", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
