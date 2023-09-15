#ifndef REQUESTSTATUS_H
#define REQUESTSTATUS_H

enum class RequestStatus {
    PENDING,
    ACCEPTED,
    REJECTED
};

std::string statusToString(RequestStatus status);

#endif