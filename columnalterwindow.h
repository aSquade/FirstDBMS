#ifndef COLUMNALTERWINDOW_H
#define COLUMNALTERWINDOW_H

#include <QMainWindow>

namespace Ui {
class ColumnAlterWindow;
}

class ColumnAlterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ColumnAlterWindow(QWidget *parent = nullptr);
    ~ColumnAlterWindow();

private slots:
    void on_cancelButton_clicked();

    void on_confirmButton_clicked();

    void on_alterMoreButton_clicked();

private:
    Ui::ColumnAlterWindow *ui;
};

#endif // COLUMNALTERWINDOW_H
