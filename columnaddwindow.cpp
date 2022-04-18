#include "columnaddwindow.h"
#include "ui_columnaddwindow.h"

ColumnAddWindow::ColumnAddWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ColumnAddWindow)
{
    ui->setupUi(this);
}

ColumnAddWindow::~ColumnAddWindow()
{
    delete ui;
}

void ColumnAddWindow::on_cancelButton_clicked()
{
    this->close();
}


void ColumnAddWindow::on_confirmButton_clicked()
{


    this->close();
}


void ColumnAddWindow::on_addMoreButton_clicked()
{
    ColumnAddWindow *c = new ColumnAddWindow;
    this->on_confirmButton_clicked();
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

