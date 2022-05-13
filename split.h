#ifndef SPLIT_H
#define SPLIT_H

#include "string"
#include <QString>
#include <QDebug>


class Split
{
public:
    Split();
    void create_(QString str);
    void drop_(QString str);
    void insert_(QString str);
    void delete_(QString str);
    void alter_(QString str);
    void select_(QString str);
    int rename_table(QString usrname, QString tbnewname, QString tbpastname, QString dbname);
    int rename_db(QString usrname, QString dbnewname, QString dbpastname);
    int opendb_(QString dbname, QString usrname);
    int closedb_(QString dbname, QString usrname);
    bool variablecheck(QString str);    //检查变量名称是否符合正则表达式
};

#endif // SPLIT_H
