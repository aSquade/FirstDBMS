#include "db_createwindow.h"
#include "ui_db_createwindow.h"
#include "database.h"
#include "user.h"
#include <QMessageBox>
#include <string.h>
#include <io.h>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDateTime>
#include <QString>
using namespace std;
DB_CreateWindow::DB_CreateWindow(QString usrname,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DB_CreateWindow)
{
    ui->setupUi(this);
    username=usrname;
    connect(ui->confirmButton,SIGNAL(on_confirmButton_clicked()),SLOT(check_dbexists()));
    connect(ui->confirmButton,SIGNAL(on_confirmButton_clicked()),SLOT(db_write()));
}

DB_CreateWindow::~DB_CreateWindow()
{
    delete ui;
}

void DB_CreateWindow::on_confirmButton_clicked()
{
    QString s = ui->textEdit->toPlainText();//读取用户输入的数据库名称
    int length =  s.length();
    if(length>128)
    {
        QMessageBox::question(this,
        tr("error"),
        tr("数据库名称不得超过128个字符"),
        QMessageBox::Ok | QMessageBox::Cancel,
        QMessageBox::Ok);
    }
    //长度符合之后,创建数据库对象，传入用户名和库名
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
    this->close();
}


void DB_CreateWindow::on_cancelButton_clicked()
{
    this->close();
}

