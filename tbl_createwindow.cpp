#include "tbl_createwindow.h"
#include "ui_tbl_createwindow.h"
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

TBL_CreateWindow::TBL_CreateWindow(QString usrname, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TBL_CreateWindow)
{
    ui->setupUi(this);
    username = usrname;
}

TBL_CreateWindow::~TBL_CreateWindow()
{
    delete ui;
}

void TBL_CreateWindow::on_confirmButton_clicked()
{
    QString db_name = ui->DB_Name->text(); //读取用户输入的数据库名称
    QString tbl_name = ui->TBL_Name->text(); //读取用户输入的表名称
    QString col_name = ui->columnName->text(); //读取用户输入的列名称
    QString col_type = ui->columnType->currentText(); //读取用户输入的列类型
    QString check_name = ui->checkName->text(); //读取用户输入的约束名称
    QString check = ui->check->toPlainText(); //读取用户输入的约束

    int t_length = tbl_name.length(); //表名称长度限制128位
    if(t_length>128)
    {
        QMessageBox::question(this,
        tr("error"),
        tr("表名称不得超过128个字符"),
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
                int col_type_check = tbl.coltype_check(col_type);
                if (col_type_check==1)
                {
                    int* col = new int();
                }
                else if(col_type_check==2)
                {
                    bool* col = new bool();
                }
                else if(col_type==3)
                {
                    double* col = new double();
                }
                else if(col_type==4)
                {
                    QString* col = new QString();
                }
                else
                {
                    QDateTime* col = new QDateTime();
                }
            }
       }
       this->close();
    }


    this->close();
}


void TBL_CreateWindow::on_cancelButton_clicked()
{
    this->close();
}

