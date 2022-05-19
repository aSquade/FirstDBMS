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

QString Database::get_dbpath(QString usrname,QString dbname){
    QString dbName = dbname;
    QString ndbName = dbName.toLower();
    QString usrName = usrname;
    QString FileName = QCoreApplication::applicationDirPath();
    QString pathName = FileName+"/data/"+usrName;//用户文件夹位置
    QString fileName = pathName+"/"+"database.txt";
    return fileName;
}
bool Database::variablecheck(QString str){
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
int Database::open_database(QString dbname,QString usrname){
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
int Database::close_database(QString dbname,QString usrname){
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
int Database::rename_database(QString usrname, QString dbnewname, QString dbpastname){
    QString old = dbpastname;
    QString nw = dbnewname;
    QString user = usrname;
    Database db(user,old);
    bool isOK = db.variablecheck(nw);
    if(!isOK){
        return -3;
    }
    //首先检查数据库是否存在
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
    QString usrName = usrname;
    QString dbName = dbname;
    QString fileName = get_dbpath(usrname, dbname);
    QFile file(fileName);
    QFile sysdb(QCoreApplication::applicationDirPath()+"/data/sysDB.db");
    QDir dir;
    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+usrName;
    dir.mkdir(pathName+"/"+dbName);//创建该数据库所属文件夹
    file.open(QIODevice::Append|QIODevice::Text);
    sysdb.open(QIODevice::Append|QIODevice::Text);
    if(file.isOpen()&&sysdb.isOpen()){
         QFileInfo info(fileName);
         QString str = info.birthTime().toString();
         QString dbInfo = dbname+"#"+ pathName+"#"+str+"#"+"用户数据库"+'#'+"lock";//#作为分隔符
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
    QString ndbName = dbName.toLower();
    QString usrName = usrname;
    QString fileName = get_dbpath(usrName, dbName);
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
                 if(ndbName==dbData.at(0).toLower()){
                     //该数据库已存在
                     if(dbData.contains("open")){
                         //已打开
                         file.close();
                         return -1;
                     }else{
                         //未打开
                         file.close();
                         return -2;
                     }

                 }
             }
             file.close();
             return 1;//该数据库不存在
        }
    }
    return 3;
}

//检查数据库是否已打开
int Database::check_dbopen(QString usrname,QString dbname){
    int ckex = check_dbexists(usrname, dbname);
    if(ckex == -1){
        //数据库存在，且已打开了
        return 0;
    }else if(ckex == -2){
        //数据库存在，但未打开
        return -1;
    }else if(ckex ==0||ckex == 1){
        //数据库不存在
        return 1;
    }else{
        //文件打开失败
        return 2;
    }

}

 //数据库删除
void Database::db_out(QString usrname,QString dbname){
    QString userName = usrname;
    QString dbName = dbname;
    QString ndbName = dbName.toLower();
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
             if(ndbName!=dbData.at(0).toLower()){
                 //把不是该数据库的数据库信息复制到链里
                lines.push_back(data);
             }
        }
         while(!sysdb.atEnd()){
             sysdata = sysdb.readLine();
             QStringList sysdbData=sysdata.split("#");
             if(ndbName!=sysdbData.at(1).toLower()){
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


