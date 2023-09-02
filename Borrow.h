#include <string>
#include "TimeSlot.h"

using namespace std;

class Borrow {
private:
    TimeSlot timeSlot;
    string username;
    int motorbikeId;
    double price;

public:
    Borrow(TimeSlot timeSlot, string username, int motorbikeId, double price)
        : timeSlot(timeSlot), username(username), motorbikeId(motorbikeId), price(price) {}

    TimeSlot getTimeSlot() const {
        return timeSlot;
    }

    string getUsername() const {
        return username;
    }

    int getMotorbikeID() const {
        return motorbikeId;
    }

    double getPrice() const {
        return price;
    }

    // TODO: Add setters -> update the whole h file.
};