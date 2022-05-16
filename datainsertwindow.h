#ifndef DATAINSERTWINDOW_H
#define DATAINSERTWINDOW_H

#include <QMainWindow>

namespace Ui {
class DataInsertWindow;
}

class DataInsertWindow : public QMainWindow
{
    Q_OBJECT
protected:
    QString username;


public:
    explicit DataInsertWindow(QString usrname,QWidget *parent = nullptr);
    ~DataInsertWindow();

private slots:
    void on_continueButton_clicked();

    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

    void on_completeButton_clicked();

private:
    Ui::DataInsertWindow *ui;
};

#endif // DATAINSERTWINDOW_H
