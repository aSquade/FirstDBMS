#include "columnaddwindow.h"
#include "ui_columnaddwindow.h"
#include <QMessageBox>
#include "column.h"
#include "user.h"
#include "database.h"
#include <string.h>

ColumnAddWindow::ColumnAddWindow(QString usrname,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ColumnAddWindow)
{
    ui->setupUi(this);
    username = usrname;
}

ColumnAddWindow::~ColumnAddWindow()
{
    delete ui;
}

void ColumnAddWindow::on_cancelButton_clicked()
{
    this->close();
}

void ColumnAddWindow::on_confirmButton_clicked()
{
    QString db_name = ui->DB_Name->text(); //读取用户输入的数据库名称
    QString tbl_name = ui->TBL_Name->text(); //读取用户输入的表名称
    QString col_name = ui->columnName->text(); //读取用户输入的列名称
    QString col_type = ui->columnType->currentText(); //读取用户输入的列类型
    QString check_name = ui->checkName->text(); //读取用户输入的约束名称
    QString check = ui->check->toPlainText(); //读取用户输入的约束

    column col(username, db_name, tbl_name,col_name); //长度符合之后,创建字段对象，传入用户名、库名和表名
    int db_exists = col.db_exists(username,db_name);//检查库是否已存在
    if(db_exists!=-1){
        QMessageBox::information(this,"警告","此数据库不存在！请先创建数据库。",QMessageBox::Ok);
    }
    else
    {
            int tbl_exists = col.tbl_exists(username,db_name,tbl_name);//检查表是否已存在
            if(tbl_exists==-1)
            {
                    //进行写入的操作
                    int chdone = col.col_in(username,db_name,tbl_name,col_name,col_type,check_name,check);
                    if(chdone==-1)
                    {
                        //写入失败
                        QMessageBox::information(this,"警告","插入字段失败！",QMessageBox::Ok);
                    }
                    else
                    {
                        QMessageBox::information(this,"提示","插入字段成功！",QMessageBox::Ok);
                        int col_type_check = col.coltype_check(col_type);
                        if (col_type_check==1){
                            char* col = new char();
                        }else if(col_type_check==2){
                            int* col = new int();
                        }else{

                        }
                    }
            }
            else
            {
                 QMessageBox::information(this,"警告","此表不存在！",QMessageBox::Ok);
            }
    }

    this->close();
}


void ColumnAddWindow::on_addMoreButton_clicked()
{
    //清空界面插入新字段
    this->on_confirmButton_clicked();
    ui->DB_Name->clear();
    ui->TBL_Name->clear();
    ui->columnName->clear();
    ui->checkName->clear();
    ui->check->clear();
    this->show();

}

