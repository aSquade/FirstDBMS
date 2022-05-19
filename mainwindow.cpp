 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createwindow.h"
#include "deletewindow.h"
#include "columnaddwindow.h"
#include "columnalterwindow.h"
#include "columndeletewindow.h"
#include "datainsertwindow.h"
#include "datadeletewindow.h"
#include "user.h"
#include "string"
#include "split.h"
#include "split.cpp"
#include "sheet.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QWindow>
#include <QRegExp>
#include <QRegExpValidator>
#include "database.h"
#include "row.h"
#include "display.h"
#include <iostream>
#include <fstream>

using namespace std;
MainWindow::MainWindow(QString usrname,QString pow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("#MainWindow{border-image:url(:/pic/background.png)}");

    ui->createButton->setStyleSheet("QPushButton{image: url(:/pic/create1.png);}"
                                    "QPushButton:hover{image: url(:/pic/create.png);}");
    ui->createButton->setFlat(true);

    ui->deleteButton->setStyleSheet("QPushButton{image: url(:/pic/delete1.png);}"
                                    "QPushButton:hover{image: url(:/pic/delete.png);}");
    ui->deleteButton->setFlat(true);

    ui->addColumnButton->setStyleSheet("QPushButton{image: url(:/pic/addCol.png);}"
                                       "QPushButton:hover{image: url(:/pic/add.png);}");
    ui->addColumnButton->setFlat(true);

    ui->alterColumnBotton->setStyleSheet("QPushButton{image: url(:/pic/alterCol.png);}"
                                         "QPushButton:hover{image: url(:/pic/alter.png);}");
    ui->alterColumnBotton->setFlat(true);

    ui->deleteColumnButton->setStyleSheet("QPushButton{image: url(:/pic/delCol.png);}"
                                          "QPushButton:hover{image: url(:/pic/delete.png);}");
    ui->deleteColumnButton->setFlat(true);

    ui->insertDataButton->setStyleSheet("QPushButton{image: url(:/pic/insert1.png);}"
                                        "QPushButton:hover{image: url(:/pic/insert.png);}");
    ui->insertDataButton->setFlat(true);

    ui->deleteDataButton->setStyleSheet("QPushButton{image: url(:/pic/delData.png);}"
                                        "QPushButton:hover{image: url(:/pic/delete.png);}");
    ui->deleteDataButton->setFlat(true);

    ui->clearButton->setStyleSheet("QPushButton{image: url(:/pic/clear1.png);}"
                                   "QPushButton:hover{image: url(:/pic/clear.png);}");
    ui->clearButton->setFlat(true);

    ui->comfirmButton->setStyleSheet("QPushButton{image: url(:/pic/comfirm1.png);}"
                                     "QPushButton:hover{image: url(:/pic/comfirm.png);}");
    ui->comfirmButton->setFlat(true);
    //ui->refreshButton->setFlat(true);

    username=usrname;
    power = pow;
    this->display();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//点击 “创建” 按钮
void MainWindow::on_createButton_clicked()
{
    CreateWindow *c = new CreateWindow(username);
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//点击 “删除" 按钮
void MainWindow::on_deleteButton_clicked()
{
    DeleteWindow *d = new DeleteWindow(username);
    d->setWindowModality(Qt::ApplicationModal);
    d->show();
}

//点击 “添加表字段” 按钮
void MainWindow::on_addColumnButton_clicked()
{
    ColumnAddWindow *c = new ColumnAddWindow(username);
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//点击 “修改表字段” 按钮
void MainWindow::on_alterColumnBotton_clicked()
{
    ColumnAlterWindow *c = new ColumnAlterWindow(username);
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//点击 “删除表字段” 按钮
void MainWindow::on_deleteColumnButton_clicked()
{
    ColumnDeleteWindow *c = new ColumnDeleteWindow(username);
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//点击 “插入数据” 按钮
void MainWindow::on_insertDataButton_clicked()
{
    DataInsertWindow *d = new DataInsertWindow(username);
    d->setWindowModality(Qt::ApplicationModal);
    d->show();
}

//点击 “删除数据” 按钮
void MainWindow::on_deleteDataButton_clicked()
{
    DataDeleteWindow *d = new DataDeleteWindow();
    d->setWindowModality(Qt::ApplicationModal);
    d->show();
}




void MainWindow::on_clearButton_clicked()
{
    ui->textInput->setText("");
}


void MainWindow::on_comfirmButton_clicked()
{
    QString strtext = ui->textInput->toPlainText();//所有语句
    QStringList list = strtext.split(";");  //以分号为间隔分开每一句话

    QStringList list2;      //没啥用
    list.removeAll(QString(""));    //删除最后一个分号后提取到的空字符串..很重要！

    QString strExec = list.at(list.size()-1);//选取输入框内最新一句话即需要执行的语句
    const int acsize = list.size();     //没啥用
    //qDebug() << strExec << endl;

    strExec = strExec.simplified(); //去除首位所有空格，把中间的空格无论多少都转为1个空格
    strExec = strExec.toLower();
    QStringList strlist = strExec.split(" ");
    if(strlist.size() < 3){
        QMessageBox::information(this,"警告","输入内容过少！请重输",QMessageBox::Ok);
        for(int i =0;i<list.size()-1;i++){
            list2.append(list.at(i));
        }
        ui->textInput->clear();         //清空
        //for(int i = 0;i<acsize-1;i++){
            //ui->textInput->setText(list2.at(i)+';');
        //}

    }
    else
    {
        QString keyword = strlist[0];
        //qDebug() << keyword << endl;
        int opt1 = QString::compare(keyword, "create", Qt::CaseInsensitive);
        int opt2 = QString::compare(keyword, "drop", Qt::CaseInsensitive);  //ok
        int opt3 = QString::compare(keyword, "alter", Qt::CaseInsensitive);
        int opt4 = QString::compare(keyword, "insert", Qt::CaseInsensitive);//ok
        int opt5 = QString::compare(keyword, "delete", Qt::CaseInsensitive);//ok
        int opt6 = QString::compare(keyword, "select", Qt::CaseInsensitive);
        int opt7 = QString::compare(keyword, "rename", Qt::CaseInsensitive);//ok
        int opt8 = QString::compare(keyword, "open", Qt::CaseInsensitive);//ok
        int opt9 = QString::compare(keyword, "close", Qt::CaseInsensitive);//ok
        int opt10= QString::compare(keyword, "grant", Qt::CaseInsensitive);
        int opt11 = QString::compare(keyword, "revoke", Qt::CaseInsensitive);



        if(power ==  "admin power")//系统管理员权限
        {
            int flag=0;
            //grant all privileges to 用户名;
            if (opt10 == 0)//grant
            {
               if(strlist[1]=="all" &&strlist[2]=="privileges"&&strlist[3]=="to")
               {
                   QString user_name = strlist[4];
                   //打开user.txt写入文件
                   QString FileName = QCoreApplication::applicationDirPath();
                   QString pathName = FileName+"/data";//数据库文件夹位置
                   QString fileName= pathName+"/"+"user.txt";//记录用户信息的文件

                   QFile file(fileName);
                   file.open(QIODevice::ReadWrite|QIODevice::Text);
                   if(file.isOpen())
                   {
                       //打开成功则进行遍历查询
                       if(file.size()==0)
                       {
                           QMessageBox::information(this,"警告","文件为空！",QMessageBox::Ok);   //文件为空，值不存在
                       }
                       else
                       {
                           QStringList lines;
                           QTextStream out(&file);
                           QString info;
                           while(!out.atEnd())
                            {
                                QString info = out.readLine();
                                QStringList information=info.split(":");

                                if(user_name!=information.at(0))
                                {
                                    //把不需要修改的列信息复制到链里
                                    lines.push_back(info);
                                }
                                else
                                {
                                    //找到了需要修改的列
                                    flag=1;
                                    QString str=user_name+":"+information.at(1)+":"+"user power";//修改此列信息
                                    lines.push_back(str);
                                }
                            }

                            file.remove();
                            if(flag==0)
                            {
                                file.close();

                            }
                            else
                            {
                                file.close();
                                QFile file2(fileName);
                                if(file2.open(QIODevice::WriteOnly | QIODevice::Text))
                                {
                                    QTextStream edit(&file2);
                                    for(int i=0;i<lines.size();i++)
                                    {
                                        edit<<lines[i]<<endl;
                                    }
                                      QMessageBox::information(this,"提示","授权成功！",QMessageBox::Ok);
                                    file2.close();

                               }
                            }

                       }
                   }

               }

               else
               {
                    QMessageBox::information(this,"警告","请检查拼写是否正确！",QMessageBox::Ok);
               }










            }
            else if (opt11 == 0)//revoke
            {
                //revoke all privileges
                //from 用户名;
                   if(strlist[1]=="all" &&strlist[2]=="privileges"&&strlist[3]=="from")
                   {
                       QString user_name = strlist[4];
                       QString FileName = QCoreApplication::applicationDirPath();
                       QString pathName = FileName+"/data";//数据库文件夹位置
                       QString fileName= pathName+"/"+"user.txt";//记录用户信息的文件

                       QFile file(fileName);
                       file.open(QIODevice::ReadWrite|QIODevice::Text);
                       if(file.isOpen())
                       {
                           //打开成功则进行遍历查询
                           if(file.size()==0)
                           {
                               QMessageBox::information(this,"警告","文件为空！",QMessageBox::Ok);   //文件为空，值不存在
                           }
                           else
                           {
                               QStringList lines;
                               QTextStream out(&file);
                               QString info;
                               while(!out.atEnd())
                                {
                                    QString info = out.readLine();
                                    QStringList information=info.split(":");

                                    if(user_name!=information.at(0))
                                    {
                                        //把不需要修改的列信息复制到链里
                                        lines.push_back(info);
                                    }
                                    else
                                    {
                                        //找到了需要修改的列
                                        flag=1;
                                        QString str=user_name+":"+information.at(1)+":"+"no power";//修改此列信息
                                        lines.push_back(str);
                                    }
                                }

                                file.remove();
                                if(flag==0)
                                {
                                    file.close();
                                }
                                else
                                {
                                    file.close();
                                    QFile file2(fileName);
                                    if(file2.open(QIODevice::WriteOnly | QIODevice::Text))
                                    {
                                        QTextStream edit(&file2);
                                        for(int i=0;i<lines.size();i++)
                                        {
                                            edit<<lines[i]<<endl;
                                        }
                                        QMessageBox::information(this,"提示","回收权限成功！",QMessageBox::Ok);
                                        file2.close();

                                   }
                                }

                           }
                       }

                   }

                   else
                   {
                        QMessageBox::information(this,"警告","请检查拼写是否正确！",QMessageBox::Ok);
                   }

            }
            else
            {
                 QMessageBox::information(this,"警告","系统用户只能操作用户权限，无法操作数据库",QMessageBox::Ok);
            }
        }
        else if(power == "no power")
        {
            QMessageBox::information(this,"警告","没有操作权限，请先让系统管理员授权",QMessageBox::Ok);
        }
        else if(power == "user power")
        {
            if (opt1 == 0){
                QStringList list1 = strExec.split(" ");
                if (list1[1] == "database"){
                    if (list1.size() == 3){
                        QString s = list1[2];//读取用户输入的数据库名称

                        if(!variablecheck(s))
                        {
                            QMessageBox::question(this,
                            tr("error"),
                            tr("数据库名称格式错误！"),
                            QMessageBox::Ok | QMessageBox::Cancel,
                            QMessageBox::Ok);
                        }
                        //格式符合之后,创建数据库对象，传入用户名和库名
                        Database db(username,s);
                        int chexists = db.check_dbexists(username,s);//检查库是否已存在
                        if(chexists==-1||chexists==-2){
                            QMessageBox::information(this,"警告","此数据库已存在！",QMessageBox::Ok);
                        }else if(chexists == 3){
                            QMessageBox::information(this,"警告","文件打开失败！",QMessageBox::Ok);
                        }else{
                            //进行写入database.txt的操作
                            int chdone = db.db_write(username,s);
                            if(chdone==1){
                                //写入失败
                                QMessageBox::information(this,"警告","数据库创建失败！",QMessageBox::Ok);
                            }else if(chdone==-2){
                                QMessageBox::information(this,"警告","文件打开失败！",QMessageBox::Ok);
                            }
                            else{
                                QMessageBox::information(this,"警告","数据库创建成功！",QMessageBox::Ok);
                            }
                        }

                        //split here
                    }else{
                        QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                    }


                }else if (list1[1] == "table"){


                    int size_ = list1.size();


                    if (list1[size_-2] != "database"){
                        QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);

                    }else{

                        QString db_name = list1[size_-1];
                        QString tail = list1[size_-1] + list1[size_-2] + list1[size_-3];
                        int tail_ = tail.length() + 3;
                        strExec = strExec.left(strExec.size() - tail_);
                        list1 = strExec.split(" ");

                        //日志
                        QString dbName = db_name;
                        QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                        QString fileName =  pathName+"/logfile.log";
                        QFile file(fileName);
                        file.open(QIODevice::Append|QIODevice::Text);
                        if(file.isOpen())
                        {
                             QFileInfo info(fileName);
                             //QString str = info.birthTime().toString();
                             QString lastModified = info.lastModified().toString();
                             QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                             QTextStream out(&file);//写入
                             out << dbInfo<<endl;
                             file.close();
                        }
                        else
                        {
                            //打印信息：文件无法打开
                            file.close();
                        }
                        QString col_name = "";
                        QString col_type = "";
                        QString check_name = "";
                        QString check = "";

                        if (list1.size() < 4){
                            QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                        }else{
                            QStringList list2 = list1[2].split("(");
                            QString tbl_name = list2[0].simplified();

                            qDebug() << tbl_name << endl;

                            QString str1 = strExec.right(strExec.size() - 14 - tbl_name.size());
                            QString str2 = str1.left(str1.size() - 1).simplified();

                            QStringList list3 = str2.split(",");
                            for (int var = 0; var < list3.size(); ++var) {
                                list3[var] = list3[var].simplified();

                                QStringList list4 = list3[var].split(" ");

                                if (list4.size() < 2){
                                    QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                                    break;
                                }else{

                                    col_name = list4[0];
                                    col_type = list4[1];


                                    if (col_type != "integer" && col_type != "bool" && col_type != "double" && col_type != "varchar" && col_type != "datetime"){
                                        QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                                        break;
                                    }

                                    if (list4.size() == 3){
                                        if (list4[2] == "unique"){
                                            check_name = "unique";
                                        }else{
                                            if (list4[2].split("(")[0] == "check"){
                                                check_name = "check";
                                                check = list4[2].split("(")[1].left(list4[2].split("(")[1].size() - 1);
                                            }else{
                                                QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                                                break;
                                            }
                                        }
                                    }else if (list4.size() == 2){
                                    }
                                    else if (list4.size() == 4){
                                        QString ap1 = list4[2]+list4[3];
                                        if (ap1 == "primarykey" || ap1 == "notnull"){
                                            check_name = list4[2]+" "+list4[3];
                                        }else{
                                            QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                                            break;
                                        }
                                    }else if (list4.size() == 6){
                                        QString ap2 = list4[2]+list4[3];
                                        if (ap2 == "foreignkey"){
                                            check_name = "foreign key";
                                            check = list4[4]+" "+list4[5];
                                        }else{
                                            QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                                            break;
                                        }
                                    }else{
                                        QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                                        break;
                                    }
                                }

                                //add here

                                if(!variablecheck(tbl_name))
                                {
                                    QMessageBox::question(this,
                                    tr("error"),
                                    tr("表名称格式错误！"),
                                    QMessageBox::Ok | QMessageBox::Cancel,
                                    QMessageBox::Ok);
                                }
                                table tbl(username, db_name, tbl_name); //长度符合之后,创建表对象，传入用户名、库名和表名
                                int db_exists = tbl.db_exists(username,db_name);//检查库是否已存在
                                if(db_exists!=-1)
                                {
                                    QMessageBox::information(this,"警告","此数据库不存在！请先创建数据库。",QMessageBox::Ok);
                                }
                                else
                                {
                                    int tbl_exists = tbl.tbl_exists(username,db_name,tbl_name);//检查表是否已存在
                                    if(tbl_exists==-1)
                                    {
                                        QMessageBox::information(this,"警告","此表已存在！",QMessageBox::Ok);
                                    }
                                    else
                                    {
                                        //进行写入table.txt的操作
                                        int chdone = tbl.table_in(username,db_name,tbl_name,col_name,col_type,check_name,check);
                                        if(chdone==-1)
                                        {
                                            //写入失败
                                            QMessageBox::information(this,"警告","表创建失败！",QMessageBox::Ok);
                                        }
                                        else
                                        {
                                            QMessageBox::information(this,"警告","表创建成功！",QMessageBox::Ok);
                                        }
                                   }

                                }
                            }

                            qDebug() << str2 << endl;
                            qDebug() << col_name << endl;
                            qDebug() << col_type << endl;
                            qDebug() << check_name << endl;
                            qDebug() << check << endl;
                            qDebug() << tail << endl;

                        }
                    }

                }else if (list1[1] == "index"){

                    int size_ = list1.size();
                    if (list1[size_-2] != "database" || size_<8){
                        QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                    }else{

                        QString dbName = list1[size_-1];
                        QString tail = list1[size_-1] + list1[size_-2] + list1[size_-3];
                        int tail_ = tail.length() + 3;
                        strExec = strExec.left(strExec.size() - tail_);
                        list1 = strExec.split(" ");


                        QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                        QString fileName =  pathName+"/logfile.log";
                        QFile file(fileName);
                        file.open(QIODevice::Append|QIODevice::Text);
                        if(file.isOpen())
                        {
                             QFileInfo info(fileName);
                             //QString str = info.birthTime().toString();
                             QString lastModified = info.lastModified().toString();
                             QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                             QTextStream out(&file);//写入
                             out << dbInfo<<endl;
                             file.close();
                        }
                        else
                        {
                            //打印信息：文件无法打开
                            file.close();
                        }
                        if (list1.size() >= 5 && list1[3] == "on"){
                            QString idxName = list1[2];
                            QStringList list5 = list1[4].split("(");
                            QString tblName = list5[0];
                            QString colName = list5[1].left(list5[1].size() - 1);

                            table tbl(username, dbName, tblName); //长度符合之后,创建表对象，传入用户名、库名和表名
                            int db_exists = tbl.db_exists(username,dbName);//检查库是否已存在
                            if(db_exists!=-1)
                            {
                                QMessageBox::information(this,"警告","此数据库不存在！请先创建数据库。",QMessageBox::Ok);
                            }
                            else
                            {
                                int tbl_exists = tbl.tbl_exists(username,dbName,tblName);//检查表是否已存在
                                if(tbl_exists==1)
                                {
                                    QMessageBox::information(this,"警告","此表不存在！请先创建表。",QMessageBox::Ok);
                                }
                                else
                                {
                                    QString FileName = QCoreApplication::applicationDirPath();
                                    QString pathName = FileName+"/data/"+username+"/"+dbName+"/"+tblName+"/"+tblName+".tid";//用户文件位置

                                    QFile file(pathName);

                                    QDir dir;

                                    file.open(QIODevice::Append|QIODevice::Text);

                                    if(file.isOpen()){
                                         QFileInfo info(pathName);

                                         QString dbInfo = idxName+"#"+tblName+"#"+colName;

                                         QTextStream out(&file);//写入

                                         out << dbInfo<<endl;

                                         file.close();
                                         QMessageBox::information(this,"警告","索引创建成功！",QMessageBox::Ok);
                                    }
                                }
                            }


                        }else{
                            QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                        }
                    }
                //
                }else{
                    QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                }

            }
            else if (opt2 == 0)//drop
            {
                QString type = strlist[1];
                if(type == "database")//删除库(首先要open库才能删除，原因暂时不明）
                {
                    QString s =  strlist[2];
                    Database db(username,s);
                    int chexists = db.check_dbexists(username,s);//检查库是否已存在

                    if(chexists==-1)
                    {
                        //说明数据库存在，可以删除
                        QString dbName = s;
                        QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                        QString fileName =  pathName+"/logfile.log";
                        QFile file(fileName);
                        file.open(QIODevice::Append|QIODevice::Text);
                        if(file.isOpen())
                        {
                             QFileInfo info(fileName);
                             //QString str = info.birthTime().toString();
                             QString lastModified = info.lastModified().toString();
                             QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                             QTextStream out(&file);//写入
                             out << dbInfo<<endl;
                             file.close();
                        }
                        else
                        {
                            //打印信息：文件无法打开
                            file.close();
                        }
                        db.db_out(username,s);
                        QMessageBox::information(this,"提示","删除成功！",QMessageBox::Ok);
                    }
                    else
                    {
                        QMessageBox::information(this,"提示","该数据库不存在！",QMessageBox::Ok);
                    }
                    ui->textInput->clear();
                }
                else if (type == "table" && strlist[3]== "in" && strlist[4]=="database")//删除表
                {
                    QString s =  strlist[2];//读取用户输入的表名称
                    QString d =  strlist[5];//读取用户打开的的数据库名称

                    QString dbName = d;
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName1 =  pathName+"/logfile.log";
                    QFile file(fileName1);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName1);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                         QTextStream out(&file);//写入
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //打印信息：文件无法打开
                        file.close();
                    }
                    QString FileName = QCoreApplication::applicationDirPath();
                    QString strPath = FileName+"/data/"+username+"/"+d;
                    QString fileName = strPath+"table.txt";

                    table tbl(username,d,s);
                    int tbl_exists = tbl.tbl_exists(username,d,s);//检查表是否已存在
                    if(tbl_exists==-1)
                    {
                        //说明表存在，可以删除
                        tbl.table_out(username,d,s);
                        QMessageBox::information(this,"提示","删除成功！",QMessageBox::Ok);
                    }
                    else
                    {
                        QMessageBox::information(this,"提示","该表不存在！",QMessageBox::Ok);
                    }
                    ui->textInput->clear();


                }
                //drop index 索引名 on 表名 in database 数据库名
                              else if(type == "index"&&strlist[3] =="on"&&strlist[5]=="in"&&strlist[6]=="database" )
                              {
                                  QString s =  strlist[4];//读取用户输入的表名称
                                  QString d =  strlist[7];//读取用户打开的的数据库名称
                                  QString x =  strlist[2];//索引名
                                  //日志
                                  QString dbName = d;
                                  QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                                  QString fileName =  pathName+"/logfile.log";
                                  QFile file(fileName);
                                  file.open(QIODevice::Append|QIODevice::Text);
                                  if(file.isOpen())
                                  {
                                       QFileInfo info(fileName);
                                       //QString str = info.birthTime().toString();
                                       QString lastModified = info.lastModified().toString();
                                       QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                                       QTextStream out(&file);//写入
                                       out << dbInfo<<endl;
                                       file.close();
                                  }
                                  else
                                  {
                                      //打印信息：文件无法打开
                                      file.close();
                                  }


                                  QString FileName = QCoreApplication::applicationDirPath();
                                  QString pathName1 = FileName+"/data/"+username+"/"+dbName+"/"+s;//用户文件夹位置
                                  QString fileName1= pathName1+"/"+s+".tid";//存储字段相关信息
                                  QFile inputfile(fileName1);
                                  QStringList lines;

                                  inputfile.open(QIODevice::ReadWrite|QIODevice::Text);
                                  if(inputfile.isOpen())
                                  {
                                      QTextStream out(&inputfile);
                                      QString data;
                                       while(!out.atEnd())
                                       {
                                           data = out.readLine();
                                           QStringList info=data.split("#");
                                           if(x!=info.at(0))
                                           {
                                               //把不是该表的表信息复制到链里
                                              lines.push_back(data);
                                           }
                                      }
                                       inputfile.remove();
                                       QFile outputfile(fileName1);
                                       if(outputfile.open(QIODevice::WriteOnly | QIODevice::Text))
                                       {
                                               QTextStream edit(&outputfile);
                                               for(int i=0;i<lines.size();i++)
                                               {
                                                   edit<<lines[i]<<endl;
                                               }
                                               outputfile.close();
                                               QMessageBox::information(this,"提示","索引删除成功！",QMessageBox::Ok);
                                       }


                                  }


                              }
                              else//拼写有误或格式有误
                              {
                                  QMessageBox::information(this,"警告","请检查拼写是否正确！",QMessageBox::Ok);
                                  ui->textInput->clear();
                              }


            }
            else if (opt3 == 0)
            {
                QStringList list_0 = strExec.split(" ");
                if (list_0[list_0.size() - 2] == "database" && list_0[list_0.size() - 3] == "in"){

                    QString dbName = list_0[list_0.size() - 1];
                    QString tail = list_0[list_0.size() - 3]+list_0[list_0.size() - 2]+list_0[list_0.size() - 1];
                    strExec = strExec.left(strExec.length() - tail.length() - 3);

                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                         QTextStream out(&file);//写入
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //打印信息：文件无法打开
                        file.close();
                    }
                    qDebug() << tail << endl;
                    qDebug() << strExec << endl;

                    QStringList list_1 = strExec.split(" ");
                    if (list_1.size() < 6 || list_1[1] != "table"){
                        QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                    }else if(list_1.size() == 6){
                        QString tblName = list_1[2];

                        if (list_1[3] == "drop" && list_1[4] == "column"){
                            QString colName = list_1[5];
                            //add here
                            //qDebug() << "drop" + col_name << endl;
                            QString FileName = QCoreApplication::applicationDirPath();
                            QString pathName = FileName+"/data/"+username+"/"+dbName+"/"+tblName ;//表文件夹位置
                            QString fileName1 = pathName+"/"+tblName+".tdf";
                            QString fileName2 = pathName+"/"+tblName+".tic";
                            QString delPath = QString(pathName);

                            QFile inputfile1(fileName1);
                            QFile inputfile2(fileName2);

                            QStringList lines;

                            inputfile1.open(QIODevice::ReadWrite|QIODevice::Text);
                            inputfile2.open(QIODevice::ReadWrite|QIODevice::Text);

                            if(inputfile1.isOpen()&&inputfile2.isOpen()){
                                QTextStream out1(&inputfile1);
                                QTextStream out2(&inputfile2);

                                QString data1;
                                QString data2;

                                 while(!out1.atEnd()){
                                     data1 = out1.readLine();
                                     QStringList data_=data1.split("#");
                                     if(colName!=data_.at(0)){
                                         //把不是该表的表信息复制到链里
                                        lines.push_back(data1);
                                     }
                                }

                                 while(!out2.atEnd()){
                                     data2 = out2.readLine();
                                     QStringList data_=data2.split("#");
                                     if(colName!=data_.at(0)){
                                         //把不是该表的表信息复制到链里
                                        lines.push_back(data2);
                                     }
                                }

                                 inputfile1.remove();
                                 inputfile2.remove();

                                 QFile outputfile1(fileName1);
                                 QFile outputfile2(fileName2);

                                 if(outputfile1.open(QIODevice::WriteOnly | QIODevice::Text))
                                 {
                                         QTextStream edit(&outputfile1);
                                         for(int i=0;i<lines.size();i++){
                                         edit<<lines[i]<<endl;
                                 }
                                         outputfile1.close();
                            }
                                 if(outputfile2.open(QIODevice::WriteOnly | QIODevice::Text))
                                 {
                                         QTextStream edit(&outputfile2);
                                         for(int i=0;i<lines.size();i++){
                                         edit<<lines[i]<<endl;
                                 }
                                         outputfile2.close();
                            }

                                 QDir qDir(delPath);

                            }
                            QMessageBox::information(this,"警告","删除成功！",QMessageBox::Ok);

                        }else{
                            QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                        }

                    }else if(list_1.size() == 7){
                        QString tblName = list_1[2];
                        QString colName = list_1[5];
                        QString colType = list_1[6];

                        if (list_1[4] == "column"){
                            if (list_1[3] == "add"){
                                table tbl(username, dbName, tblName); //长度符合之后,创建表对象，传入用户名、库名和表名
                                int db_exists = tbl.db_exists(username,dbName);//检查库是否已存在
                                if(db_exists!=-1)
                                {
                                    QMessageBox::information(this,"警告","此数据库不存在！请先创建数据库。",QMessageBox::Ok);
                                }
                                else
                                {
                                    int tbl_exists = tbl.tbl_exists(username,dbName,tblName);//检查表是否已存在
                                    if(tbl_exists==1)
                                    {
                                        QMessageBox::information(this,"警告","此表不存在！请先创建表。",QMessageBox::Ok);
                                    }
                                    else
                                    {
                                        QString FileName = QCoreApplication::applicationDirPath();
                                        QString pathName = FileName+"/data/"+username+"/"+dbName+"/"+tblName+"/"+tblName+".tdf";//用户文件位置

                                        QFile file(pathName);

                                        QDir dir;

                                        file.open(QIODevice::Append|QIODevice::Text);

                                        if(file.isOpen()){
                                             QFileInfo info(pathName);

                                             QString dbInfo = colName + "#" + colType;

                                             QTextStream out(&file);//写入

                                             out << dbInfo<<endl;

                                             file.close();
                                             QMessageBox::information(this,"警告","添加成功！",QMessageBox::Ok);
                                        }
                                    }
                                }
                                //qDebug() << "add" + col_name << endl;


                            }else if (list_1[3] == "modify"){
                                QString FileName = QCoreApplication::applicationDirPath();
                                QString pathName = FileName+"/data/"+username+"/"+dbName+"/"+tblName ;//表文件夹位置
                                QString fileName = pathName+"/"+tblName+".tdf";
                                QString delPath = QString(pathName);

                                QFile inputfile(fileName);

                                QStringList lines;

                                inputfile.open(QIODevice::ReadWrite|QIODevice::Text);

                                if(inputfile.isOpen()){
                                    QTextStream out(&inputfile);

                                    QString data;

                                     while(!out.atEnd()){
                                         data = out.readLine();
                                         QStringList data_=data.split("#");
                                         if(colName!=data_.at(0)){
                                             //把不是该表的表信息复制到链里
                                            lines.push_back(data);
                                         }
                                    }

                                     inputfile.remove();

                                     QFile outputfile(fileName);

                                     if(outputfile.open(QIODevice::WriteOnly | QIODevice::Text))
                                     {
                                             QTextStream edit(&outputfile);
                                             for(int i=0;i<lines.size();i++){
                                             edit<<lines[i]<<endl;
                                     }
                                             outputfile.close();
                                }

                                     QDir qDir(delPath);

                                }

                                table tbl(username, dbName, tblName); //长度符合之后,创建表对象，传入用户名、库名和表名
                                int db_exists = tbl.db_exists(username,dbName);//检查库是否已存在
                                if(db_exists!=-1)
                                {
                                    QMessageBox::information(this,"警告","此数据库不存在！请先创建数据库。",QMessageBox::Ok);
                                }
                                else
                                {
                                    int tbl_exists = tbl.tbl_exists(username,dbName,tblName);//检查表是否已存在
                                    if(tbl_exists==1)
                                    {
                                        QMessageBox::information(this,"警告","此表不存在！请先创建表。",QMessageBox::Ok);
                                    }
                                    else
                                    {
                                        QString FileName = QCoreApplication::applicationDirPath();
                                        QString pathName = FileName+"/data/"+username+"/"+dbName+"/"+tblName+"/"+tblName+".tdf";//用户文件位置

                                        QFile file(pathName);

                                        QDir dir;

                                        file.open(QIODevice::Append|QIODevice::Text);

                                        if(file.isOpen()){
                                             QFileInfo info(pathName);

                                             QString dbInfo = colName + "#" + colType;

                                             QTextStream out(&file);//写入

                                             out << dbInfo<<endl;

                                             file.close();
                                             QMessageBox::information(this,"警告","修改成功！",QMessageBox::Ok);
                                        }
                                    }
                                }




                            }else{
                                QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                            }
                        }else{
                            QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                        }

                    }else{
                        QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                    }
                }else{
                    QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                }
            }
            //insert
            else if (opt4 == 0)//insert into 表名【(字段名,字段名...)】values(值,值,值...) in database 库名;（注意，作为值的字符串都要加单引号）//这是在一行里的
            {
                //insert into 表名 (列名) values (记录值) in database 库名;//指定列名
                if(strlist[1] == "into" &&  strlist[4] == "values"&& strlist[6] == "in"&& strlist[7] == "database")
                {

                    QString tbl_name =  strlist[2];//读取用户输入的表名称
                    QString col_name  = strlist[3];//读取用户输入的列名称
                    col_name.replace(")","");//去掉括号
                    col_name.replace("(","");
                    QStringList col_list = col_name.split(",");//按逗号分隔
                    QString data_item  =  strlist[5];//读取用户输入的值
                    data_item.replace(")","");//去掉括号
                    data_item.replace("(","");
                    data_item.replace("'","");//去掉单引号
                    QStringList data_list = data_item.split(",");//按逗号分隔
                    QString db_name  =  strlist[8];//读取用户打开的的数据库名称

                    QString dbName = db_name;
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                         QTextStream out(&file);//写入
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //打印信息：文件无法打开
                        file.close();
                    }
                    if(data_list.length()==col_list.length()) //检查数据与字段个数是否匹配
                    {
                            row rw(username, db_name, tbl_name,col_list,data_list); //长度符合之后,创建字段对象，传入用户名、库名和表名
                            int db_exists = rw.db_exists(username,db_name);//检查库是否已存在
                            if(db_exists!=-1)
                            {
                                QMessageBox::information(this,"警告","此数据库不存在！请先创建数据库。",QMessageBox::Ok);
                            }
                            else
                            {
                                    int tbl_exists = rw.tbl_exists(username,db_name,tbl_name);//检查表是否已存在
                                    if(tbl_exists==-1)
                                    {
                                           int col_exists = rw.col_exists(username,db_name,tbl_name,col_list);//检查列是否已存在
                                           {
                                                 if(col_exists!=-1)
                                                 {
                                                      QMessageBox::information(this,"警告","此列不存在！请先创建列。",QMessageBox::Ok);
                                                 }
                                                 else  //进行写入的操作
                                                 {
                                                     int chdone = rw.row_in(username,db_name,tbl_name,col_list,data_list);
                                                     if(chdone==-1)
                                                     {
                                                         //写入失败
                                                         QMessageBox::information(this,"警告","插入数据失败！",QMessageBox::Ok);
                                                     }
                                                     else
                                                     {
                                                         QMessageBox::information(this,"提示","插入数据成功！",QMessageBox::Ok);
                                                     }
                                                 }
                                           }
                                    }
                                    else
                                    {
                                         QMessageBox::information(this,"警告","此表不存在！",QMessageBox::Ok);
                                    }
                           }

                       }

                   else
                {
                    QMessageBox::information(this,"警告","字段与数据个数不匹配！",QMessageBox::Ok);

                }
                ui->textInput->clear();
             }
                //insert into 表名 values (记录值) in database 库名;//不指定列名，全部插入
                else if(strlist[1] == "into" &&  strlist[3] == "values"&& strlist[5] == "in"&& strlist[6] == "database")
                {
                    QString tbl_name =  strlist[2];//读取用户输入的表名称
                    QString data_item  =  strlist[4];//读取用户输入的值
                    data_item.replace(")","");//去掉左括号
                    data_item.replace("(","");//去掉右括号
                    data_item.replace("'","");//去掉单引号
                    QStringList data_list = data_item.split(",");//按逗号分隔
                    QString db_name  =  strlist[7];//读取用户打开的的数据库名称
                    QStringList col_list;

                    QString dbName = db_name;
                    QString pathName1 = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName1=  pathName1+"/logfile.log";
                    QFile file1(fileName1);
                    file1.open(QIODevice::Append|QIODevice::Text);
                    if(file1.isOpen())
                    {
                         QFileInfo info(fileName1);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName1+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                         QTextStream out(&file1);//写入
                         out << dbInfo<<endl;
                         file1.close();
                    }
                    else
                    {
                        //打印信息：文件无法打开
                        file1.close();
                    }
                    //读取文件行数
                    QString FileName = QCoreApplication::applicationDirPath();
                    QString pathName = FileName+"/data/"+username+"/"+db_name+"/"+tbl_name;//用户文件夹位置
                    QString fileName= pathName+"/"+tbl_name+".tdf";//存储记录相关信息
                    QFile file(fileName);
                    int num = 0;
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                          QMessageBox::information(this,"警告","文件打开失败",QMessageBox::Ok);
                    }
                    QTextStream in(&file);
                    while (!in.atEnd())
                    {
                          QString line = in.readLine();
                          QStringList oneline = line.split('#');
                          col_list.append(oneline[0]);
                          num++;
                    }
                    if(data_list.length()==num) //检查数据与字段个数是否匹配
                    {

                                row rw(username, db_name, tbl_name,col_list,data_list); //长度符合之后,创建字段对象，传入用户名、库名和表名
                                int db_exists = rw.db_exists(username,db_name);//检查库是否已存在
                                if(db_exists!=-1)
                                {
                                    QMessageBox::information(this,"警告","此数据库不存在！请先创建数据库。",QMessageBox::Ok);
                                }
                                else
                                {
                                        int tbl_exists = rw.tbl_exists(username,db_name,tbl_name);//检查表是否已存在
                                        if(tbl_exists==-1)
                                        {
                                               int col_exists = rw.col_exists(username,db_name,tbl_name,col_list);//检查列是否已存在
                                               {
                                                     if(col_exists!=-1)
                                                     {
                                                          QMessageBox::information(this,"警告","此列不存在！请先创建列。",QMessageBox::Ok);
                                                     }
                                                     else  //进行写入的操作
                                                     {
                                                         int chdone = rw.row_in(username,db_name,tbl_name,col_list,data_list);
                                                         if(chdone==-1)
                                                         {
                                                             //写入失败
                                                             QMessageBox::information(this,"警告","插入数据失败！",QMessageBox::Ok);
                                                         }
                                                         else
                                                         {
                                                             QMessageBox::information(this,"提示","插入数据成功！",QMessageBox::Ok);
                                                         }
                                                     }
                                               }
                                        }
                                        else
                                        {
                                             QMessageBox::information(this,"警告","此表不存在！",QMessageBox::Ok);
                                        }
                               }

                    }
                    else
                   {
                                QMessageBox::information(this,"警告","字段与数据个数不匹配！",QMessageBox::Ok);
                   }
                   ui->textInput->clear();

            }
                 ui->textInput->clear();

    }
            else if (opt5 == 0)//delete
            {
                //delete from 表名 where 列名 = 值 in database 库名；
                if(strlist[1] == "from" && strlist[3]=="where" && strlist[5]=="="&&strlist[7]=="in"&&strlist[8]=="database")
                {
                    QString tblName = strlist[2];//表名
                    QString colName =  strlist[4];//列名
                    QString dataItem =  strlist[6];//'值'
                    dataItem.replace("'","");//去掉单引号
                    QString dbName = strlist[9];//数据库名
                    QStringList col_name;
                    col_name.append(colName);
                    QStringList data_item;
                    data_item.append(dataItem);


                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                         QTextStream out(&file);//写入
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //打印信息：文件无法打开
                        file.close();
                    }
                    row rw(username,dbName,tblName,col_name,data_item);
                    int tbl_exists = rw.tbl_exists(username,dbName,tblName);//检查表是否已存在
                    if(tbl_exists==-1) //说明表存在
                    {

                        int col_exists = rw.col_exists(username,dbName,tblName,col_name);//检查表是否已存在
                        if(col_exists==-1) //说明字段存在，可以删除
                        {
                             int row_exists = rw.row_exists(username,dbName,tblName,col_name,data_item);//检查值是否已存在
                             if(row_exists==-1)//值存在，可删除
                            {
                                rw.row_out(username,dbName,tblName,col_name,data_item);
                                QMessageBox::information(this,"提示","删除成功！",QMessageBox::Ok);
                            }
                            else
                             {
                                   QMessageBox::information(this,"提示","没有符合条件的值！",QMessageBox::Ok);
                             }

                        }
                        else
                        {
                            QMessageBox::information(this,"提示","该字段不存在！",QMessageBox::Ok);
                        }

                    }
                    else
                    {
                        QMessageBox::information(this,"提示","该表不存在！",QMessageBox::Ok);
                    }


                }
                ui->textInput->clear();


            }
            else if (opt6 == 0)
            {
                Sheet t = select_(strExec,username);
                ui->tableWidget->clear();
                ui->tableWidget->setColumnCount(t.getHead().size());//设置列数
                ui->tableWidget->setRowCount(t.getData().size());//设置行数
                for(int i = 0;i<t.getData().size();i++){
                    for(int j = 0;j<t.getHead().size();j++){
                        //表头
                        ui->tableWidget->setHorizontalHeaderItem(
                                    j,new QTableWidgetItem(
                                        t.getHead()[j].get_name()));
                        if(t.getData()[i][j] ==NULL){
                            ui->tableWidget->setItem(i,j,new QTableWidgetItem(""));
                        }else{
                            ui->tableWidget->setItem(i,j,new QTableWidgetItem(t.getData()[i][j]));
                        }
                    }
                }
                ui->textInput->clear();
            }
            else if(opt7 == 0)
            {
                //rename database 新名 to 旧名;
                //rename table 新名 to 旧名 in database 库名;
                QString type = strlist[1];
                if(type == "database" && strlist[3]=="to")
                {
                    Database db(username,strlist[4]);
                    QString dbName = strlist[4];
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                         QTextStream out(&file);//写入
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //打印信息：文件无法打开
                        file.close();
                    }
                    int op = db.rename_database(username, strlist[2], strlist[4]);
                    if(op==1){
                        QMessageBox::information(this,"提示","修改成功！",QMessageBox::Ok);
                    }
                    if(op==-1){
                        QMessageBox::information(this,"警告","库不存在！",QMessageBox::Ok);
                    }
                    if(op==-2){
                        QMessageBox::information(this,"警告","新库名早已存在！",QMessageBox::Ok);
                    }
                    if(op == -3){
                        QMessageBox::information(this,"警告","新库名命名不规范！",QMessageBox::Ok);
                    }
                }else if(type == "table" && strlist[6] == "database"&&strlist[5]=="in"&&strlist[3]=="to"){
                    table tbl(username,strlist[7],strlist[4]);
                    QString dbName = strlist[7];
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                         QTextStream out(&file);//写入
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //打印信息：文件无法打开
                        file.close();
                    }
                    int op = tbl.rename_tbl(username, strlist[2], strlist[4], strlist[7]);
                    if(op == 1){
                        QMessageBox::information(this,"警告","该数据库未打开！",QMessageBox::Ok);
                    }else if(op ==2){
                        QMessageBox::information(this,"警告","数据库不存在或文件打开失败！",QMessageBox::Ok);
                    }else if(op == 3){
                        QMessageBox::information(this,"警告","新表名在数据库里已存在！",QMessageBox::Ok);
                    }else if(op == 4){
                        QMessageBox::information(this,"警告","表不存在！",QMessageBox::Ok);
                    }else if(op == 5){
                        QMessageBox::information(this,"警告","新表名命名不规范！",QMessageBox::Ok);
                    }else if(op == 6){
                        QMessageBox::information(this,"警告","表内文件不存在或打开失败！",QMessageBox::Ok);
                    }
                    else{
                        //修改成功
                        QMessageBox::information(this,"提示","修改成功！",QMessageBox::Ok);
                    }
                }else{
                    QMessageBox::information(this,"警告","请检查拼写是否正确！",QMessageBox::Ok);
                }
                ui->textInput->clear();
            }
            else if(opt8 == 0)
            {
                //strlist的组成成分为3个单词： open、database、数据库名
                //故仅提取最后一个数据库名即可传入函数即可
                //先判断database这个单词拼对没有
                //只允许一个用户同一时间打开一个数据库
                QString letter = strlist[1];
                if(letter == "database"){
                    QString dbname = strlist[2];    //这个数据库名记得传进各个函数里
                    QString dbName = dbname;
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                         QTextStream out(&file);//写入
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //打印信息：文件无法打开
                        file.close();
                    }
                    qDebug() << dbname << endl;
                    Database db(username,dbname);
                    int op = db.open_database(dbname,username);
                    if(op == -1){
                        QMessageBox::information(this,"警告","无效数据库名！",QMessageBox::Ok);
                    }else if(op == 1){
                        QMessageBox::information(this,"提示","数据库打开成功！",QMessageBox::Ok);
                    }else if(op == -4){
                        QMessageBox::information(this,"提示","有另外的库已打开！",QMessageBox::Ok);
                    }
                }else{
                    QMessageBox::information(this,"警告","请检查拼写是否正确！",QMessageBox::Ok);
                }
                ui->textInput->clear();         //清空
            }
            else if(opt9 == 0){
                QString letter = strlist[1];
                if(letter == "database"){
                    QString dbname = strlist[2];
                    QString dbName = dbname;
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"日志";//#作为分隔符
                         QTextStream out(&file);//写入
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //打印信息：文件无法打开
                        file.close();
                    }
                    qDebug() << dbname << endl;
                    Database db(username,dbname);
                    int op = db.close_database(dbname,username);
                    if(op == -1){
                        QMessageBox::information(this,"警告","无效数据库名！",QMessageBox::Ok);
                    }else if(op == 1){
                        QMessageBox::information(this,"提示","数据库关闭成功！",QMessageBox::Ok);
                    }
                }else{
                    QMessageBox::information(this,"警告","请检查拼写是否正确！",QMessageBox::Ok);
                }
                ui->textInput->clear();         //清空
            }
            else
            {
                QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);
                ui->textInput->clear();         //清空
            }

        }
        else
        {
             qDebug() << "power fail" << endl;
        }
      }


}

//展示该用户下所有的数据库和数据库所包含的表
void MainWindow::display()
{
    ui->fileDisplay->setFont(QFont("Timers", 16, QFont::Bold));
    Display *d = new Display(username);
    ui->fileDisplay->setText(d->getText());
    ui->fileDisplay->setEnabled(false);
}

void MainWindow::on_refreshButton_clicked()
{
    this->display();
}

