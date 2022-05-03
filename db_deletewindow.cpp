#include "db_deletewindow.h"
#include "ui_db_deletewindow.h"
#include "database.h"
#include "user.h"
#include <QFile>
#include <QDir>
#include <QString>
#include <QMessageBox>
#include <QLineEdit>
DB_DeleteWindow::DB_DeleteWindow(QString usrname,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DB_DeleteWindow)
{
    ui->setupUi(this);
    username=usrname;
    connect(ui->confirmButton,SIGNAL(on_confirmButton_clicked()),SLOT(db_delete()));
    connect(ui->confirmButton,SIGNAL(on_confirmButton_clicked()),SLOT((check_dbexists)));
}

DB_DeleteWindow::~DB_DeleteWindow()
{
    delete ui;
}

void DB_DeleteWindow::on_confirmButton_clicked()
{
    QString s = ui->lineEdit->text();  //读取用户输入的数据库名称
    QString strPath = "E:/MyDBMS/dbms2_ver2.0/dbms2/dbms2/dbms2/data/" + username;
    QString fileName = strPath+"/database.txt";
    Database db(username,s);
    int chexists = db.check_dbexists(username,s);//检查库是否已存在
    if(chexists==-1){
        //说明数据库存在，可以删除
        db.db_out(username,s);
        QMessageBox::information(this,"提示","删除成功！",QMessageBox::Ok);
    }else{
        QMessageBox::information(this,"提示","该数据库不存在！",QMessageBox::Ok);
    }
    this->close();
}


void DB_DeleteWindow::on_cancelButton_clicked()
{
    this->close();
}

