#include "user.h"
#include "register.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <iostream>
#include <QTextStream>
#include <QByteArray>
using namespace std;
User::User(QString usrname, QString passwd){
    username=usrname;
    password=passwd;
}
User::~User(){

}

//检验用户名是否已存在
int User::check_exist(QString usr){
    QFile file("user.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(file.isOpen()){
        if(file.size()==0){
            return 0;
        }else{
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
int User::user_write(User *newUser){
        QFile file("user.txt");
        file.open(QIODevice::Append|QIODevice::Text);
        if(file.isOpen()){
            QTextStream in(&file);
            in<<newUser->username<<":"<<newUser->password<<endl;
            userList.push_back(newUser);
            file.close();
            return 0;
        }else{
            return -1;
        }
}
//用户信息读取登录
int User::user_read(User usr){
    QFile file("user.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Text);//文件不存在会自动创建
    if(file.isOpen()){
        if(file.size()){
            QString data;
            QStringList userData;
            QTextStream out(&file);
            while(!out.atEnd()){//一行行读直到末尾
                data=out.readLine();
                userData=data.split(":");//以冒号为分隔符存到userData里
                User *newUser=new User(userData.at(0),userData.at(1));
                if((usr.username==userData.at(0))&&(usr.password==userData.at(1))){
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



