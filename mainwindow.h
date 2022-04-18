#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createButton_clicked();

    void on_deleteButton_clicked();

    void on_tableOperation_clicked();

    void on_addColumnButton_clicked();

    void on_alterColumnBotton_clicked();

    void on_deleteColumnButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
