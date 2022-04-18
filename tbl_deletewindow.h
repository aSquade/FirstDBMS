#ifndef TBL_DELETEWINDOW_H
#define TBL_DELETEWINDOW_H

#include <QMainWindow>

namespace Ui {
class TBL_DeleteWindow;
}

class TBL_DeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TBL_DeleteWindow(QWidget *parent = nullptr);
    ~TBL_DeleteWindow();

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::TBL_DeleteWindow *ui;
};

#endif // TBL_DELETEWINDOW_H
