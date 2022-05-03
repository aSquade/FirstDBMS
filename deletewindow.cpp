#include "deletewindow.h"
#include "ui_deletewindow.h"
#include "db_deletewindow.h"
#include "tbl_deletewindow.h"
#include "database.h"
#include "user.h"
#include <QString>

DeleteWindow::DeleteWindow(QString usrname,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
    username=usrname;
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

//删除数据库
void DeleteWindow::on_DB_DeleteButton_clicked()
{
    DB_DeleteWindow *db = new DB_DeleteWindow(username);
    this->close();
    db->setWindowModality(Qt::ApplicationModal);
    db->show();
}

//删除表
void DeleteWindow::on_TBL_DeleteButton_clicked()
{
    TBL_DeleteWindow *tbl = new TBL_DeleteWindow(username);
    this->close();
    tbl->setWindowModality(Qt::ApplicationModal);
    tbl->show();
}


void DeleteWindow::on_cancelButton_clicked()
{
    this->close();
}

