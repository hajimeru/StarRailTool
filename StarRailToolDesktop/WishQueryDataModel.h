#pragma once
#include <QDateTime>
struct WishQueryDataModel
{
  //�ܼƳ���
  int total_number;
  //�����ѵ�
  int four_after;
  //�����ѵ�
  int five_after;
  //��ʼʱ��
  QDateTime begin_time;
  //����ʱ��
  QDateTime end_time;
  //�����ܳ���
  int rank5total;
  //������ռ����
  double rank5ratio;
  //�����ܳ���
  int rank4total;
  //������ռ����
  double rank4ratio;
  //�����ܳ���
  int rank3total;
  //������ռ����
  double rank3ratio;
  //����ƽ�����ó���
  int rank5avg;
  //ƽ��up5�ǳ���
  int rank5Upavg;
  //С���ײ������
  int xiaobaodibuwai;
  //С���������
  int xiaobaodiwai;
  //��ŷ
  int zuiou;
  //���
  int zuifei;
};

