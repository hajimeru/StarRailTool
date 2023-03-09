#pragma once

#include <QWidget>
#include "ui_WishPageQueryTemplate.h"
#include "WishDataHttpParser.h"

enum class WishPoolType
{
  Common = 0,
  CharaterUp = 1,
  PathsUp = 2,
};

class WishPageQueryTemplate : public QWidget
{
    Q_OBJECT

public:
    WishPageQueryTemplate(WishPoolType pooltype, QWidget *parent = nullptr);
    ~WishPageQueryTemplate();

    WishUrlStruct wishUrlStruct;
private:
    Ui::WishPageQueryTemplate ui;

    void initCommonPoolUI();
    void initCharaterUpPoolUI();
    void initPathsUpPoolUI();

};
