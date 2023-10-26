#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login n;
    n.show();

    return a.exec();
}
