#ifndef REGISTER_H
#define REGISTER_H
#include "ui_register.h"
#include "user.h"
#include <QRegExp>
#include <QButtonGroup>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {class Register; }
QT_END_NAMESPACE

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();


private slots:

    //取消按钮触发
    void on_cancelButton_clicked();
    //确认按钮触发
    void on_confirmButton_clicked();
    //检查用户名和密码输入是否符合规范
    int check_input(QString s1,QString s2,QString s3);
    //清空输入框
    void clear_edit();


private:
    Ui::Register *reui;
    int checkInput;
    QRegExp usrRx;
    QRegExp pwdRx;
    QMessageBox msgBox;
};


#endif // REGISTER_H
