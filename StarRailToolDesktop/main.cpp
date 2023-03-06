#include "StarRailToolDesktop.h"
#include <QtWidgets/QApplication>
#include <qnamespace.h>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    StarRailToolDesktop w;
    w.show();
    return a.exec();
}
