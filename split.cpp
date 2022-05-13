#include "split.h"
#include "user.h"
#include "database.h"
#include "table.h"
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

bool variablecheck(QString str){
    //各种名称的要求：数据库名、表名、列名要求智能大小写字母，3到15个字符组成
    QRegExp  name("^[a-zA-Z_]{3,15}$");
    //QRegExpValidator nameVli(name, 0);  //用于执行匹配操作
    if(name.exactMatch(str)){
        return true;
    }else{
        return false;
    }
}


//打开数据库操作
int opendb_(QString dbname, QString usrname){
    //首先检查数据库是否存在
    Database db(usrname,dbname);
    int ck_exists = db.check_dbexists(usrname,dbname);
    if(ck_exists >= 0){
        //要打开的数据库不存在，返回-1
        return -1;
    }else{
        //数据库存在，可以打开了，即将最后的单词lock改为open
        //省流版：打开文件，读进stringlist，根据换行符分割
        //找到要打开的dbname所在行，用replace把lock替换
        QString strAll;
        QStringList strList;    //存放所有数据库信息的链

        QString dbName = dbname;
        QString usrName = usrname;
        QString fileName = db.get_dbpath(usrName, dbName);
        QFile readFile(fileName);   //读文件信息

        if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
        {
            QTextStream stream(&readFile);
            strAll = stream.readAll();
            QStringList strlist1 = strAll.split("\n");
            for(int i = 0; i<strlist1.count();i++){
                QString strinfo = strlist1.at(i);
                QStringList infolist = strinfo.split("#");
                if(infolist.at(0).toLower() != dbName){
                    bool orp = strinfo.contains("open");
                    if(orp==true){
                        //有另外的库处于打开状态，此库不可打开
                        readFile.close();
                        return -4;
                    }
                }

            }
        }
        readFile.close();
        QFile writeFile(fileName);      //写新信息
        if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
            QTextStream stream(&writeFile);
            strList = strAll.split("\n");   //每行分开存
            for(int i = 0; i<strList.count();i++){
                QString strinfo = strList.at(i);
                QStringList infolist = strinfo.split("#");

                if(infolist.at(0).toLower() == dbName){

                    strinfo.replace(QString("lock"), QString("open"));
                    if(i != strList.count() -1)
                        stream<<strinfo<<endl;
                    else
                        stream<<strinfo;

                }else{
                    //若不是要操作的库
                    if(i == strList.count() -1){
                        //若是到了最后一行
                        stream<<strList.at(i);
                    }else{
                        stream<<strList.at(i)<<endl;
                    }
                }
            }
        }
            writeFile.close();
            return 1;   //返回1表示操作成功
    }
}

int closedb_(QString dbname, QString usrname){
    //首先检查数据库是否存在
    Database db(usrname,dbname);
    int ck_exists = db.check_dbexists(usrname,dbname);
    if(ck_exists >= 0){
        //要打开的数据库不存在，返回-1
        return -1;
    }else{
        //数据库存在，可以关闭了，即将最后的单词open改为lock
        //省流版：打开文件，读进stringlist，根据换行符分割
        //找到要打开的dbname所在行，用replace把lock替换
        QString strAll;
        QStringList strList;    //存放所有数据库信息的链

        QString dbName = dbname;
        QString usrName = usrname;
        QString fileName = db.get_dbpath(usrName, dbName);
        QFile readFile(fileName);   //读文件信息

        if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
        {
            QTextStream stream(&readFile);
            strAll = stream.readAll();
        }
        readFile.close();
        QFile writeFile(fileName);      //写新信息
        if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
            QTextStream stream(&writeFile);
            strList = strAll.split("\n");   //每行分开存
            for(int i = 0; i<strList.count();i++){
                QString strinfo = strList.at(i);
                QStringList infolist = strinfo.split("#");
                if(infolist.at(0).toLower() == dbName){
                    strinfo.replace(QString("open"), QString("lock"));
                    if(i != strList.count() -1)
                        stream<<strinfo<<endl;
                    else
                        stream<<strinfo;

                }else{
                    //若不是要操作的库
                    if(i == strList.count() -1){
                        //若是到了最后一行
                        stream<<strList.at(i);
                    }else{
                        stream<<strList.at(i)<<endl;
                    }
                }
            }
        }
            writeFile.close();
            return 1;   //返回1表示操作成功
    }
}


