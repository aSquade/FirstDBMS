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
        }else if (opt2 == 0){
            drop_(strExec);
        }else if (opt3 == 0){
            alter_(strExec);
        }else if (opt4 == 0){
            insert_(strExec);
        }else if (opt5 == 0){
            delete_(strExec);
        }else if (opt6 == 0){
            select_(strExec);
        }else if(opt7 == 0){
            //rename database 新名 to 旧名;
            //rename table 新名 to 旧名 in database 库名;
            QString type = strlist[1];
            if(type == "database" && strlist[3]=="to"){
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

