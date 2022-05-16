#include "datadeletewindow.h"
#include "ui_datadeletewindow.h"
#include <QMessageBox>

DataDeleteWindow::DataDeleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataDeleteWindow)
{
    ui->setupUi(this);
}

DataDeleteWindow::~DataDeleteWindow()
{
    delete ui;
}

void DataDeleteWindow::on_continueButton_clicked()
{




    //完成操作后不关闭该窗口，弹出操作成功提示窗口
    //然后将录入的三个数据框清空
    ui->datas->setText("");
    ui->datas_2->setText("");
    ui->datas_3->setText("");
    QMessageBox msg;
    msg.information(this, "提示","操作成功！",QMessageBox::Ok);
}

//确定按钮，完成本次数据删除后关闭窗口并返回主界面
void DataDeleteWindow::on_confirmButton_clicked()
{
    this->on_continueButton_clicked();
    this->close();
}


void DataDeleteWindow::on_cancelButton_clicked()
{
    this->close();
}

