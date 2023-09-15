#ifndef CITY_H
#define CITY_H
#include <map>
#include <string>

using namespace std;

enum class City
{
    Saigon,
    Hanoi
};

std::string cityToString(City city);
City stringToCity(const std::string &cityStr);

#endif

