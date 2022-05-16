#include "table.h"
#include "user.h"
#include <QString>
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
#include <QMessageBox>
#include <QMainWindow>
#include <string.h>
#include <io.h>
#include <QCoreApplication>

using namespace std;
table::table(QString usrname,QString dbname,QString tblname){
    databasename = dbname;
    username = usrname;
    tablename = tblname;
}
table::~table(){

}


int table::coltype_check(QString coltype){
    int a = QString::compare(coltype, "integer", Qt::CaseInsensitive);
    int b = QString::compare(coltype, "bool", Qt::CaseInsensitive);
    int c = QString::compare(coltype, "double", Qt::CaseInsensitive);
    int d = QString::compare(coltype, "varchar", Qt::CaseInsensitive);
    int e = QString::compare(coltype, "datetime", Qt::CaseInsensitive);

    if(a==0){
        return 1;
    }else if(b==0){
        return 2;
    }else if(c==0){
        return 3;
    }else if(d==0){
        return 4;
    }else {
        return 5;
    }
}
QString table::get_path(QString usrname,QString dbname){
    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrname+"/"+dbname;//用户文件夹位置
    QString fileName = pathName+"/"+"table.txt";
    return fileName;
}
int table::db_exists(QString usrname,QString dbname){
    QString dbName = dbname;
    QString usrName = usrname;
    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName;//用户文件夹位置
    QString fileName = pathName+"/"+"database.txt";
    QFile file(fileName);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    if(file.isOpen()){
        //打开成功则进行遍历查询
        if(file.size()==0){
            return 0;       //文件为空，数据库不存在
        }else{
            QTextStream out(&file);
            QString data;
             while(!out.atEnd()){
                 data= out.readLine();
                 QStringList dbData=data.split("#");
                 if(dbName==dbData.at(0)){
                     //该数据库已存在
                     file.close();
                     return -1;
                 }
             }
             file.close();
             return 1;//该数据库不存在
        }
    }
    return -2;
}

int table::tbl_exists(QString usrname,QString dbname,QString tblname){
    QString dbName = dbname;
    QString usrName = usrname;
    QString tblName = tblname;
    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName+"/"+dbName;//用户文件夹位置
    QString fileName = pathName+"/"+"table.txt";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(file.isOpen()){
        //打开成功则进行遍历查询
        if(file.size()==0)
        {
            return 0;       //文件为空，表不存在，可以创建
        }else{
            QTextStream out(&file);
            QString strAll;
            QStringList strList;

            strAll = out.readAll();
            strList = strAll.split("\n");
            for(int i = 0;i<strList.count();i++){
                QString tblname = strList.at(i);
                if(tblname == tblName){
                    //表名已存在
                    file.close();
                    return -1;
                }
            }

             file.close();
             return 1;//该表不存在
        }
    }
    return -2;
}

int table::table_in(QString usrname,QString dbname,QString tblname,QString colname,QString coltype,QString check_name,QString check){
    QString dbName = dbname;
    QString usrName = usrname;
    QString tblName = tblname;
    QString colName = colname;
    QString colType = coltype;
    QString cheName = check_name;
    QString che = check;
    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName+"/"+dbName;//用户文件夹位置
    QString fileName = pathName+"/"+"table.txt";
    QFile file(fileName);
    QDir dir;
    dir.mkdir(pathName+"/"+tblName);//创建该表所属文件夹
    QFile systdf(FileName+"/data/"+usrName+"/"+dbName+"/"+tblName+"/"+tblName+".tdf");
    QFile systic(FileName+"/data/"+usrName+"/"+dbName+"/"+tblName+"/"+tblName+".tic");
    QFile systid(FileName+"/data/"+usrName+"/"+dbName+"/"+tblName+"/"+tblName+".tid");
    QFile systrd(FileName+"/data/"+usrName+"/"+dbName+"/"+tblName+"/"+tblName+".trd");
    file.open(QIODevice::Append|QIODevice::Text);
    systdf.open(QIODevice::Append|QIODevice::Text);
    systic.open(QIODevice::Append|QIODevice::Text);
    systid.open(QIODevice::Append|QIODevice::Text);
    systrd.open(QIODevice::Append|QIODevice::Text);
    if(file.isOpen()&&systdf.isOpen()&&systic.isOpen()&&systid.isOpen()&&systrd.isOpen()){
         QFileInfo info(fileName);
         QString tblInfo1 = tblName;//#作为分隔符
         QString tblInfo2 = colName+"#"+colType;
         QString tblInfo3 = cheName+"#"+che;
         QTextStream out1(&file);//写入
         QTextStream out2(&systdf);
         QTextStream out3(&systic);
         out1 << tblInfo1 <<endl;
         out2 << tblInfo2 <<endl;
         out3 << tblInfo3 <<endl;

         file.close();
         systdf.close();
         systic.close();
         systid.close();
         systrd.close();
         return 0;
    }else{
        //打印信息：文件无法打开
        file.close();
        systdf.close();
        systic.close();
        systid.close();
        systrd.close();
        return -1;
    }
}

void table::table_out(QString usrname,QString dbname,QString tblname){
    QString userName = usrname;
    QString dbName = dbname;
    QString tblName = tblname;
    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+userName+"/"+dbName;//用户数据库文件夹位置
    QString fileName = pathName+"/"+"table.txt";
    QString delPath = QString(pathName+"/"+tblName);
    QFile inputfile(fileName);
    QFile systdf(FileName+"/data/"+userName+"/"+dbName+"/"+tblName+"/"+tblname+".tdf");
    QFile systic(FileName+"/data/"+userName+"/"+dbName+"/"+tblName+"/"+tblname+".tic");
    QFile systid(FileName+"/data/"+userName+"/"+dbName+"/"+tblName+"/"+tblname+".tid");
    QFile systrd(FileName+"/data/"+userName+"/"+dbName+"/"+tblName+"/"+tblname+".trd");
    QStringList lines;
    //QStringList lines2;
    inputfile.open(QIODevice::ReadWrite|QIODevice::Text);
    //systbl.open(QIODevice::ReadWrite|QIODevice::Text);
    if(inputfile.isOpen()){
        QTextStream out(&inputfile);
        //QTextStream out2(&inputfile);
        QString data;
        //QString sysdata;
         while(!out.atEnd()){
             data = out.readLine();
             QStringList dbData=data.split("#");
             if(tblName!=dbData.at(0)){
                 //把不是该表的表信息复制到链里
                lines.push_back(data);
             }
        }
         /*while(!systbl.atEnd()){
             sysdata = systbl.readLine();
             QStringList systblData=sysdata.split("#");
             if(dbName!=systblData.at(1)){
                 //把不是该表的表信息复制到链里
                lines2.push_back(sysdata);
             }
         }*/
         inputfile.remove();
         systdf.remove();
         systic.remove();
         systid.remove();
         systrd.remove();
         QFile outputfile(fileName);
         //QFile systbl2(FileName+"/data/"+userName+"/"+dbName+"/"+tblName+"/"+tblName+".tdf");
         if(outputfile.open(QIODevice::WriteOnly | QIODevice::Text))
         {
                 QTextStream edit(&outputfile);
                 for(int i=0;i<lines.size();i++){
                 edit<<lines[i]<<endl;
         }
                 outputfile.close();
    }
         /*if(systbl2.open(QIODevice::WriteOnly | QIODevice::Text)){
             QTextStream edit2(&systbl2);
             for(int i=0;i<lines2.size();i++){
                 edit2<<lines[i]<<endl;
             }
             systbl2.close();
         }*/
         QDir qDir(delPath);
         qDir.removeRecursively();//删除表文件夹

    }
}
