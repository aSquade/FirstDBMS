#include "register.h"
#include "ui_register.h"
#include "user.h"
#include <QRegExp>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QDebug>
using namespace std;
Register::Register(QWidget *parent)
    : QWidget(parent)
    , reui(new Ui::Register)
{
    reui->setupUi(this);
    reui->passwordEdit->setEchoMode(QLineEdit::Password);
    reui->confirmpasswordEdit->setEchoMode(QLineEdit::Password);
    //建立信号和响应函数
    connect(reui->confirmButton,SIGNAL(on_confirmButton_clicked()),SLOT(check_input()));
    connect(reui->confirmButton,SIGNAL(on_confirmButton_clicked()),SLOT(check_exist()));
    usrRx.setPatternSyntax(QRegExp::RegExp);
    pwdRx.setPatternSyntax(QRegExp::RegExp);
    //大小写敏感
    usrRx.setCaseSensitivity(Qt::CaseSensitive);
    pwdRx.setCaseSensitivity(Qt::CaseSensitive);
    //密码匹配格式为字母开头，仅包含字母数字下划线，6~12位
    pwdRx.setPattern(QString("^[a-zA-Z]\\w{5,11}$"));
    //用户名的匹配格式为4到8位的26个大小写字母和下划线的组合
    usrRx.setPattern(QString("^[a-zA-Z]\\w{3,7}$"));

}

Register::~Register(){
    delete reui;
}
void Register::clear_edit(){
    reui->usernameEdit->setText("");
    reui->passwordEdit->setText("");
    reui->confirmpasswordEdit->setText("");
    reui->usernameEdit->setEnabled(true);
    reui->usernameEdit->setFocus();
}

//检查用户名和密码输入是否规范
int Register::check_input(QString s1,QString s2,QString s3){
    if((s1=="")||(s2=="")||(s3=="")){
        msgBox.information(this,"警告","输入不能为空",QMessageBox::Ok);
        return -1;
    }else if(s2 != s3){
        msgBox.information(this,"警告","两次密码不一致",QMessageBox::Ok);
        reui->passwordEdit->setText("");
        reui->confirmpasswordEdit->setText("");
        reui->passwordEdit->setEnabled(true);
        reui->passwordEdit->setFocus();
        return -1;
    }else{
        if(s1==s2){
            msgBox.information(this,"提示","用户名和密码不能重复！",QMessageBox::Ok);
            clear_edit();
            return -1;
        }
        //三次输入均满足条件，则开始写入文件
        else if(usrRx.exactMatch(s1)&&pwdRx.exactMatch(s2)){

            qDebug()<<"格式正确";
            return 1;
            //this->hide();
        }
        else{
            msgBox.information(this,"提示","格式输入有误！\n"
                           "\n用户名和密码为字母开头仅包含字母数字和下划线的组合\n"
                           "\n密码6~12位，用户名4~8位",QMessageBox::Ok);
            clear_edit();
        }
    }
}

//取消按钮触发
void Register::on_cancelButton_clicked()
{
    this->hide();
}
//确认按钮触发
void Register::on_confirmButton_clicked()
{
    QString usrname = reui->usernameEdit->text();
    QString passwd = reui->passwordEdit->text();
    QString confmpw = reui->confirmpasswordEdit->text();
    //检查用户名和密码格式
    //int ckinput=Register::check_input(usrname,passwd,confmpw);
    int ckinput = 1;
    if(ckinput==1){
        //检查是否重名
        User usr(usrname,passwd);
        int chexist = usr.check_exist(usrname);
        if(chexist<0){
            msgBox.information(this,"提示","该用户名已存在！",QMessageBox::Ok);
            clear_edit();
        }else{
            //将注册信息写入文件
            int chdone = usr.user_write(&usr);
            if(chdone<0){
                msgBox.information(this,"错误","文件无法打开!",QMessageBox::Ok);
            }else{
                msgBox.information(this,"提示","格式正确，注册成功！",QMessageBox::Ok);
                this->hide();
            }
        }
    }
}


