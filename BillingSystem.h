#ifndef BILLING_SYSTEM_H
#define BILLING_SYSTEM_H

#include "Observer.h"
#include "Membership.h"
#include <string>

class BillingSystem : public Observer {
private:
    std::string systemName;

public:
    BillingSystem(const std::string& name);
    void update(const Membership* membership) override;
    void sendInvoice(const std::string& memberName, double amount);
};

#endif 