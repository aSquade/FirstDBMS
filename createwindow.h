#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QMainWindow>

namespace Ui {
class CreateWindow;
}

class CreateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateWindow(QWidget *parent = nullptr);
    ~CreateWindow();

private slots:
    void on_DB_CreateButton_clicked();

    void on_TBL_CreateButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CreateWindow *ui;
};

#endif // CREATEWINDOW_H
