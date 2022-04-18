#include "tbl_deletewindow.h"
#include "ui_tbl_deletewindow.h"

TBL_DeleteWindow::TBL_DeleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TBL_DeleteWindow)
{
    ui->setupUi(this);
}

TBL_DeleteWindow::~TBL_DeleteWindow()
{
    delete ui;
}

void TBL_DeleteWindow::on_confirmButton_clicked()
{

    this->close();
}


void TBL_DeleteWindow::on_cancelButton_clicked()
{
    this->close();
}

