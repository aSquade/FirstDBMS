#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H
#include "user.h"
#include "database.h"
#include <QMainWindow>
#include <QString>

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteWindow(QString usrname,QWidget *parent = nullptr);
    ~DeleteWindow();

private slots:
    void on_DB_DeleteButton_clicked();

    void on_TBL_DeleteButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::DeleteWindow *ui;
public:
    QString username;
};

#endif // DELETEWINDOW_H
