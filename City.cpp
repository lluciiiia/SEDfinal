#include <map>
#include <string>
#include "City.h"

// Function to convert City enum to string
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