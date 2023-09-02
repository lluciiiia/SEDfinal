#include "TimeSlot.h"
#include <string>

using namespace std;

TimeSlot::TimeSlot(const string& startTime, const string& endTime)
    : startTime(startTime), endTime(endTime) {
}

string TimeSlot::getStartTime() const {
    return startTime;
}

string TimeSlot::getEndTime() const {
    return endTime;
}
