#ifndef COLUMNADDWINDOW_H
#define COLUMNADDWINDOW_H

#include <QMainWindow>

namespace Ui {
class ColumnAddWindow;
}

class ColumnAddWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ColumnAddWindow(QWidget *parent = nullptr);
    ~ColumnAddWindow();

private slots:
    void on_cancelButton_clicked();

    void on_confirmButton_clicked();

    void on_addMoreButton_clicked();

private:
    Ui::ColumnAddWindow *ui;
};

#endif // COLUMNADDWINDOW_H
