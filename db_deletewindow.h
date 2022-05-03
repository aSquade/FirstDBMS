#ifndef DB_DELETEWINDOW_H
#define DB_DELETEWINDOW_H
#include "user.h"
#include "database.h"
#include <QMainWindow>
#include <QString>

namespace Ui {
class DB_DeleteWindow;
}

class DB_DeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DB_DeleteWindow(QString usrname,QWidget *parent = nullptr);
    ~DB_DeleteWindow();

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::DB_DeleteWindow *ui;
public:
    QString username;
};

#endif // DB_DELETEWINDOW_H
