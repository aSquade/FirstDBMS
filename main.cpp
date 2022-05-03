#include "login.h"
#include "register.h"
#include "user.h"
#include "database.h"
#include <QApplication>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login *w = new Login;
    w->setWindowTitle("用户登录");
    w->show();
    QString fileName = QCoreApplication::applicationDirPath();//到生成文件的debug文件夹里
    QFileInfo info(fileName);
    qDebug()<<"filename:"<<fileName;
    return a.exec();
}
