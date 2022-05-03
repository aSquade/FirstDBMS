#include "columnalterwindow.h"
#include "ui_columnalterwindow.h"

ColumnAlterWindow::ColumnAlterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ColumnAlterWindow)
{
    ui->setupUi(this);
}

ColumnAlterWindow::~ColumnAlterWindow()
{
    delete ui;
}

void ColumnAlterWindow::on_cancelButton_clicked()
{
    this->close();
}


void ColumnAlterWindow::on_confirmButton_clicked()
{

    this->close();
}

void ColumnAlterWindow::on_alterMoreButton_clicked()
{
    ColumnAlterWindow *c =new ColumnAlterWindow;
    this->on_confirmButton_clicked();
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

