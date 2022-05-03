#ifndef TBL_DELETEWINDOW_H
#define TBL_DELETEWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "database.h"
#include <QMainWindow>
#include <QString>

namespace Ui {
class TBL_DeleteWindow;
}

class TBL_DeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TBL_DeleteWindow(QString usrname,QWidget *parent = nullptr);
    ~TBL_DeleteWindow();

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::TBL_DeleteWindow *ui;
public:
    QString username;
};

#endif // TBL_DELETEWINDOW_H
