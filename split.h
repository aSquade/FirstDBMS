#ifndef SPLIT_H
#define SPLIT_H

#include "string"
#include "sheet.h"
#include <QString>
#include <QDebug>


class Split
{
public:
    Split();
    void create_(QString str);
    void alter_(QString str);
    Sheet select_(QString str,QString username);
    QString find_opendb(QString user);//找到打开的库
    bool variablecheck(QString str);    //检查变量名称是否符合正则表达式
};

#endif // SPLIT_H
