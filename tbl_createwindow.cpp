#include "tbl_createwindow.h"
#include "ui_tbl_createwindow.h"

TBL_CreateWindow::TBL_CreateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TBL_CreateWindow)
{
    ui->setupUi(this);
}

TBL_CreateWindow::~TBL_CreateWindow()
{
    delete ui;
}

void TBL_CreateWindow::on_confirmButton_clicked()
{

    this->close();
}


void TBL_CreateWindow::on_cancelButton_clicked()
{
    this->close();
}

