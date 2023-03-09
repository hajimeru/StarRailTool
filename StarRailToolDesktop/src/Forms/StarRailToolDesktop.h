#pragma once

#include <QWidget>
#include "ui_MainWindow.h"
class StarRailToolDesktop : public QWidget
{
    Q_OBJECT

public:
    StarRailToolDesktop(QWidget *parent = nullptr);
    ~StarRailToolDesktop();

protected:
  void updateMaximizeButton(bool maximized);

  private:
    void syncPosition();

private:
    Ui::MainWindow ui;
};
