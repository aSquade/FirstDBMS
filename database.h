#ifndef DATABASE_H
#define DATABASE_H
#include <QWidget>
#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#include "user.h"
using namespace std;
class Database{
public:
    friend class User;
    //构造时传入用户名和库名
    Database(QString usrname,QString dbname);
    ~Database();
protected:
    QString databasename;
    QString username;
public:
    void db_out(QString usrname,QString dbname);//数据库删除
    int db_read(QString usrname,QString dbname);      //读取数据库信息
    int check_dbexists(QString usrname,QString dbname);//检查数据库是否存在
    int db_write(QString usrname,QString dbname);     //数据库信息写入
    bool del_directory(const QString &path);//删除文件夹
};

#endif // DATABASE_H
