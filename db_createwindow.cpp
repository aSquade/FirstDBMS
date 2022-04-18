#include "db_createwindow.h"
#include "ui_db_createwindow.h"
#include <QMessageBox>
#include <string.h>
#include <io.h>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDateTime>
using namespace std;
DB_CreateWindow::DB_CreateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DB_CreateWindow)
{
    ui->setupUi(this);
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
    //长度符合之后
    string dataBaseName = s.toStdString();
    string pathName = "D:\\simpleDBMS\\" + dataBaseName;//文件夹位置，相当于数据库
    string fileName = pathName + "\\db.txt";//文件位置，存放数据库的相关信息
    QString qs = QString::fromStdString(fileName);
    QFile file(qs);
    if (0 != access(pathName.c_str(), 0))
    {
       if (0 == mkdir(pathName.c_str()))//返回0表示创建成功,-1表示失败
       {
           if(! file.open(QIODevice::Append|QIODevice::Text))  //append追加，不会覆盖之前的文件
           {
                   QMessageBox::critical(this,"错误","文件打开失败，信息没有保存！","确定");
                   return;
           }
          QMessageBox::question(this,
          tr("success"),
          tr("创建成功"),
          QMessageBox::Ok | QMessageBox::Cancel,
          QMessageBox::Ok);
        }
          else
       {

          QMessageBox::question(this,
          tr("error"),
          tr("创建失败"),
          QMessageBox::Ok | QMessageBox::Cancel,
          QMessageBox::Ok);
        }

     }
    else
    {
          QMessageBox::question(this,
          tr("error"),
          tr("该数据库已存在"),
          QMessageBox::Ok | QMessageBox::Cancel,
          QMessageBox::Ok);
    }

          QFileInfo info(qs);
          QString str = info.birthTime().toString();
          QString dbInfo = s+"#"+ QString::fromStdString(pathName)+"#"+str+"#"+"用户数据库";//#作为分隔符
          QTextStream out(&file);//写入
          out << dbInfo;
          file.close();
    this->close();
}


void DB_CreateWindow::on_cancelButton_clicked()
{
    this->close();
}

