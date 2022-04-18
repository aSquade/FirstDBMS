#include "columndeletewindow.h"
#include "ui_columndeletewindow.h"

ColumnDeleteWindow::ColumnDeleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ColumnDeleteWindow)
{
    ui->setupUi(this);
}

ColumnDeleteWindow::~ColumnDeleteWindow()
{
    delete ui;
}

void ColumnDeleteWindow::on_cancelButton_clicked()
{
    this->close();
}


void ColumnDeleteWindow::on_confirmButton_clicked()
{


    this->close();
}


void ColumnDeleteWindow::on_alterMoreButton_clicked()
{
    ColumnDeleteWindow *c = new ColumnDeleteWindow;
    this->on_confirmButton_clicked();
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

