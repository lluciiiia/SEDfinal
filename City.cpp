#include <map>
#include <string>
#include "City.h"

// Method to convert city information to string
string cityToString(City city) {
    static map<City, string> cityMap = {
        {City::Saigon, "Saigon"},
        {City::Hanoi, "Hanoi"}
    };

    auto it = cityMap.find(city);
    if (it != cityMap.end()) {
        return it->second;
    } else {
        return "Unknown"; // Handle unknown enum values
    }
}

// Method to convert string to city
City stringToCity(const std::string &cityStr)
{
    if (cityStr == "Saigon")
    {
        return City::Saigon;
    }
    else if (cityStr == "Hanoi")
    {
        return City::Hanoi;
    }
    return static_cast<City>(-1); // Invalid city, return -1
}
