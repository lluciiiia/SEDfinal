#include "TimeSlot.h"
#include <string>

using namespace std;

class TimeSlot {
private:
    string startTime;
    string endTime;

public:
    TimeSlot(const string& startTime, const string& endTime)
        : startTime(startTime), endTime(endTime) {
    }

    string getStartTime() const {
        return startTime;
    }

    string getEndTime() const {
        return endTime;
    }
};
