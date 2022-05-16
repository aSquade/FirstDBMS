#include "columnalterwindow.h"
#include "ui_columnalterwindow.h"
#include "column.h"
#include "user.h"
#include <QMessageBox>

ColumnAlterWindow::ColumnAlterWindow(QString usrname,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ColumnAlterWindow)
{
    ui->setupUi(this);
    username = usrname;
}

ColumnAlterWindow::~ColumnAlterWindow()
{
    delete ui;
}

void ColumnAlterWindow::on_cancelButton_clicked()
{
    this->close();
}


void ColumnAlterWindow::on_confirmButton_clicked()
{
    QString db_name = ui->DB_Name->text(); //读取用户输入的数据库名称
    QString tbl_name = ui->TBL_Name->text(); //读取用户输入的表名称
    QString col_name = ui->columnName->text(); //读取用户输入的原列名称
    QString newcol_name = ui->changeName->text();//读取用户输入的新列名称
    column col(username,db_name,tbl_name,col_name);
    int db_exists = col.db_exists(username,db_name);//检查库是否已存在
    if(db_exists!=-1){
        QMessageBox::information(this,"警告","此数据库不存在！请先创建数据库。",QMessageBox::Ok);
    }
    else
    {
            int tbl_exists = col.tbl_exists(username,db_name,tbl_name);//检查表是否已存在
            if(tbl_exists==-1){
                int changeName = col.col_namechange(username,db_name,tbl_name,col_name,newcol_name);
                if(changeName==-1){
                    QMessageBox::information(this,"警告","表中已存在此新列名，请重新输入列名！",QMessageBox::Ok);
                    ui->changeName->clear();
                }else if(changeName==-2){
                    QMessageBox::information(this,"警告","要修改的列名不存在！请重新输入！",QMessageBox::Ok);
                    ui->columnName->clear();
                    ui->changeName->clear();
                }else if(changeName==0){
                    QMessageBox::information(this,"警告","表中无字段！",QMessageBox::Ok);
                    this->close();
                }
                else{
                    QMessageBox::information(this,"提示","列名修改成功！",QMessageBox::Ok);
                    this->close();
                }
            }
            else
            {
                 QMessageBox::information(this,"警告","此表不存在！",QMessageBox::Ok);
            }
    }


    this->close();
}

void ColumnAlterWindow::on_alterMoreButton_clicked()
{
    ColumnAlterWindow *c =new ColumnAlterWindow(username);
    this->on_confirmButton_clicked();
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

