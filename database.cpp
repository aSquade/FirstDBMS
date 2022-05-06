#include "database.h"
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
#include <QCoreApplication>
using namespace std;
Database::Database(QString usrname,QString dbname){
    databasename=dbname;
    username = usrname;
}
Database::~Database(){

}
bool Database::del_directory(const QString &path){
    if(path.isEmpty()){
        return false;
    }
    QDir dir(path);
    if(!dir.exists()){
        return true;
    }
    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
        QFileInfoList fileList = dir.entryInfoList();
        foreach (QFileInfo fi, fileList)
        {
            if (fi.isFile())
            {
                fi.dir().remove(fi.fileName());
            }
            else
            {
                del_directory(fi.absoluteFilePath());
            }
        }
        return dir.rmpath(dir.absolutePath());


}
//数据库信息写入用户名所在文件夹下的database.txt文件内
int Database::db_write(QString usrname,QString dbname){
    QString dbName = dbname;
    QString usrName = usrname;
    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName;//用户文件夹位置
    QString fileName = pathName+"/"+"database.txt";
    QFile file(fileName);
    QFile sysdb(FileName+"/data/sysDB.db");
    QDir dir;
    dir.mkdir(pathName+"/"+dbName);//创建该数据库所属文件夹
    file.open(QIODevice::Append|QIODevice::Text);
    sysdb.open(QIODevice::Append|QIODevice::Text);
    if(file.isOpen()&&sysdb.isOpen()){
         QFileInfo info(fileName);
         QString str = info.birthTime().toString();
         QString dbInfo = dbname+"#"+ pathName+"#"+str+"#"+"用户数据库";//#作为分隔符
         QString dbInfo2= usrName+"#"+dbname+"#"+ pathName+"#"+str+"#"+"用户数据库";
         QTextStream out(&file);//写入
         QTextStream out2(&sysdb);
         out << dbInfo<<endl;
         out2<<dbInfo2<<endl;
         file.close();
         sysdb.close();
         return 0;
    }else{
        //打印信息：文件无法打开
        file.close();
        sysdb.close();
        return -1;
    }
}
//检查数据库是否存在
int Database::check_dbexists(QString usrname,QString dbname){
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
            return 0;       //文件为空，数据库不存在，可以创建
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

 //数据库删除
void Database::db_out(QString usrname,QString dbname){
    QString userName = usrname;
    QString dbName = dbname;
    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+userName;//用户文件夹位置
    QString fileName = pathName+"/"+"database.txt";
    QString delPath = pathName+"/"+dbName;
    QFile inputfile(fileName);
    QFile sysdb(FileName+"/data/sysDB.db");
    QStringList lines;
    QStringList lines2;
    inputfile.open(QIODevice::ReadWrite|QIODevice::Text);
    sysdb.open(QIODevice::ReadWrite|QIODevice::Text);
    if(inputfile.isOpen()&&sysdb.isOpen()){
        QTextStream out(&inputfile);
        QTextStream out2(&inputfile);
        QString data;
        QString sysdata;
         while(!out.atEnd()){
             data = out.readLine();
             QStringList dbData=data.split("#");
             if(dbName!=dbData.at(0)){
                 //把不是该数据库的数据库信息复制到链里
                lines.push_back(data);
             }
        }
         while(!sysdb.atEnd()){
             sysdata = sysdb.readLine();
             QStringList sysdbData=sysdata.split("#");
             if(dbName!=sysdbData.at(1)){
                 //把不是该数据库的数据库信息复制到链里
                lines2.push_back(sysdata);
             }
         }
         inputfile.remove();
         sysdb.remove();
         QFile outputfile(fileName);
         QFile sysdb2(FileName+"/data/sysDB.db");
         if(outputfile.open(QIODevice::WriteOnly | QIODevice::Text)){
                 QTextStream edit(&outputfile);
                 for(int i=0;i<lines.size();i++){
                 edit<<lines[i]<<endl;
        }
                 outputfile.close();
    }
         if(sysdb2.open(QIODevice::WriteOnly | QIODevice::Text)){
             QTextStream edit2(&sysdb2);
             for(int i=0;i<lines2.size();i++){
                 edit2<<lines[i]<<endl;
             }
             sysdb2.close();
         }
         del_directory(delPath);
    }
}


