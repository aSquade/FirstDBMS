#include "column.h"
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
column::column(QString usrname,QString dbname,QString tblname,QString colname)
{
    databasename = dbname;
    username = usrname;
    tablename = tblname;
    columnname = colname;
}
column::~column()
{

}
int column::coltype_check(QString coltype)
{
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
//库是否存在
int column::db_exists(QString usrname,QString dbname)
{
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
//表是否存在
int column::tbl_exists(QString usrname,QString dbname,QString tblname)
{
    QString dbName = dbname;
    QString usrName = usrname;
    QString tblName = tblname;

    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName+"/"+dbName;//用户文件夹位置
    QString fileName = pathName+"/"+"table.txt";
    QFile file(fileName);

    file.open(QIODevice::ReadWrite|QIODevice::Text);
    if(file.isOpen()){
        //打开成功则进行遍历查询
        if(file.size()==0){
            return 0;       //文件为空，表不存在，可以创建
        }else{
            QTextStream out(&file);
            QString data;
             while(!out.atEnd()){
                 data= out.readLine();
                 QStringList tblData=data.split("#");
                 if(tblName==tblData.at(0)){
                     //该表已存在
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

//检查列是否存在
int column::col_exists(QString usrname,QString dbname,QString tblname,QString colname)
{
    QString dbName = dbname;
    QString usrName = usrname;
    QString tblName = tblname;
    QString colName = colname;

    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName+"/"+dbName+"/"+tblname;//用户文件夹位置
    QString fileName1= pathName+"/"+tblname+".tdf";//存储字段相关信息
    QString fileName2= pathName+"/"+tblname+".tic";
    QString fileName3= pathName+"/"+tblname+".tid";
    QString fileName4= pathName+"/"+tblname+".trd";

    QFile file(fileName1);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    if(file.isOpen())
    {
        //打开成功则进行遍历查询
        if(file.size()==0){
            return 0;       //文件为空，列不存在，可以创建
        }else{
            QTextStream out(&file);
            QString data;
             while(!out.atEnd()){
                 data= out.readLine();
                 QStringList colData=data.split("#");
                 if(colName==colData.at(0)){
                     //该列已存在
                     file.close();
                     return -1;
                 }
             }
             file.close();
             return 1;//该列不存在
        }
    }
    return -2;
}
//写入列
int column::col_in(QString usrname,QString dbname,QString tblname,QString colname,QString coltype,QString check_name,QString check)
{
    QString dbName = dbname;
    QString usrName = usrname;
    QString tblName = tblname;
    QString colName = colname;
    QString colType = coltype;
    QString cheName = check_name;
    QString che = check;


    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName+"/"+dbName+"/"+tblname;//用户文件夹位置
    QString fileName1= pathName+"/"+tblname+".tdf";//存储字段相关信息
    QString fileName2= pathName+"/"+tblname+".tic";
    QString fileName3= pathName+"/"+tblname+".tid";
    QString fileName4= pathName+"/"+tblname+".trd";

    QFile file1(fileName1);
    QFile file2(fileName2);
    QFile file3(fileName3);
    QFile file4(fileName4);

    file1.open(QIODevice::Append|QIODevice::Text);
    file2.open(QIODevice::Append|QIODevice::Text);
    file3.open(QIODevice::Append|QIODevice::Text);
    file4.open(QIODevice::Append|QIODevice::Text);

    if(file1.isOpen()&&file2.isOpen()&&file3.isOpen()&&file4.isOpen())
    {
         QFileInfo info(fileName1);
         QString colInfo1 = colName+"#"+colType;
         QString colInfo2 = cheName+"#"+che;
         QTextStream out1(&file1);//写入
         QTextStream out2(&file2);
         QTextStream out3(&file3);

         out1 << colInfo1 <<endl;
         out2 << colInfo2 <<endl;

         file2.close();
         return 0;
    }else{
        //打印信息：文件无法打开
        file1.close();
        file2.close();
        file3.close();
        file4.close();
        return -1;
    }
}

//删除列
void column::col_out(QString usrname,QString dbname,QString tblname,QString colname)
{
    QString usrName = usrname;
    QString dbName = dbname;
    QString tblName = tblname;
    QString colName = colname;

    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName+"/"+dbName+"/"+tblname;//用户文件夹位置
    QString fileName1= pathName+"/"+tblname+".tdf";//存储字段相关信息
//    QString fileName2= pathName+"/"+tblname+".tic";
//    QString fileName3= pathName+"/"+tblname+".tid";
//    QString fileName4= pathName+"/"+tblname+".trd";
    QString delPath = QString(pathName+"/"+tblName);

    QFile inputfile(fileName1);
    QFile systdf(fileName1);
//    QFile systic(fileName2);
//    QFile systid(fileName3);
//    QFile systrd(fileName4);

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
             QStringList colData=data.split("#");
             if(colName!=colData.at(0)){
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
//         systic.remove();
//         systid.remove();
//         systrd.remove();
         QFile outputfile(fileName1);
         //QFile systbl2(FileName+"/data/"+userName+"/"+dbName+"/"+tblName+"/"+tblName+".tdf");
         if(outputfile.open(QIODevice::WriteOnly | QIODevice::Text)){
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
//         QDir qDir(delPath);
//         qDir.removeRecursively();//删除表文件夹

    }
}