int rename_table(QString usrname, QString tbnewname, QString tbpastname, QString dbname){

    QString nw = tbnewname;
    QString old = tbpastname;
    QString user = usrname;
    QString dbn = dbname;
    bool isOK = variablecheck(nw);
    if(!isOK){
        //新表名不满足条件
        return 5;
    }
    //先检查库是否存在并已打开
    Database db(user,dbn);
    int ck_exists = db.check_dbexists(usrname,dbname);
    if(ck_exists==-1){
        //检查表是否存在
        table tbl(user, dbn, old);
        int ck_tblexists = tbl.tbl_exists(user,dbn,old);
        if(ck_tblexists == -1){
            //表存在，可以进行修改
            QString filename = tbl.get_path(user,dbn);
            QString strAll;
            QStringList strList;
            QFile readFile(filename);
            if(readFile.open((QIODevice::ReadOnly|QIODevice::Text))){
                QTextStream stream(&readFile);
                strAll = stream.readAll();
                strList = strAll.split("\n");
                for(int i = 0;i<strList.count();i++){
                    QString tblname = strList.at(i);
                    if(tblname == nw){
                        //新表名已存在
                        readFile.close();
                        return 3;
                    }
                }
            }
            readFile.close();
            QFile writeFile(filename);      //写新信息
            if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
                QTextStream stream(&writeFile);
                strList = strAll.split("\n");
                for(int i = 0; i<strList.count();i++){
                    QString tblname = strList.at(i);
                    if(tblname==old){
                        //进行替换
                        tblname = nw;
                        if(i != (strList.count() -1))
                            stream<<tblname<<endl;
                        else
                            stream<<tblname;
                    }else{
                        //若不是要操作的库
                        if(i == (strList.count() -1)){
                            //若是到了最后一行
                            stream<<strList.at(i);
                        }else{
                            stream<<strList.at(i)<<endl;
                        }
                    }
                }
            }
            writeFile.close();
            //重命名文件夹
            QString pastPath = QCoreApplication::applicationDirPath()+"/data/"+user+"/"+dbn+'/'+old;
            QString newPath = QCoreApplication::applicationDirPath()+"/data/"+user+"/"+dbn+'/'+nw;
            QDir dir(pastPath);
            dir.rename(pastPath,newPath);
            return -1;

        }else{
            //表不存在
            return 4;
        }
    }else if(ck_exists==-2){
        //库已存在，但未打开
        return 1;
    }else{
        //库不存在或文件打开失败
        return 2;
    }
}
int rename_db(QString usrname,QString dbnewname, QString dbpastname){

        QString old = dbpastname;
        QString nw = dbnewname;
        QString user = usrname;

        bool isOK = variablecheck(nw);
        if(!isOK){
            return -3;
        }

        //首先检查数据库是否存在
        Database db(user,old);
        int ck_exists = db.check_dbexists(user,old);
        if(ck_exists >= 0){
            //要打开的数据库不存在，返回-1
            return -1;
        }else{
            //改database.txt里的名字
            QString strAll;
            QStringList strList;    //存放所有数据库信息的链

            QString fileName = db.get_dbpath(user, old);
            QFile readFile(fileName);   //读文件信息

            if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
            {
                QTextStream stream(&readFile);
                strAll = stream.readAll();
                strList = strAll.split("\n");
                for(int i = 0;i<strList.count();i++){
                    QString dbstr = strList.at(i);
                    QStringList dbstrlist = dbstr.split("#");
                    if(dbstrlist.at(0).toLower() == nw){
                        //要替换的名字已存在
                        readFile.close();
                        return -2;
                    }
                }
            }
            readFile.close();
            QFile writeFile(fileName);      //写新信息
            if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text)){
                QTextStream stream(&writeFile);
                strList = strAll.split("\n");   //每行分开存
                for(int i = 0; i<strList.count();i++){
                    QString strinfo = strList.at(i);
                    QStringList infolist = strinfo.split("#");
                    if(infolist.at(0).toLower() == old){
                        //替换名字
                        strinfo.replace(old, nw);
                        if(i != (strList.count() -1))
                            stream<<strinfo<<endl;
                        else
                            stream<<strinfo;
                    }else{
                        //若不是要操作的库
                        if(i == (strList.count() -1)){
                            //若是到了最后一行
                            stream<<strList.at(i);
                        }else{
                            stream<<strList.at(i)<<endl;
                        }
                    }
                }
            }
            writeFile.close();

            QString sysAll;
            QStringList sysList;
            QString syspath = QCoreApplication::applicationDirPath()+"/data/sysDB.db";
            QFile sysreadFile(syspath);
            if(sysreadFile.open(QIODevice::ReadOnly|QIODevice::Text)){
                QTextStream stream(&sysreadFile);
                sysAll = stream.readAll();
            }
            sysreadFile.close();
            QFile syswriteFile(syspath);
            if(syswriteFile.open(QIODevice::WriteOnly|QIODevice::Text)){
                QTextStream stream(&syswriteFile);
                sysList = sysAll.split("\n");   //每行分开存
                for(int i = 0; i<sysList.count();i++){
                    QString strinfo = sysList.at(i);
                    QStringList infolist = strinfo.split("#");
                    if(infolist.size() == 5){   //判断是否属于一条记录，也就是至少有5个成员
                        if(infolist.at(1).toLower() == old && infolist.at(0) == user){
                            //替换名字
                            strinfo.replace(old, nw);
                            if(i != (sysList.size() -1))
                                stream<<strinfo<<endl;
                            else
                                stream<<strinfo;
                        }else{
                            //若不是要操作的库
                            if(i == (sysList.size() -1)){
                                //若是到了最后一行
                                stream<<sysList.at(i);
                            }else{
                                stream<<sysList.at(i)<<endl;
                            }
                        }
                    }
                }
            }
            syswriteFile.close();

            //重命名文件夹
            QString pastPath = QCoreApplication::applicationDirPath()+"/data/"+user+"/"+old;
            QString newPath = QCoreApplication::applicationDirPath()+"/data/"+user+"/"+nw;
            QDir dir(pastPath);
            dir.rename(pastPath,newPath);
            return 1;

        }

}

void create_(QString str){
    //qDebug() << "create" << endl;
}

void drop_(QString str){
    //qDebug() << "drop" << endl;
}

void insert_(QString str){
    //qDebug() << "insert" << endl;
}

void delete_(QString str){
    //qDebug() << "delete" << endl;
}

void alter_(QString str){
    //qDebug() << "alter" << endl;
}

void select_(QString str){
    //qDebug() << "select" << endl;
}
