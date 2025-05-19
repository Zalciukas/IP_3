#include "Membership.h"
#include <algorithm>

Membership::Membership(const std::string& name, const std::string& type)
    : memberName(name), membershipType(type), paymentStatus(false) {}

std::string Membership::getMemberName() const {
    return memberName;
}

std::string Membership::getMembershipType() const {
    return membershipType;
}

bool Membership::getPaymentStatus() const {
    return paymentStatus;
}

std::vector<std::string> Membership::getOffers() const {
    return offers;
}

void Membership::setMemberName(const std::string& name) {
    memberName = name;
    notify();
}

void Membership::setMembershipType(const std::string& type) {
    membershipType = type;
    notify();
}

void Membership::setPaymentStatus(bool status) {
    paymentStatus = status;
    notify();
}

void Membership::addOffer(const std::string& offer) {
    offers.push_back(offer);
    notify();
}

void Membership::removeOffer(const std::string& offer) {
    auto it = std::find(offers.begin(), offers.end(), offer);
    if (it != offers.end()) {
        offers.erase(it);
        notify();
    }
}

void Membership::attach(Observer* observer) {
    observers.push_back(observer);
}

void Membership::detach(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void Membership::notify() {
    // POLYMORPHISM: Iterating through Observer pointers and calling update()
    // Each pointer points to either a BillingSystem or MarketingSystem object
    // The correct update() implementation is called based on the actual object type
    for (auto observer : observers) {
        observer->update(this);
    }
}

Membership::~Membership() {
    observers.clear();
} 