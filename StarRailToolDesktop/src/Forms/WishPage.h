#pragma once

#include <QWidget>
#include "ui_WishPage.h"

class WishPage : public QWidget
{
    Q_OBJECT

public:
    WishPage(QWidget *parent = nullptr);
    ~WishPage();

private:
    Ui::WishPage ui;
};
