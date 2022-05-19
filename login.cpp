#include "login.h"
#include "ui_login.h"
#include "register.h"
#include "user.h"
#include "mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
using namespace std;
Login::Login(QWidget *parent)
    : QWidget(parent)
    , loui(new Ui::Login)
{
    loui->setupUi(this);

    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/pic/background.png")));
    setPalette(pal);

    loui->loginButton->setStyleSheet("QPushButton{image: url(:/pic/login1.png);}"
                                     "QPushButton:hover{image: url(:/pic/login.png);}");
    loui->loginButton->setFlat(true);

    loui->registerButton->setStyleSheet("QPushButton{image: url(:/pic/signup1.png);}"
                                     "QPushButton:hover{image: url(:/pic/signup.png);}");
    loui->registerButton->setFlat(true);

    loui->passwordEdit->setEchoMode(QLineEdit::Password);//设置密码不可见
    connect(loui->loginButton,SIGNAL(on_LoginButton_clicked()),SLOT(user_read()));
}

Login::~Login()
{
    delete loui;
}

//注册按钮触发
void Login::on_registerButton_clicked()
{
    Register *r = new Register;
     r->setWindowTitle("用户注册");
     r->show();
}
//登录按钮触发
void Login::on_loginButton_clicked()
{
    QString usrname = loui->UsernameEdit->text();
    QString passwd = loui->passwordEdit->text();
    QString pow ;
    QString fileName = QCoreApplication::applicationDirPath();
    QFile file(fileName+"/data/user.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Text);//文件不存在会自动创建
    if(file.isOpen())
    {
        if(file.size())
        {
            QString data;
            QStringList userData;
            QTextStream out(&file);
            while(!out.atEnd())
            {//一行行读直到末尾
                data=out.readLine();
                userData=data.split(":");//以冒号为分隔符存到userData里
                if(usrname==userData.at(0))
                {
                     pow = userData.at(2);
                     break;
                }
            }

        }
    }
     User usr(usrname,passwd,pow); //创建当前用户
    //检查输入内容
    if(usrname==""||passwd=="")
    {
        QMessageBox::information(this,"警告","输入不能为空",QMessageBox::Ok);
    }
    else
    {

        int logCheck = usr.user_read(usr);
        if(logCheck==0)
        {
            //QMessageBox::information(this,"提示","登录成功！",QMessageBox::Ok);
           this->close();
            //传入登录的用户名，方便后面进行各种增删改查存数据的操作
           MainWindow *m = new MainWindow(usr.username,usr.power);
           m->show();
        }else if(logCheck==-1){
           QMessageBox::information(this,"警告","用户不存在或密码错误！",QMessageBox::Ok);
           loui->UsernameEdit->setText("");
           loui->passwordEdit->setText("");
           loui->UsernameEdit->setEnabled(true);
           loui->UsernameEdit->setFocus();
        }else if(logCheck==-2){
            QMessageBox::information(this,"警告","用户文件为空！请创建用户！",QMessageBox::Ok);
        }else{
            QMessageBox::information(this,"警告","文件打开失败！",QMessageBox::Ok);
            this->close();
        }
    }


}
