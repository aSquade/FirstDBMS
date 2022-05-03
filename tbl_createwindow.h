#ifndef TBL_CREATEWINDOW_H
#define TBL_CREATEWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>

namespace Ui {
class TBL_CreateWindow;
}

class TBL_CreateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TBL_CreateWindow(QString usrname, QWidget *parent = nullptr);
    ~TBL_CreateWindow();

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::TBL_CreateWindow *ui;

public:
    QString username;
};

#endif // TBL_CREATEWINDOW_H
