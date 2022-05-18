#include "user.h"
#include "register.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <iostream>
#include <QByteArray>
#include <QDir>
#include <QCoreApplication>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
using namespace std;
User::User(QString usrname, QString passwd,QString pow)
{
    username=usrname;
    password=passwd;
    power = pow;
}
User::~User()
{

}
QString User::toUpperAndLower(QString src)
{
    for(int i = 0; i < src.count(); i++)
    {
            QChar curC = src.at(i);
            if(curC.isUpper())
            {
                curC = curC.toLower();
            }
            else if(curC.isLower())
            {
                curC = curC.toUpper();
            }
            src[i] = curC;
        }
        return src;
}

//检验用户名是否已存在
int User::check_exist(QString usr){
    QString fileName = QCoreApplication::applicationDirPath();//到生成文件的debug文件夹里
    QFile file(fileName+"/data/user.txt");
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    if(file.isOpen()){
        if(file.size()==0)
        {
            file.close();
            return 0;
        }
        else
        {
            QString data;
            QStringList userData;//保存读取到的用户名和密码
            QTextStream out(&file);
            while(!out.atEnd()){
                 data= out.readLine();
                 userData=data.split(":");//以冒号为分隔符将其存到userData里
                 if(usr==userData.at(0))//出现重名的情况
                 {
                     file.close();
                     return -1;
                 }
            }
            file.close();
            return 0;
        }
    }
}

//用户信息写入文件
int User::user_write(User *newUser)
{
        QString fileName = QCoreApplication::applicationDirPath();
        QFile file(fileName+"/data/user.txt");
        QDir dir;
        dir.mkdir(fileName+"/data/"+newUser->username);
        file.open(QIODevice::Append|QIODevice::Text);
        //进行加密
        QByteArray text = newUser->password.toLocal8Bit();
        QByteArray by = text.toBase64();
        QString str = toUpperAndLower(QString(by));
        newUser->password = str;

        if(newUser->username=="admin")
        {
            newUser->power = "admin power";
        }
        else
        {
            newUser->power = "no power";
        }
        if(file.isOpen())
        {
            QTextStream in(&file);
            in<<newUser->username<<":"<<newUser->password<<":"<<newUser->power<<endl;
            userList.push_back(newUser);
            file.close();
            return 0;
        }
        else
        {
            return -1;
        }

}
//用户信息读取登录
int User::user_read(User usr){
    QString fileName = QCoreApplication::applicationDirPath();
    QFile file(fileName+"/data/user.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Text);//文件不存在会自动创建
    if(file.isOpen()){
        if(file.size()){
            QString data;
            QStringList userData;
            QTextStream out(&file);
            while(!out.atEnd()){//一行行读直到末尾
                data=out.readLine();
                userData=data.split(":");//以冒号为分隔符存到userData里
                User *newUser=new User(userData.at(0),userData.at(1),userData.at(2));
                //进行解密
                QString pw = userData.at(1);
                QString str = toUpperAndLower(pw);
                QByteArray text = str.toLocal8Bit();
                QByteArray by = text.fromBase64(text);
                pw = QString(by);
                if((usr.username==userData.at(0))&&(usr.password==pw)){
                    //比对成功，可以登录
                    User::userList.push_back(newUser);
                    userData.clear();//清空，存放下一行
                    file.close();
                    return 0 ;
                }
                User::userList.push_back(newUser);
                userData.clear();//清空，存放下一行
            }
            file.close();
            return -1;
        }else{
            file.close();
            return -2;
        }
    }else{
        return -3;
    }
}




