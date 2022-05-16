#include "datainsertwindow.h"
#include "ui_datainsertwindow.h"
#include "row.h"
#include "column.h"
#include <QMessageBox>

DataInsertWindow::DataInsertWindow(QString usrname,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataInsertWindow)
{
    ui->setupUi(this);
    //this->resize(QSize(800,600));
    username=usrname;
}

DataInsertWindow::~DataInsertWindow()
{
    delete ui;
}

//继续插入数据
   void DataInsertWindow::on_continueButton_clicked()
{
//    //读取用户输入的库、表、列、数据四个内容
//    QString db_name = ui->db_name->text();
//    QString tbl_name = ui->tbl_name->text();
//    QString col_name = ui->col_name->text();
//    QString newData = ui->datas->text();

//    row newdata(username,db_name,tbl_name,col_name,newData);//创建行对象（只有插入一个数据项
//    column *col;    //创建一个column类型指针方便使用column类里的函数
//    int db_exists = col->db_exists(username,db_name);//检查库是否已存在
//    if(db_exists==1){
//        QMessageBox::information(this,"警告","此数据库不存在！请先创建数据库。",QMessageBox::Ok);
//    }else if(db_exists==-2){
//        QMessageBox::information(this,"警告","数据库文件打开失败!",QMessageBox::Ok);
//    }
//    else{
//        int tbl_exists = col->tbl_exists(username,db_name,tbl_name);//检查表是否已存在
//        if(tbl_exists==-1){
//            int col_exists = col->col_exists(username,db_name,tbl_name,col_name);
//            if(col_exists==1){
//                QMessageBox::information(this,"警告","此字段不存在！请先创建字段。",QMessageBox::Ok);
//            }else if(col_exists==-2){
//                 QMessageBox::information(this,"警告","字段文件打开失败!",QMessageBox::Ok);
//            }else{
//                //开始写入数据


//            }
//        }else if(tbl_exists==-2){
//            QMessageBox::information(this,"警告","表文件打开失败!",QMessageBox::Ok);
//        }else{
//            QMessageBox::information(this,"警告","表不存在！请先创建表!",QMessageBox::Ok);
//        }
//    }

//    //完成操作后不关闭该窗口，弹出操作成功提示窗口
//    //然后将录入的数据框清空
//    ui->datas->setText("");
//    ui->col_name->setText("");
//    QMessageBox msg;
//    msg.information(this, "提示","操作成功！",QMessageBox::Ok);
}


void DataInsertWindow::on_confirmButton_clicked()
{
//    //完成操作后不关闭该窗口，弹出操作成功提示窗口
//    //然后将录入的数据框清空
//    ui->datas->setText("");
//    ui->col_name->setText("");
//    QMessageBox msg;
//    msg.information(this, "提示","操作成功！",QMessageBox::Ok);
}


void DataInsertWindow::on_cancelButton_clicked()
{
//    this->close();
}

////完成按钮，完成本次数据插入操作后关闭窗口并返回主界面
void DataInsertWindow::on_completeButton_clicked()
{
//    this->on_continueButton_clicked();
//    this->close();
}

