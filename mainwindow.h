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
    explicit MainWindow(QString usrname,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createButton_clicked();

    void on_deleteButton_clicked();

    void on_addColumnButton_clicked();

    void on_alterColumnBotton_clicked();

    void on_deleteColumnButton_clicked();

private:
    Ui::MainWindow *ui;
public:
     QString username;
};

#endif // MAINWINDOW_H
