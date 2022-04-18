#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:


    //注册按钮触发
    void on_registerButton_clicked();
    //登录按钮触发
    void on_loginButton_clicked();

private:
    Ui::Login *loui;

};
#endif // LOGIN_H
