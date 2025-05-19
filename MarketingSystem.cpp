#include "MarketingSystem.h"
#include <iostream>

MarketingSystem::MarketingSystem(const std::string& name) : systemName(name) {}

void MarketingSystem::update(const Membership* membership) {
    std::cout << "MarketingSystem " << systemName << " received update for member: " 
              << membership->getMemberName() << std::endl;
    
    // Check for new offers
    auto offers = membership->getOffers();
    if (!offers.empty()) {
        sendPromotionalEmail(membership->getMemberName(), offers.back());
    }
    
    generateReport(membership);
}

void MarketingSystem::sendPromotionalEmail(const std::string& memberName, const std::string& offer) {
    std::cout << "Sending promotional email to " << memberName 
              << " about offer: " << offer << std::endl;
}

void MarketingSystem::generateReport(const Membership* membership) {
    std::cout << "Generating marketing report for " << membership->getMemberName() << std::endl;
    std::cout << "Membership Type: " << membership->getMembershipType() << std::endl;
    std::cout << "Payment Status: " << (membership->getPaymentStatus() ? "Paid" : "Unpaid") << std::endl;
    std::cout << "Active Offers: " << membership->getOffers().size() << std::endl;
} 