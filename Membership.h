#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <string>
#include <vector>
#include "Observer.h"

class Membership {
private:
    std::string memberName;
    std::string membershipType;
    bool paymentStatus;
    std::vector<std::string> offers;
    std::vector<Observer*> observers;

public:
    Membership(const std::string& name, const std::string& type);
    
    // Getters
    std::string getMemberName() const;
    std::string getMembershipType() const;
    bool getPaymentStatus() const;
    std::vector<std::string> getOffers() const;

    // Setters
    void setMemberName(const std::string& name);
    void setMembershipType(const std::string& type);
    void setPaymentStatus(bool status);
    void addOffer(const std::string& offer);
    void removeOffer(const std::string& offer);

    // Observer pattern methods
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify();

    ~Membership();
};

#endif 