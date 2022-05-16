#include "row.h"
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
#include <QCoreApplication>
row::row(QString usrname,QString dbname, QString tblname,QStringList colname,QStringList dataitem)
{
    username=usrname;
    dbName=dbname;
    tblName=tblname;
    colName=colname;
    dataItem=dataitem;
}

row::~row()
{

}

//库是否存在
int row::db_exists(QString usrname,QString dbname)
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
int row::tbl_exists(QString usrname,QString dbname,QString tblname)
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
int row::col_exists(QString usrname,QString dbname,QString tblname,QStringList colname)
{
    QString dbName = dbname;
    QString usrName = usrname;
    QString tblName = tblname;
    QStringList colName = colname;

    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName+"/"+dbName+"/"+tblname;//用户文件夹位置
    QString fileName1= pathName+"/"+tblname+".tdf";//存储字段相关信息

    QFile file(fileName1);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    if(file.isOpen())
    {
        //打开成功则进行遍历查询
        if(file.size()==0)
        {
            return 0;       //文件为空，列不存在，可以创建
        }
        else
        {
            QTextStream out(&file);
            QString data;
            int num = 0;
             while(!out.atEnd())
             {
                 data= out.readLine();
                 QStringList colData=data.split("#");
                 for(int i = 0;i<colName.length();i++)
                 {
                     if(colName[i]==colData.at(0))
                     {
                         //该列存在
                        //file.close();
                         //return -1;
                         num++;
                     }
                 }

             }
             file.close();
             if(num==colName.length())
             {
                 return -1;
             }
            else
             {
                 return 1;//该列不存在
             }

        }
    }
    return -2;
}


//检查值是否存在
int row::row_exists(QString usrname,QString dbname,QString tblname,QStringList colname,QStringList dataitem)
{
    QString dbName = dbname;
    QString usrName = usrname;
    QString tblName = tblname;
    QStringList colName = colname;
    QStringList dataItem = dataitem;

    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName+"/"+dbName+"/"+tblname;//用户文件夹位置
    QString fileName= pathName+"/"+tblname+".trd";//存储记录相关

    //读取文件行数
    QFile file(fileName);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    if(file.isOpen())
    {
        //打开成功则进行遍历查询
        if(file.size()==0)
        {
            return 0;       //文件为空，值不存在
        }
        else
        {
            QTextStream out(&file);
            QString data;
            while(!out.atEnd())
             {
                 data = out.readLine();
                 QStringList data_item =data.split("#");

                 QString cmp = colName[0]+':'+dataItem[0];
                  QList<QString>::iterator  it = find(data_item.begin(), data_item.end(),cmp);
                 if (it == data_item.end())
                 {
                      cout << "not" << endl;

                 }
                 else
                 {
                      cout << "it: " <<endl;
                      return -1;
                 }

            }
             file.close();
             return 1;//不存在

        }
    }
    return -2;
}

//写入记录
int row::row_in(QString usrname,QString dbname,QString tblname,QStringList colname,QStringList dataitem)
{
    QString dbName = dbname;
    QString usrName = usrname;
    QString tblName = tblname;
    QStringList colName = colname;
    QStringList dataItem = dataitem;

    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName+"/"+dbName+"/"+tblname;//用户文件夹位置
    QString fileName1= pathName+"/"+tblname+".trd";//存储记录相关信息
    QFile file1(fileName1);

    //每行是一条记录，各值之间用#分隔（所有的字符串值不带引号）
    file1.open(QIODevice::Append|QIODevice::Text);

    if(file1.isOpen())
    {
         QFileInfo info(fileName1);
         for(int i =0;i< dataitem.length();i++)
         {
             QString rowInfo1 = colname[i]+':'+dataitem[i]+'#';
             QTextStream out1(&file1);//写入
             out1 << rowInfo1;//写入一条记录
         }
         QTextStream out2(&file1);
         out2<<"\n";
         file1.close();
         return 0;
    }
    else
    {
        //打印信息：文件无法打开
        file1.close();
        return -1;
    }
}

//删除记录
void row::row_out(QString usrname,QString dbname,QString tblname,QStringList colname,QStringList dataitem)
{
    QString usrName = usrname;
    QString dbName = dbname;
    QString tblName = tblname;
    QStringList colName = colname;
    QStringList dataItem = dataitem;

    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName+"/"+dbName+"/"+tblname;//用户文件夹位置
    QString fileName1= pathName+"/"+tblname+".trd";//存储数值信息
    QFile inputfile(fileName1);
    QFile systrd(fileName1);

    QStringList lines;

    inputfile.open(QIODevice::ReadWrite|QIODevice::Text);
    if(inputfile.isOpen())
    {
        QTextStream out(&inputfile);
        QString data;
        while(!out.atEnd())
        {
             data = out.readLine();
             QStringList data_item =data.split("#");


                     QString cmp = colName[0]+':'+dataItem[0];
                      QList<QString>::iterator  it = find(data_item.begin(), data_item.end(),cmp);
                     if (it == data_item.end())
                     {
                          cout << "not" << endl;
                          lines.push_back(data);
                     }
                     else
                     {
                          cout << "it: " <<endl;
                     }


         }
         inputfile.remove();
         systrd.remove();

         QFile outputfile(fileName1);
         if(outputfile.open(QIODevice::WriteOnly | QIODevice::Text))
         {
                 QTextStream edit(&outputfile);
                 for(int i=0;i<lines.size();i++)
                 {
                    edit<<lines[i]<<endl;
                 }
                 outputfile.close();
         }

    }
}



