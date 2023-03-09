#include "WishPageQueryTemplate.h"

WishPageQueryTemplate::WishPageQueryTemplate(WishPoolType pooltype, QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

		switch (pooltype)
		{
		case WishPoolType::Common:
			initCommonPoolUI();
			break;
		case WishPoolType::CharaterUp:
			initCharaterUpPoolUI();
			break;
		case WishPoolType::PathsUp:
			initPathsUpPoolUI();
			break;
		default:
			break;
		}

}

WishPageQueryTemplate::~WishPageQueryTemplate()
{}

void WishPageQueryTemplate::initCommonPoolUI()
{
	ui.pool_title->setText(QString::fromLocal8Bit("³£×¤³Ø"));
	wishUrlStruct.url = "https://api-takumi.mihoyo.com/common/gacha_record/api/getGachaLog";
	wishUrlStruct.authkey_ver = "1";
	wishUrlStruct.sign_type = "2";
	wishUrlStruct.auth_appid = "webview_gacha";
	wishUrlStruct.default_gacha_type = "11";
	wishUrlStruct.lang = "zh-cn";
	wishUrlStruct.game_biz = "hkrpg_cn";
	wishUrlStruct.os_system = "Windows+10++(10.0.19045)+64bit";
	wishUrlStruct.device_model = "82JQ+(LENOVO)";
	wishUrlStruct.plat_type = "pc";
	wishUrlStruct.gacha_type = "11";
	wishUrlStruct.end_id = "0";
}

void WishPageQueryTemplate::initCharaterUpPoolUI()
{
	ui.pool_title->setText(QString::fromLocal8Bit("½ÇÉ«Up³Ø"));
	wishUrlStruct.url = "https://api-takumi.mihoyo.com/common/gacha_record/api/getGachaLog";
	wishUrlStruct.authkey = "1";
	wishUrlStruct.sign_type = "2";
	wishUrlStruct.auth_appid = "webview_gacha";
	wishUrlStruct.default_gacha_type = "11";
	wishUrlStruct.lang = "zh-cn";
	wishUrlStruct.game_biz = "hkrpg_cn";
	wishUrlStruct.os_system = "Windows+10++(10.0.19045)+64bit";
	wishUrlStruct.device_model = "82JQ+(LENOVO)";
	wishUrlStruct.plat_type = "pc";
	wishUrlStruct.gacha_type = "11";
	wishUrlStruct.end_id = "0";
}

void WishPageQueryTemplate::initPathsUpPoolUI()
{
	ui.pool_title->setText(QString::fromLocal8Bit("ÃüÍ¾Up³Ø"));
	wishUrlStruct.url = "https://api-takumi.mihoyo.com/common/gacha_record/api/getGachaLog";
	wishUrlStruct.authkey = "1";
	wishUrlStruct.sign_type = "2";
	wishUrlStruct.auth_appid = "webview_gacha";
	wishUrlStruct.default_gacha_type = "11";
	wishUrlStruct.lang = "zh-cn";
	wishUrlStruct.game_biz = "hkrpg_cn";
	wishUrlStruct.os_system = "Windows+10++(10.0.19045)+64bit";
	wishUrlStruct.device_model = "82JQ+(LENOVO)";
	wishUrlStruct.plat_type = "pc";
	wishUrlStruct.gacha_type = "11";
	wishUrlStruct.end_id = "0";
}
