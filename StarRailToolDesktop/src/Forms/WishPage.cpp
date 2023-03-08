#include "WishPage.h"
#include <QVBoxLayout>

#include "WishPageQueryTemplate.h"

WishPage::WishPage(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  QVBoxLayout* layout = new QVBoxLayout;
  ui.scrollAreaWidgetContents->setLayout(layout);
  for (int i = 0; i < 5; i++)
  {
    WishPageQueryTemplate* w = new WishPageQueryTemplate();
    layout->addWidget(w);
  }
}

WishPage::~WishPage()
{}
