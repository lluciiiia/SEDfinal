#include "TimeSlot.h"
#include <string>
#include <iostream>

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
