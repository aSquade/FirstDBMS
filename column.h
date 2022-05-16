#ifndef COLUMN_H
#define COLUMN_H
#include <QWidget>
#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#include "user.h"

using namespace std;
class column
{
public:
    friend class User;
    //构造时传入用户名、库名和表名
    column(QString usrname,QString dbname, QString tblname,QString colname);
    ~column();

protected:
    QString databasename;
    QString username;
    QString tablename;
    QString columnname;

public:
    int coltype_check(QString coltype);
    int db_exists(QString usrname,QString dbname);
    int tbl_exists(QString usrname,QString dbname,QString tblname);
    int col_exists(QString usrname,QString dbname, QString tblname,QString colname);
    int col_in(QString usrname,QString dbname,QString tblname,QString colname,QString coltype,QString check_name,QString check);
    void col_out(QString usrname,QString dbname,QString tblname,QString colname);
    int col_namechange(QString usrname,QString dbname,QString tblname,QString colname1,QString colname2);
};

#endif // COLUMN_H





