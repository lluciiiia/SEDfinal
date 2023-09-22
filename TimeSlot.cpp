#include "TimeSlot.h"
#include <string>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <sstream>

using namespace std;

// Constructors
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

// Getters
string TimeSlot::getStartTime() const
{
    return startTime;
}

string TimeSlot::getEndTime() const
{
    return endTime;
}

// Setters
void TimeSlot::setStartTime(string newStartTime)
{
    this->startTime = newStartTime;
}

void TimeSlot::setEndTime(string newEndTime)
{
    this->endTime = newEndTime;
}

// Method to display the information of the time slot
void TimeSlot::showInfo()
{
    cout << "Start time: " << startTime << "\nEnd time: " << endTime << "\n";
};

// To Make sure date follows format "xx/xx/xxxx". Example: "09/15/2023", 09 = month, 15 = date, 2023 = year
static const std::regex dateRegex("^(0[1-9]|1[0-2])/(0[1-9]|[1-2][0-9]|3[0-1])/(\\d{4})$");

// Method to compare the time slot to regex
bool TimeSlot::isValidDateFormat(const std::string &date) const
{
    return std::regex_match(date, dateRegex);
}

// Method to check if the date is in a valid format
bool TimeSlot::isDateWithinTimeSlot(const std::string &date) const
{
    // Check if the date has a valid format first
    if (!isValidDateFormat(date))
    {
        throw std::invalid_argument("Invalid date format");
    }

    return date >= startTime && date <= endTime;
}

// == Operator method
bool TimeSlot::operator==(const TimeSlot &other) const
{
    return this->startTime == other.startTime &&
           this->endTime == other.endTime;
}

// Method to add days to date
string TimeSlot::addDayToDate()
{
    try
    {
        stringstream ss(startTime);
        string token1, token2;
        std::string token;
        std::vector<std::string> tokens;
        int dayToAdd = stoi(endTime);

        while (std::getline(ss, token, '/'))
        {
            tokens.push_back(token);
        }

        if (tokens.size() != 2)
        {
            throw std::invalid_argument("Invalid date format");
        }

        int day = stoi(tokens[0]);
        int month = stoi(tokens[1]);

        int maxdayinMonth;
        if (month == 2)
        {
            maxdayinMonth = 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            maxdayinMonth = 30;
        }
        else
        {
            maxdayinMonth = 31;
        }

        day += dayToAdd;

        if (day > maxdayinMonth)
        {
            day = day - maxdayinMonth;
            month++;

            if (month > 12)
            {
                month = 1;
            }
        }

        string daystring = to_string(day);
        string monthString = to_string(month);

        if (daystring.length() == 1)
        {
            daystring = "0" + daystring;
        }

        if (monthString.length() == 1)
        {
            monthString = "0" + monthString;
        }

        return daystring + "/" + monthString;
    }
    catch (const std::exception &e)
    {
        cerr << "Error in addDayToDate: " << e.what() << endl;
        throw;
    }
}

// Method to check if the date is within the range
bool TimeSlot::isDateInRange(const string &date)
{
    int day, month;
    char slash;
    istringstream ss(date);
    ss >> day >> slash >> month;

    int startDay, startMonth;
    char slash2;
    istringstream ss1(startTime);
    ss1 >> startDay >> slash2 >> startMonth;

    int endDay, endMonth;
    char slash3;
    istringstream ss2(endTime);
    ss2 >> endDay >> slash3 >> endMonth;

    if (month < startMonth || month > endMonth)
    {
        return false;
    }

    if (month == startMonth && day < startDay)
    {
        return false;
    }

    if (month == endMonth && day > endDay)
    {
        return false;
    }

    return true;
}
