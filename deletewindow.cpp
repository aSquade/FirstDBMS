#include "deletewindow.h"
#include "ui_deletewindow.h"
#include "db_deletewindow.h"
#include "tbl_deletewindow.h"

DeleteWindow::DeleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

//删除数据库
void DeleteWindow::on_DB_DeleteButton_clicked()
{
    DB_DeleteWindow *db = new DB_DeleteWindow;
    this->close();
    db->setWindowModality(Qt::ApplicationModal);
    db->show();
}

//删除表
void DeleteWindow::on_TBL_DeleteButton_clicked()
{
    TBL_DeleteWindow *tbl = new TBL_DeleteWindow;
    this->close();
    tbl->setWindowModality(Qt::ApplicationModal);
    tbl->show();
}


void DeleteWindow::on_cancelButton_clicked()
{
    this->close();
}

