#include "BillingSystem.h"
#include <iostream>

BillingSystem::BillingSystem(const std::string& name) : systemName(name) {}

void BillingSystem::update(const Membership* membership) {
    std::cout << "BillingSystem " << systemName << " received update for member: " 
              << membership->getMemberName() << std::endl;
    
    if (!membership->getPaymentStatus()) {
        sendInvoice(membership->getMemberName(), 99.99); // Example amount, TODO: create baby classes for different membership types
    }
}

void BillingSystem::sendInvoice(const std::string& memberName, double amount) {
    std::cout << "Sending invoice to " << memberName << " for amount: $" << amount << std::endl;
} 