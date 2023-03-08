#include "CTest.h"
#include "nlohmann/json.hpp"
#include <iostream>
namespace ns {
  // a simple struct to model a person
  struct person {
    std::string name;
    std::string address;
    int age;
  };

  void to_json(nlohmann::json& j, const person& p) {
    j = nlohmann::json{ {"name", p.name}, {"address", p.address}, {"age", p.age} };
  }

  void from_json(const nlohmann::json& j, person& p) {
    j.at("name").get_to(p.name);
    j.at("address").get_to(p.address);
    j.at("age").get_to(p.age);
  }
}
namespace ns {

}

CTest::CTest()
{

}

CTest::~CTest()
{

}

void CTest::initTestCase()
{
  //È¥ºó×ºÃû

// create a person
  ns::person p{ "Ned Flanders", "744 Evergreen Terrace", 60 };

  // conversion: person -> json
  nlohmann::json j = p;

  std::cout << j << std::endl;
  // {"address":"744 Evergreen Terrace","age":60,"name":"Ned Flanders"}

  // conversion: json -> person
  auto p2 = j.get<ns::person>();
}

void CTest::cleanupTestCase()
{
}

void CTest::init()
{
}

void CTest::cleanup()
{
}

void CTest::test_case1()
{


	QVERIFY(1==1);
}
