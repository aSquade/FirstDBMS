#include "columndeletewindow.h"
#include "ui_columndeletewindow.h"
#include <QMessageBox>
#include "table.h"
#include "user.h"
#include "database.h"
#include <string.h>
#include "column.h"
ColumnDeleteWindow::ColumnDeleteWindow(QString usrname,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ColumnDeleteWindow)
{
    ui->setupUi(this);
    username = usrname;
}

ColumnDeleteWindow::~ColumnDeleteWindow()
{
    delete ui;
}

void ColumnDeleteWindow::on_cancelButton_clicked()
{
    this->close();
}


void ColumnDeleteWindow::on_confirmButton_clicked()
{
    QString db_name = ui->DB_Name->text(); //读取用户输入的数据库名称
    QString tbl_name = ui->TBL_Name->text(); //读取用户输入的表名称
    QString col_name = ui->columnName->text();//读取用户输入的列名称

    column col(username,db_name,tbl_name,col_name);
    int tbl_exists = col.tbl_exists(username,db_name,tbl_name);//检查表是否已存在
    if(tbl_exists==-1) //说明表存在
    {

        int col_exists = col.col_exists(username,db_name,tbl_name,col_name);//检查表是否已存在
        if(col_exists==-1) //说明字段存在，可以删除
        {
            col.col_out(username,db_name,tbl_name,col_name);
            QMessageBox::information(this,"提示","删除成功！",QMessageBox::Ok);
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

    this->close();
}


void ColumnDeleteWindow::on_alterMoreButton_clicked()
{
    //清空界面删除新字段
    this->on_confirmButton_clicked();
    ui->DB_Name->clear();
    ui->TBL_Name->clear();
    ui->columnName->clear();
    this->show();
}

