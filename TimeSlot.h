#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <string>
#include <sstream>
using namespace std;

class TimeSlot
{
private:
    string startTime;
    string endTime;

public:
    TimeSlot();
    TimeSlot(const string& startTime, const string& endTime);

    string getStartTime() const;
    string getEndTime() const;

    void setStartTime(string newStartTime);
    void setEndTime(string newEndTime); 

    void showInfo();
    bool isValidDateFormat(const std::string& date) const;
    bool isDateWithinTimeSlot(const string& date) const;

    bool operator==(const TimeSlot& other) const;
    string addDayToDate();
    bool isDateInRange(const string& date);
};

#endif
