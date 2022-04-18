#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QMainWindow>

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteWindow(QWidget *parent = nullptr);
    ~DeleteWindow();

private slots:
    void on_DB_DeleteButton_clicked();

    void on_TBL_DeleteButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::DeleteWindow *ui;
};

#endif // DELETEWINDOW_H
