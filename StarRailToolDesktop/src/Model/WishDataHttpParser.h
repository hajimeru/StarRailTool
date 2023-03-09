#pragma once
#include <QString>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

struct WishItem
{
  QString uid;
  QString gacha_id;
  QString gacha_type;
  QString item_id;
  QString count;
  QDateTime time;
  QString name;
  QString lang;
  QString item_type;
  QString rank_type;
  QString id;
};

struct WishaHttpData
{
  QString page;
  QString size;
  QVector<WishItem> list;
};

struct WishDataHttpReturnValue
{
  int retcode;
  QString message;
  WishaHttpData data;
};

struct WishDataHttpParser {
  static WishDataHttpReturnValue parser(const QString& json) 
  {
    QJsonParseError err_rpt;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(json.toUtf8(), &err_rpt); // 字符串格式化为JSON

    if (err_rpt.error != QJsonParseError::NoError)
    {
      qDebug() << "JSON格式错误";
    }
    else
    {
      WishDataHttpReturnValue retData;
      QJsonObject root_Obj = root_Doc.object();
      retData.retcode = root_Obj.value("retcode").toInt();
      retData.message = root_Obj.value("message").toString();
      QJsonObject data =  root_Obj.value("data").toObject();
      retData.data.page = data.value("page").toString();
      retData.data.size = data.value("size").toString();
      QJsonArray array = data.value("list").toArray();
      for (auto i : array)
      {
        WishItem item;
        item.uid = i.toObject().value("uid").toString();
        item.gacha_id = i.toObject().value("gacha_id").toString();
        item.gacha_type = i.toObject().value("gacha_type").toString();
        item.item_id = i.toObject().value("item_id").toString();
        item.count = i.toObject().value("count").toString();
        item.time = QDateTime::fromString(i.toObject().value("time").toString(),"yyyy-MM-dd hh:mm:ss");
        item.name = i.toObject().value("name").toString();
        item.lang = i.toObject().value("lang").toString();
        item.item_type = i.toObject().value("item_type").toString();
        item.rank_type = i.toObject().value("rank_type").toString();
        item.id = i.toObject().value("id").toString();
        retData.data.list.push_back(item);
      }
      return retData;
    }
    return WishDataHttpReturnValue();
  }
};



struct WishUrlStruct
{
  QString url;
  QString authkey_ver;
  QString sign_type;
  QString auth_appid;
  QString default_gacha_type;
  QString lang;
  QString authkey;
  QString game_biz;
  QString os_system;
  QString device_model;
  QString plat_type;
  QString page;
  QString size;
  QString gacha_type;
  QString end_id;
};

