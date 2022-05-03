#ifndef COLUMNDELETEWINDOW_H
#define COLUMNDELETEWINDOW_H

#include <QMainWindow>

namespace Ui {
class ColumnDeleteWindow;
}

class ColumnDeleteWindow : public QMainWindow
{
    Q_OBJECT
protected:
    QString databasename;
    QString username;
    QString tablename;
public:
    explicit ColumnDeleteWindow(QString usrname,QWidget *parent = nullptr);
    ~ColumnDeleteWindow();

private slots:
    void on_cancelButton_clicked();

    void on_confirmButton_clicked();

    void on_alterMoreButton_clicked();

private:
    Ui::ColumnDeleteWindow *ui;
};

#endif // COLUMNDELETEWINDOW_H
