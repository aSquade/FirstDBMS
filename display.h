#ifndef DISPLAY_H
#define DISPLAY_H
#include <QString>
#include <QCoreApplication>
#include <QDebug>
#include <QFileDialog>

class Display
{
private:
    QString displayText;
public:
    Display(QString username);
    QString getText();
};

#endif // DISPLAY_H
