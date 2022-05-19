#ifndef TABLE_H
#define TABLE_H
#include <QWidget>
#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#include "user.h"

using namespace std;

class table
{
public:
    friend class User;
    //构造时传入用户名、库名和表名
    table(QString usrname,QString dbname, QString tblname);
    ~table();

protected:
    QString databasename;
    QString username;
    QString tablename;

public:
    int coltype_check(QString coltype);
    int db_exists(QString usrname,QString dbname);
    int tbl_exists(QString usrname,QString dbname,QString tblname);
    int table_in(QString usrname,QString dbname,QString tblname,QString colname,QString coltype,QString check_name,QString check);
    void table_out(QString usrname,QString dbname,QString tblname);
    QString get_path(QString usrname,QString dbname);
    int rename_tbl(QString usrname, QString tbnewname, QString tbpastname, QString dbname);
};

#endif // TABLE_H
