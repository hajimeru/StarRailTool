#pragma once

#include <QWidget>
#include "ui_WishPageQueryTemplate.h"

class WishPageQueryTemplate : public QWidget
{
    Q_OBJECT

public:
    WishPageQueryTemplate(QWidget *parent = nullptr);
    ~WishPageQueryTemplate();

private:
    Ui::WishPageQueryTemplate ui;
};
