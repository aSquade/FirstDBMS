#include "tbl_deletewindow.h"
#include "ui_tbl_deletewindow.h"
#include "table.h"
#include "user.h"
#include <QMessageBox>
#include <string.h>
#include <io.h>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDateTime>
#include <QString>
#include <QCoreApplication>

TBL_DeleteWindow::TBL_DeleteWindow(QString usrname,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TBL_DeleteWindow)
{
    username = usrname;
    ui->setupUi(this);
}

TBL_DeleteWindow::~TBL_DeleteWindow()
{
    delete ui;
}

void TBL_DeleteWindow::on_confirmButton_clicked()
{
    QString db_name = ui->lineEdit_2->text(); //读取用户输入的数据库名称
    QString tbl_name = ui->lineEdit->text(); //读取用户输入的表名称
    QString FileName = QCoreApplication::applicationDirPath();
    QString strPath = FileName+"/data/"+username+"/"+db_name;
    QString fileName = strPath+"table.txt";
    table tbl(username,db_name,tbl_name);
    int tbl_exists = tbl.tbl_exists(username,db_name,tbl_name);//检查表是否已存在
    if(tbl_exists==-1){
        //说明表存在，可以删除
        tbl.table_out(username,db_name,tbl_name);
        QMessageBox::information(this,"提示","删除成功！",QMessageBox::Ok);
    }else{
        QMessageBox::information(this,"提示","该表不存在！",QMessageBox::Ok);
    }


    this->close();
}


void TBL_DeleteWindow::on_cancelButton_clicked()
{
    this->close();
}

