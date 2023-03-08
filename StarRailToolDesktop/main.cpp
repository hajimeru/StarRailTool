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
    qDebug() << QTest::qExec(&test, argc, argv);   //ִ��test���еĲ�������  ȫ���ɹ�����0  ��ʧ�ܷ��ط�0

    return a.exec();
}
