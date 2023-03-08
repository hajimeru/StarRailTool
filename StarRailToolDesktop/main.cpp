#include "StarRailToolDesktop.h"

#include <QtWidgets/QApplication>
#include <qnamespace.h>

#include "CTest.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    StarRailToolDesktop w;
    w.show();

    CTest test;
    QTEST_SET_MAIN_SOURCE_PATH;
    qDebug() << QTest::qExec(&test, argc, argv);   //执行test类中的测试用例  全部成功返回0  有失败返回非0

    return a.exec();
}
