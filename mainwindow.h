#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "user.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString usrname,QString pow,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createButton_clicked();

    void on_deleteButton_clicked();

    void on_addColumnButton_clicked();

    void on_alterColumnBotton_clicked();

    void on_deleteColumnButton_clicked();

    void on_insertDataButton_clicked();

    void on_deleteDataButton_clicked();

    void on_clearButton_clicked();

    void on_comfirmButton_clicked();

private:
    Ui::MainWindow *ui;
public:
     QString username;
     QString power;
};

#endif // MAINWINDOW_H
