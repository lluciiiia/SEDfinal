#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <string>

using namespace std;

class TimeSlot
{
private:
    string startTime;
    string endTime;

public:
    TimeSlot();
    TimeSlot(const string &startTime, const string &endTime);
    TimeSlot(const string &startTime);

    string getStartTime() const;
    string getEndTime() const;

    void showInfo();

};

#endif
