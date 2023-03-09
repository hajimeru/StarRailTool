#pragma once
#include <QDateTime>
struct WishQueryDataModel
{
  //总计抽数
  int total_number;
  //四星已垫
  int four_after;
  //五星已垫
  int five_after;
  //开始时间
  QDateTime begin_time;
  //结束时间
  QDateTime end_time;
  //五星总抽数
  int rank5total;
  //五星所占比例
  double rank5ratio;
  //四星总抽数
  int rank4total;
  //四星所占比例
  double rank4ratio;
  //三星总抽数
  int rank3total;
  //三星所占比例
  double rank3ratio;
  //五星平均所用抽数
  int rank5avg;
  //平均up5星抽数
  int rank5Upavg;
  //小保底不歪个数
  int xiaobaodibuwai;
  //小保底歪个数
  int xiaobaodiwai;
  //最欧
  int zuiou;
  //最非
  int zuifei;
};

