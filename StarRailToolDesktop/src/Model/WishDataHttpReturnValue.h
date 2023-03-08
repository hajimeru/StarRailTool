#pragma once
#include <string>
#include <vector>

struct WishItem
{
  std::string uid;
  std::string gacha_id;
  std::string gacha_type;
  std::string item_id;
  std::string count;
  std::string time;
  std::string name;
  std::string lang;
  std::string item_type;
  std::string rank_type;
  std::string id;
};

struct WishaHttpData
{
  std::string page;
  std::string size;
  std::vector<WishItem> list;
};


struct WishDataHttpReturnValue
{
  int retcode;
  std::string message;
  WishaHttpData data;
};

