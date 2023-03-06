#include "StarRailToolDesktop.h"

#include <QTimer>
#include <QWindow>
#include <QScreen>
#include <QPainter>

#include "FramelessHelper.h"


StarRailToolDesktop::StarRailToolDesktop(QWidget *parent) 
  :QWidget(parent, Qt::FramelessWindowHint)
{
    ui.setupUi(this);


    setWindowTitle("Qt Widgets");

    auto helper = new FramelessHelper(this);
    helper->setDraggableMargins(3, 3, 3, 3);
    helper->setMaximizedMargins(3, 3, 3, 3);
    helper->setTitleBarHeight(32);

    helper->addExcludeItem(ui.minimizeButton);
    helper->addExcludeItem(ui.maximizeButton);
    helper->addExcludeItem(ui.closeButton);

    connect(ui.minimizeButton, &QPushButton::clicked,
      helper, &FramelessHelper::triggerMinimizeButtonAction);
    connect(ui.maximizeButton, &QPushButton::clicked,
      helper, &FramelessHelper::triggerMaximizeButtonAction);
    connect(ui.closeButton, &QPushButton::clicked,
      helper, &FramelessHelper::triggerCloseButtonAction);

    connect(helper, &FramelessHelper::maximizedChanged,
      this, &StarRailToolDesktop::updateMaximizeButton);

    ui.maximizeButton->setIcon(QIcon(QStringLiteral(":/icon/asset/icon/maximize-button1.png")));

    QTimer::singleShot(100, this, &StarRailToolDesktop::syncPosition);
}

StarRailToolDesktop::~StarRailToolDesktop()
{

}

void StarRailToolDesktop::updateMaximizeButton(bool maximized)
{
  if (maximized) {
    ui.maximizeButton->setIcon(QIcon(QStringLiteral(":/icon/asset/icon/maximize-button2.png")));
    ui.maximizeButton->setToolTip(tr("Restore"));
  }
  else {
    ui.maximizeButton->setIcon(QIcon(QStringLiteral(":/icon/asset/icon/maximize-button1.png")));
    ui.maximizeButton->setToolTip(tr("Maximize"));
  }
}

void StarRailToolDesktop::syncPosition()
{
  QWindow* window = windowHandle();
  QScreen* screen = window->screen();

  window->setX(screen->availableGeometry().width() / 2 + 10);
}
