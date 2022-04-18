#include "db_deletewindow.h"
#include "ui_db_deletewindow.h"
#include <QFile>
#include <QDir>
#include <QString>
#include <QMessageBox>
#include <QLineEdit>
DB_DeleteWindow::DB_DeleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DB_DeleteWindow)
{
    ui->setupUi(this);
}

DB_DeleteWindow::~DB_DeleteWindow()
{
    delete ui;
}

void DB_DeleteWindow::on_confirmButton_clicked()
{

    QString dataBaseName = ui->lineEdit->text();  //读取用户输入的数据库名称
    QString strPath = "D:\\simpleDBMS\\" + dataBaseName;
    if (strPath.isEmpty() || !QDir().exists(strPath))//是否传入了空的路径||路径是否存在
    {
        QMessageBox::question(this,
        tr("error"),
        tr("找不到该数据库"),
        QMessageBox::Ok | QMessageBox::Cancel,
        QMessageBox::Ok);
    }
    QDir qDir(strPath);
    qDir.removeRecursively();
    QMessageBox::question(this,
    tr("success"),
    tr("删除成功"),
    QMessageBox::Ok | QMessageBox::Cancel,
    QMessageBox::Ok);


    this->close();
}


void DB_DeleteWindow::on_cancelButton_clicked()
{
    this->close();
}

