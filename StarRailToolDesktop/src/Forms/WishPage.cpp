#include "WishPage.h"
#include <QVBoxLayout>

#include "WishPageQueryTemplate.h"
#include "HttpClient.h"
#include "WishDataHttpParser.h"

WishPage::WishPage(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  QVBoxLayout* layout = new QVBoxLayout;
  ui.scrollAreaWidgetContents->setLayout(layout);
  commonWishPage_ = new WishPageQueryTemplate(WishPoolType::Common);
  characterWishPage_ = new WishPageQueryTemplate(WishPoolType::CharaterUp);
  pathsWishPage_ = new WishPageQueryTemplate(WishPoolType::PathsUp);
  layout->addWidget(commonWishPage_);
  layout->addWidget(characterWishPage_);
  layout->addWidget(pathsWishPage_);
  connect(ui.showWishDataButton, &QPushButton::clicked, this, &WishPage::showWishData);
  connect(this, &WishPage::emitGetWishDataItems, this, &WishPage::getWishDataItems);
}

WishPage::~WishPage()
{}

void WishPage::showWishData()
{
  //获取地址（暂时输入）
  QString authkey = ui.urlTextEdit->toPlainText();

  getWishDataItems(authkey,"1","6","0");
}

void WishPage::getWishDataItems(QString authkey, QString page, QString size, QString end_id)
{
  WishUrlStruct wishUrlStruct = commonWishPage_->wishUrlStruct;
  //获取角色
  static AeaQt::HttpClient client;
  QString url = QString("https://api-takumi.mihoyo.com/common/gacha_record/api/getGachaLog?authkey_ver=1&sign_type=2&auth_appid=webview_gacha&default_gacha_type=11&lang=zh-cn&authkey=").append(authkey).append(QString("&game_biz=hkrpg_cn&os_system=Windows+10++(10.0.19045)+64bit&device_model=82JQ+(LENOVO)&plat_type=pc&page=%1&size=%2&gacha_type=%3&end_id=%4")
    .arg(page)
    .arg(size)
    .arg(wishUrlStruct.gacha_type)
    .arg(end_id));
  qDebug() << "url" << url;
  client.get(url)
    .onSuccess([this,page,authkey](QString result) {
    WishDataHttpReturnValue v = WishDataHttpParser::parser(result);
    wishItemList_.append(v.data.list);
    qDebug() << "page" << page;
    if (v.data.list.size() == 6)
    {
      QTimer::singleShot(1000, [this, page, authkey,v] {
        emit emitGetWishDataItems(authkey, QString::number(page.toInt() + 1), "6", v.data.list.last().id);
        });
    }
    else
    {
      qDebug() << wishItemList_.size();
    }
      })
    .onFailed([](QString error) {
        qDebug() << "error:" << error;
      })
        .onTimeout([](QNetworkReply*) {
        qDebug() << "timeout";
          }) // 超时处理
        .timeout(2000) // 1s超时
            .exec();
}
