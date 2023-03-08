#pragma once
#include <QObject>
#include <QtTest>

class CTest : public QObject
{
	Q_OBJECT

public:
	CTest();

	~CTest();

private slots:

	//在第一个用例被调用之前，该函数执行，做一些初始化工作
	void initTestCase();

	//最后一个用例执行之后，该函数执行，做一些收尾/反初始化工作
	void cleanupTestCase();

	//每一个用例执行之前，该函数会执行
	void init();

	//每一个用例执行之后，该函数会执行
	void cleanup();

	//测试用例1
	void test_case1();

};