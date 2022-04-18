#include "db_createwindow.h"
#include "ui_db_createwindow.h"

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

    this->close();
}


void DB_CreateWindow::on_cancelButton_clicked()
{
    this->close();
}

