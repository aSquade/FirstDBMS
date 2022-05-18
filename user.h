#ifndef USER_H
#define USER_H
#include <QWidget>
#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QStringList>
using namespace std;
class User
{
public:
    friend class Register;
    friend class Login;
    //构造时传入用户名和密码
    User(QString usrname, QString passwd,QString pow);
    ~User();
private:
    QString username;
    QString password;
    QString power;
public:
    QList<User *> userList;//定义一条链表存放所有用户
    int check_exist(QString usr);//检验用户名是否已存在
    int user_write(User *newUser);//用户信息写入文件
    int user_read(User usr);//用户信息读取登录
    QString toUpperAndLower(QString src);//加密函数
};
#endif // USER_H
