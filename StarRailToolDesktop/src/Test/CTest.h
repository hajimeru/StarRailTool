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

	//�ڵ�һ������������֮ǰ���ú���ִ�У���һЩ��ʼ������
	void initTestCase();

	//���һ������ִ��֮�󣬸ú���ִ�У���һЩ��β/����ʼ������
	void cleanupTestCase();

	//ÿһ������ִ��֮ǰ���ú�����ִ��
	void init();

	//ÿһ������ִ��֮�󣬸ú�����ִ��
	void cleanup();

	//��������1
	void test_case1();

};