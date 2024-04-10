#include "Data.h"

Data::Data(int customerNumber, int serviceTime) : customerNumber(customerNumber), serviceTime(serviceTime), totalTime(0) {}

Data::~Data() {}

int Data::getCustomerNumber() const {
    return customerNumber;
}

int Data::getServiceTime() const {
    return serviceTime;
}

int Data::getTotalTime() const {
    return totalTime;
}

void Data::setTotalTime(int totalTime) {
    this->totalTime = totalTime;
}
