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
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QWindow>
#include <QRegExp>
#include <QRegExpValidator>
#include "database.h"
#include "row.h"

#include <iostream>
#include <fstream>

using namespace std;
MainWindow::MainWindow(QString usrname,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    username=usrname;
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
    qDebug() << strExec << endl;

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
    else{
        QString keyword = strlist[0];
        //qDebug() << keyword << endl;

        int opt1 = QString::compare(keyword, "create", Qt::CaseInsensitive);
        int opt2 = QString::compare(keyword, "drop", Qt::CaseInsensitive);
        int opt3 = QString::compare(keyword, "alter", Qt::CaseInsensitive);
        int opt4 = QString::compare(keyword, "insert", Qt::CaseInsensitive);
        int opt5 = QString::compare(keyword, "delete", Qt::CaseInsensitive);
        int opt6 = QString::compare(keyword, "select", Qt::CaseInsensitive);
        int opt7 = QString::compare(keyword, "rename", Qt::CaseInsensitive);
        int opt8 = QString::compare(keyword, "open", Qt::CaseInsensitive);
        int opt9 = QString::compare(keyword, "close", Qt::CaseInsensitive);

        if (opt1 == 0){
            create_(strExec);
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
            //drop index 索引名 on 表名 in 数据库名
            else if(type == "index")
            {
                QString s =  strlist[4];//读取用户输入的表名称
                QString d =  strlist[6];//读取用户打开的的数据库名称
            }
            else//拼写有误或格式有误
            {
                QMessageBox::information(this,"警告","请检查拼写是否正确！",QMessageBox::Ok);
                ui->textInput->clear();
            }

        }else if (opt3 == 0)
        {
            alter_(strExec);
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
            select_(strExec);
        }
        else if(opt7 == 0)
        {
            //rename database 新名 to 旧名;
            //rename table 新名 to 旧名 in database 库名;
            QString type = strlist[1];
            if(type == "database" && strlist[3]=="to")
            {
                int op = rename_db(username, strlist[2], strlist[4]);
                if(op==1){
                    QMessageBox::information(this,"提示","修改成功！",QMessageBox::Ok);
                    ui->textInput->clear();
                }
                if(op==-1){
                    QMessageBox::information(this,"警告","库不存在！",QMessageBox::Ok);
                    ui->textInput->clear();
                }
                if(op==-2){
                    QMessageBox::information(this,"警告","新库名早已存在！",QMessageBox::Ok);
                    ui->textInput->clear();
                }
                if(op == -3){
                    QMessageBox::information(this,"警告","新库名命名不规范！",QMessageBox::Ok);
                    ui->textInput->clear();
                }
            }else if(type == "table" && strlist[6] == "database"&&strlist[5]=="in"&&strlist[3]=="to"){
                int op = rename_table(username, strlist[2], strlist[4], strlist[7]);
                if(op == 1){
                    QMessageBox::information(this,"警告","该数据库未打开！",QMessageBox::Ok);
                    ui->textInput->clear();
                }else if(op ==2){
                    QMessageBox::information(this,"警告","数据库不存在或文件打开失败！",QMessageBox::Ok);
                    ui->textInput->clear();
                }else if(op == 3){
                    QMessageBox::information(this,"警告","新表名在数据库里已存在！",QMessageBox::Ok);
                    ui->textInput->clear();
                }else if(op == 4){
                    QMessageBox::information(this,"警告","表不存在！",QMessageBox::Ok);
                    ui->textInput->clear();
                }else if(op == 5){
                    QMessageBox::information(this,"警告","新表名命名不规范！",QMessageBox::Ok);
                    ui->textInput->clear();
                }
                else{
                    //修改成功
                    QMessageBox::information(this,"提示","修改成功！",QMessageBox::Ok);
                    ui->textInput->clear();
                }
            }else{
                QMessageBox::information(this,"警告","请检查拼写是否正确！",QMessageBox::Ok);
                ui->textInput->clear();
            }

        }else if(opt8 == 0){
            //strlist的组成成分为3个单词： open、database、数据库名
            //故仅提取最后一个数据库名即可传入函数即可
            //先判断database这个单词拼对没有
            //只允许一个用户同一时间打开一个数据库
            QString letter = strlist[1];
            if(letter == "database"){

                QString dbname = strlist[2];    //这个数据库名记得传进各个函数里
                qDebug() << dbname << endl;
                int op = opendb_(dbname,username);
                if(op == -1){
                    QMessageBox::information(this,"警告","无效数据库名！",QMessageBox::Ok);
                    ui->textInput->clear();         //清空
                    //for(int i=0;i<list.size()-1;i++){
                        //ui->textInput->setText(list.at(i)+';');     //重新将之前的语句打印到输入框
                    //}
                }else if(op == 1){
                    QMessageBox::information(this,"提示","数据库打开成功！",QMessageBox::Ok);
                    ui->textInput->clear();
                }else if(op == -4){
                    QMessageBox::information(this,"提示","有另外的库已打开！",QMessageBox::Ok);
                    ui->textInput->clear();
                }
            }else{
                QMessageBox::information(this,"警告","请检查拼写是否正确！",QMessageBox::Ok);

                ui->textInput->clear();         //清空

            }
        }else if(opt9 == 0){
            QString letter = strlist[1];
            if(letter == "database"){
                QString dbname = strlist[2];
                qDebug() << dbname << endl;
                int op = closedb_(dbname,username);
                if(op == -1){
                    QMessageBox::information(this,"警告","无效数据库名！",QMessageBox::Ok);
                    ui->textInput->clear();         //清空
                }else if(op == 1){
                    QMessageBox::information(this,"提示","数据库关闭成功！",QMessageBox::Ok);
                    ui->textInput->clear();
                }
            }else{
                QMessageBox::information(this,"警告","请检查拼写是否正确！",QMessageBox::Ok);

                ui->textInput->clear();         //清空

            }
        }
        else{
            QMessageBox::information(this,"警告","无效关键词！",QMessageBox::Ok);

            ui->textInput->clear();         //清空

        }
    }


}
