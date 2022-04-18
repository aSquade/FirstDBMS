#include "db_deletewindow.h"
#include "ui_db_deletewindow.h"

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

    this->close();
}


void DB_DeleteWindow::on_cancelButton_clicked()
{
    this->close();
}

