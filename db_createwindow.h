#ifndef DB_CREATEWINDOW_H
#define DB_CREATEWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
namespace Ui {
class DB_CreateWindow;
}

class DB_CreateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DB_CreateWindow(QString usrname,QWidget *parent = nullptr);
    ~DB_CreateWindow();

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::DB_CreateWindow *ui;

public:
    QString username;
};

#endif // DB_CREATEWINDOW_H
