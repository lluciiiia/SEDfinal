#include "TimeSlot.h"
#include <string>
#include <iostream>
#include <regex>
#include <stdexcept>

using namespace std;


TimeSlot::TimeSlot()
{
    this->startTime = "";
    this->endTime = "";
}

TimeSlot::TimeSlot(const string &startTime, const string &endTime)
{
    this->startTime = startTime;
    this->endTime = endTime;
}

string TimeSlot::getStartTime() const
{
    return startTime;
}

string TimeSlot::getEndTime() const
{
    return endTime;
}

void TimeSlot::showInfo()
{
    cout << "Start time: " << startTime << "\nEnd time: " << endTime << "\n";
};

bool TimeSlot::isDateWithinTimeSlot(const std::string& date) const {
    // Check if the date has a valid format first
    if (!isValidDateFormat(date)) {
        throw std::invalid_argument("Invalid date format");
    }

    return date >= startTime && date <= endTime;
}


//Make sure date follows format "xx/xx/xxxx". Example: "09/15/2023", 09 = month, 15 = date, 2023 = year
static const std::regex dateRegex("^(0[1-9]|1[0-2])/(0[1-9]|[1-2][0-9]|3[0-1])/(\\d{4})$");

bool TimeSlot::isValidDateFormat(const std::string& date) const {
  return std::regex_match(date, dateRegex);
}


