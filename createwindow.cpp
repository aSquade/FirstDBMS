#include "createwindow.h"
#include "ui_createwindow.h"
#include "db_createwindow.h"
#include "tbl_createwindow.h"
#include <QString>

CreateWindow::CreateWindow(QString usrname,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateWindow)
{
    ui->setupUi(this);
    username=usrname;
}

CreateWindow::~CreateWindow()
{
    delete ui;
}

//创建数据库
void CreateWindow::on_DB_CreateButton_clicked()
{
    DB_CreateWindow *db = new DB_CreateWindow(username);
    this->close();
    db->setWindowModality(Qt::ApplicationModal);
    db->show();
}

//创建表
void CreateWindow::on_TBL_CreateButton_clicked()
{
    TBL_CreateWindow *tbl = new TBL_CreateWindow(username);
    this->close();
    tbl->setWindowModality(Qt::ApplicationModal);
    tbl->show();
}


void CreateWindow::on_cancelButton_clicked()
{
    this->close();
}

