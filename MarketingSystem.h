#ifndef MARKETING_SYSTEM_H
#define MARKETING_SYSTEM_H

#include "Observer.h"
#include "Membership.h"
#include <string>

class MarketingSystem : public Observer {
private:
    std::string systemName;

public:
    MarketingSystem(const std::string& name);
    void update(const Membership* membership) override;
    void sendPromotionalEmail(const std::string& memberName, const std::string& offer);
    void generateReport(const Membership* membership);
};

#endif 