#ifndef DATADELETEWINDOW_H
#define DATADELETEWINDOW_H

#include <QMainWindow>

namespace Ui {
class DataDeleteWindow;
}

class DataDeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataDeleteWindow(QWidget *parent = nullptr);
    ~DataDeleteWindow();

private slots:
    void on_continueButton_clicked();

    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::DataDeleteWindow *ui;
};

#endif // DATADELETEWINDOW_H
