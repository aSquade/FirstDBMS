#ifndef ROW_H
#define ROW_H
#include <QWidget>
#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#include "user.h"

using namespace std;
class row{
public:
    friend class User;
    //需要获取用户名，库名，表名，字段名，才能在该字段插入数据
    row(QString usrname,QString dbname, QString tblname,QStringList colname,QStringList dataitem);
    ~row();
protected:
    QString dbName;
    QString username;
    QString tblName;
    QStringList colName;
    QStringList dataItem;

public:
    int db_exists(QString usrname,QString dbname);
    int tbl_exists(QString usrname,QString dbname,QString tblname);
    int col_exists(QString usrname,QString dbname, QString tblname,QStringList colname);
    int row_exists(QString usrname,QString dbname,QString tblname,QStringList colname,QStringList dataitem);
    int row_in(QString usrname,QString dbname,QString tblname,QStringList colname,QStringList dataitem);
    void row_out(QString usrname,QString dbname,QString tblname,QStringList colname,QStringList dataitem);

};

#endif // ROW_H


