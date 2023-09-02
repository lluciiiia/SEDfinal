#ifndef REQUEST_H
#define REQUEST_H
#include "User.cpp"
#include "Motorbike.cpp"
#include "TimeSlot.cpp"
#include "RequestStatus.cpp"


class Request {
private:
    User requester;
    Motorbike motorbike;
    RequestStatus status;
    TimeSlot timeSlot;

public:
    Request(User requester, Motorbike motorbike, TimeSlot timeSlot)
        : requester(requester), motorbike(motorbike), status(RequestStatus::PENDING), timeSlot(timeSlot) {
    }

    User getRequester() const {
        return requester;
    }

    Motorbike getMotorbike() const {
        return motorbike;
    }

    RequestStatus getStatus() const {
        return status;
    }

    void setStatus(RequestStatus status) {
        status = status;
    }

    TimeSlot getTimeSlot() const {
        return timeSlot;
    }
};


#endif