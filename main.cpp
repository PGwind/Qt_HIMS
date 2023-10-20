#include "mainwindow.h"
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login n;
    n.show();

//    bool flagValue = n.getFlag();
//    MainWindow w;
//    w.show();
//    // 如果 flag 为 true，则打开 MainWindow
//    if (flagValue) {
//        w.close();
//    }

    return a.exec();
}
