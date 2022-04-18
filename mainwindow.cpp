#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createwindow.h"
#include "deletewindow.h"
#include "columnaddwindow.h"
#include "columnalterwindow.h"
#include "columndeletewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//点击 “创建” 按钮
void MainWindow::on_createButton_clicked()
{
    CreateWindow *c = new CreateWindow;
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//点击 “删除" 按钮
void MainWindow::on_deleteButton_clicked()
{
    DeleteWindow *d = new DeleteWindow;
    d->setWindowModality(Qt::ApplicationModal);
    d->show();
}

//点击 “添加表字段” 按钮
void MainWindow::on_addColumnButton_clicked()
{
    ColumnAddWindow *c = new ColumnAddWindow;
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//点击 “修改表字段” 按钮
void MainWindow::on_alterColumnBotton_clicked()
{
    ColumnAlterWindow *c = new ColumnAlterWindow;
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//点击 “删除表字段” 按钮
void MainWindow::on_deleteColumnButton_clicked()
{
    ColumnDeleteWindow *c = new ColumnDeleteWindow;
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

