#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H
#include "user.h"
#include "database.h"
#include <QString>
#include <QMainWindow>

namespace Ui {
class CreateWindow;
}

class CreateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateWindow(QString usrname,QWidget *parent = nullptr);
    ~CreateWindow();

private slots:
    void on_DB_CreateButton_clicked();

    void on_TBL_CreateButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CreateWindow *ui;
public:
    QString username;
};

#endif // CREATEWINDOW_H
