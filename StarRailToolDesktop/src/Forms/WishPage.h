#pragma once

#include <QWidget>
#include "ui_WishPage.h"

#include "WishDataHttpParser.h"
class WishPageQueryTemplate;

class WishPage : public QWidget
{
  Q_OBJECT

public:
  WishPage(QWidget* parent = nullptr);
  ~WishPage();

private:
  void showWishData();
  void getWishDataItems(QString authkey,QString page,QString size,QString end_id);
  
signals:
  void emitGetWishDataItems(QString authkey, QString page, QString size, QString end_id);

private:
  Ui::WishPage ui;

  WishPageQueryTemplate* commonWishPage_;
  WishPageQueryTemplate* characterWishPage_;
  WishPageQueryTemplate* pathsWishPage_;

  QVector<WishItem> wishItemList_;
};
