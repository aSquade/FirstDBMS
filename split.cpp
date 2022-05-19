#include "split.h"
#include "user.h"
#include "database.h"
#include "table.h"
#include "sheet.h"
#include <QDebug>
#include <QTextStream>
#include <QStringList>
#include <iostream>
#include <QTextStream>
#include <QByteArray>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QDateTime>
#include <QRegExp>
#include <QRegExpValidator>
#include <QCoreApplication>
Split::Split()
{

}
QString find_opendb(QString user){
    QString db;
    QString filePath = QCoreApplication::applicationDirPath()+"/data/"+user+'/'+"database.txt";
    QFile file(filePath);
    if(file.open((QIODevice::ReadOnly|QIODevice::Text))){
        //找到结尾是open的数据库
        QString strAll;
        QStringList strList;
        QTextStream stream(&file);
        strAll = stream.readAll();
        strList = strAll.split('\n');//以行为分割存到list里
        for(int i = 0; i<strList.count();i++){
            QString strinfo = strList.at(i);
            QStringList infolist = strinfo.split("#");
            if(infolist.contains("open")){
                //此库是打开的，应对其进行操作
                db = infolist.at(0);
                file.close();
                return db;
            }
        }
    }
    file.close();
    return NULL;
}
bool variablecheck(QString str){
    //各种名称的要求：数据库名、表名、列名要求智能大小写字母，3到15个字符组成
    QRegExp  name("^[a-zA-Z_]{3,15}$");
    //QRegExpValidator nameVli(name, 0);  //用于执行匹配操作
    if(name.exactMatch(str) && str != "create" && str != "drop" && str != "delete" && str != "alter"
             && str != "update" && str != "select" && str != "open" && str != "close" && str != "table"
             && str != "database" && str != "index"){
        return true;

    }else{
        return false;
    }
}

Sheet selectDao(QString username,QString databasename,QStringList tableList, QStringList columnList, QStringList judgeList){
    try{
        Sheet all;//总表
        //暂不考虑子查询
        for(int i=0;i<tableList.size();i++){
            //qDebug()<<tableList[i];
            Sheet temp(username,tableList[i],databasename);
            //qDebug()<<"tempsize"<<temp.getData()[0].size();
            all = all.Cartesian(temp);
            //qDebug()<<"size"<<all.getData()[0].size();
        }
        if(!judgeList.isEmpty()){
             QVector<int> where = all.getWhere(judgeList);
            //qDebug()<<"where"<<where.size();
            //只保留符合where条件的数据
            QVector<QVector<QString>> newData;
            for(int i=0;i<all.getData().size();i++){
                if(where.contains(i)){
                    newData.append(all.getData()[i]);
                    //qDebug()<<i;
                }
            }
            all.setData(newData);
        }
        return all.SelectData(columnList);
    }catch(QString exception){
        throw QString(exception);
    }
    //return all.SelectData(columnList,groupList,orderList,desc);
}



Sheet select_(QString str,QString username){
    //qDebug() << "select" << endl;
    Sheet t;
    QString db = find_opendb(username);
    if(db != NULL){
        //select * from 表名 （where……）
        //select 字段名 from 表名 （where……）
        QString tbl;
        QString col;
        QString judge;

        QStringList colList; // SELECT ...
        QStringList tblList;  // FROM ...
        QStringList judgeList;  // WHERE
        QRegularExpression re(
            "^select\\s((?:[\\w\\.]+,)*[\\w\\.]+|\\*)\\sfrom\\s((?:\\w+,)*\\w+)"
            "(?:\\swhere\\s((?:[A-Za-z_\\.]+\\s?(?:>|<|>=|<=|!=|=)\\s?[\\w\\.]+"
            "\\s(?:and|or)\\s)*[A-Za-z_\\.]+\\s?(?:>|<|>=|<=|!=|=)\\s?[\\w\\.]+"
            "))?");
        QRegularExpressionMatch match = re.match(str);
         if (match.hasMatch()) {
            if(str.contains("where")){
                QRegularExpression re(
                                    "\\swhere\\s((?:[A-Za-z_\\.]+\\s?(?:>|<|>=|<=|!=|=)\\s?["
                                    "\\w\\.]+\\s(?:and|or)\\s)*[A-Za-z_\\.]+\\s?(?:>|<|>=|<=|!="
                                    "|=)\\s?[\\w\\.]+)");
                QRegularExpressionMatch match = re.match(str);
                if (match.hasMatch()) {
                    judge = match.captured(1);
                    qDebug()<<"where条件"<<judge<<endl;
                    judgeList = judge.split(" or ");
               }
            }
            QRegularExpression re("^select\\s((?:[\\w\\.]+,)*[\\w\\.]+|\\*)"
                                  "\\sfrom\\s((?:\\w+,)*\\w+)");
            QRegularExpressionMatch match = re.match(str);
             if (match.hasMatch()) {
                 col = match.captured(1);
                 qDebug()<<"column"<<col<<endl;
                 tbl = match.captured(2);
                 qDebug()<<"table"<<tbl<<endl;
                 tblList = tbl.split(",");//表列表
                 colList = col.split(",");//字段列表
                 t = selectDao(username,db, tblList, colList, judgeList);
                 return t;
             }
         }
    }

}

void alter_(QString str){
    //qDebug() << "alter" << endl;
}


