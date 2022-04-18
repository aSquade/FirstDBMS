#include "login.h"
#include "register.h"
#include "user.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login *w = new Login;
    w->setWindowTitle("用户登录");
    w->show();
    return a.exec();
}
