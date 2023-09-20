#include <map>
#include <string>
#include "Request.h"

string statusToString(RequestStatus status) {
    static map<RequestStatus, string> statusMap = {
        {RequestStatus::PENDING, "Pending"},
        {RequestStatus::ACCEPTED, "Accepted"},
        {RequestStatus::REJECTED, "Rejected"},
    };

    auto it = statusMap.find(status);
    if (it != statusMap.end()) {
        return it->second;
    } else {
        return "Unknown"; // Handle unknown enum values
    }
}