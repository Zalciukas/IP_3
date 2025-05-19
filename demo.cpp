#include "Membership.h"
#include "BillingSystem.h"
#include "MarketingSystem.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printHeader() {
    cout << string(50, '=') << endl;
    cout << setw(35) << "MEMBERSHIP MANAGEMENT SYSTEM" << endl;
    cout << string(50, '=') << endl << endl;
}

void printMenu() {
    cout << "Available Actions:" << endl;
    cout << "1. View Member Details" << endl;
    cout << "2. Update Member Name" << endl;
    cout << "3. Update Membership Type" << endl;
    cout << "4. Update Payment Status" << endl;
    cout << "5. Add Offer" << endl;
    cout << "6. Remove Offer" << endl;
    cout << "7. View All Offers" << endl;
    cout << "0. Exit" << endl;
    cout << "\nEnter your choice: ";
}

void displayMemberDetails(const Membership& membership) {
    cout << "\n=== Member Details ===" << endl;
    cout << "Name: " << membership.getMemberName() << endl;
    cout << "Membership Type: " << membership.getMembershipType() << endl;
    cout << "Payment Status: " << (membership.getPaymentStatus() ? "Paid" : "Unpaid") << endl;
    cout << "Active Offers: " << membership.getOffers().size() << endl;
}

void updateMemberName(Membership& membership) {
    cout << "\nCurrent Member Name: " << membership.getMemberName() << endl;
    cout << "Enter new name: ";
    
    string newName;
    getline(cin, newName);
    
    if (newName.empty()) {
        cout << "Name cannot be empty!" << endl;
        return;
    }
    
    membership.setMemberName(newName);
    cout << "Member name updated successfully!" << endl;
}

void updateMembershipType(Membership& membership) {
    cout << "\nAvailable Membership Types:" << endl;
    cout << "1. Basic" << endl;
    cout << "2. Premium" << endl;
    cout << "3. VIP" << endl;
    cout << "Enter new type (1-3): ";
    
    string input;
    getline(cin, input);
    
    int choice;
    try {
        choice = stoi(input);
    } catch (const exception&) {
        cout << "Invalid input! Please enter a number between 1 and 3." << endl;
        return;
    }
    
    string newType;
    switch(choice) {
        case 1: newType = "Basic"; break;
        case 2: newType = "Premium"; break;
        case 3: newType = "VIP"; break;
        default: 
            cout << "Invalid choice! Please enter a number between 1 and 3." << endl;
            return;
    }
    
    membership.setMembershipType(newType);
    cout << "Membership type updated successfully!" << endl;
}

void updatePaymentStatus(Membership& membership) {
    cout << "\nCurrent Payment Status: " 
              << (membership.getPaymentStatus() ? "Paid" : "Unpaid") << endl;
    cout << "Update to (1 for Paid, 0 for Unpaid): ";
    
    string input;
    getline(cin, input);
    
    bool newStatus;
    if (input == "1") {
        newStatus = true;
    } else if (input == "0") {
        newStatus = false;
    } else {
        cout << "Invalid choice! Please enter 0 or 1." << endl;
        return;
    }
    
    membership.setPaymentStatus(newStatus);
    cout << "Payment status updated successfully!" << endl;
}

void addOffer(Membership& membership) {
    cout << "\nEnter new offer description: ";
    string offer;
    getline(cin, offer);
    
    if (offer.empty()) {
        cout << "Offer description cannot be empty!" << endl;
        return;
    }
    
    membership.addOffer(offer);
    cout << "Offer added successfully!" << endl;
}

void removeOffer(Membership& membership) {
    auto offers = membership.getOffers();
    if (offers.empty()) {
        cout << "\nNo offers available to remove!" << endl;
        return;
    }
    
    cout << "\nAvailable Offers:" << endl;
    for (size_t i = 0; i < offers.size(); ++i) {
        cout << (i + 1) << ". " << offers[i] << endl;
    }
    
    cout << "Enter offer number to remove: ";
    string input;
    getline(cin, input);
    
    size_t choice;
    try {
        choice = stoul(input);
    } catch (const exception&) {
        cout << "Invalid input! Please enter a valid offer number." << endl;
        return;
    }
    
    if (choice > 0 && choice <= offers.size()) {
        membership.removeOffer(offers[choice - 1]);
        cout << "Offer removed successfully!" << endl;
    } else {
        cout << "Invalid choice! Please enter a number between 1 and " << offers.size() << "." << endl;
    }
}

void displayOffers(const Membership& membership) {
    auto offers = membership.getOffers();
    if (offers.empty()) {
        cout << "\nNo active offers!" << endl;
        return;
    }
    
    cout << "\n=== Active Offers ===" << endl;
    for (size_t i = 0; i < offers.size(); ++i) {
        cout << (i + 1) << ". " << offers[i] << endl;
    }
}

int main() {
    Membership membership("Jonas Bulvinis", "Premium");
    
    // POLYMORPHISM: Creating derived class objects (BillingSystem and MarketingSystem)
    BillingSystem billing("MainBilling");
    MarketingSystem marketing("MainMarketing");
    
    // POLYMORPHISM: Using base class (Observer) pointers to store
    membership.attach(&billing);
    membership.attach(&marketing);
    
    bool running = true;
    
    while (running) {
        clearScreen();
        printHeader();
        displayMemberDetails(membership);
        cout << endl;
        printMenu();
        
        string input;
        getline(cin, input);
        
        int choice;
        try {
            choice = stoi(input);
        } catch (const exception&) {
            cout << "Invalid input! Please enter a number between 0 and 7." << endl;
            cout << "\nPress Enter to continue...";
            cin.get();
            continue;
        }
        
        switch (choice) {
            case 0:
                running = false;
                break;
            case 1:
                displayMemberDetails(membership);
                break;
            case 2:
                updateMemberName(membership);
                break;
            case 3:
                updateMembershipType(membership);
                break;
            case 4:
                updatePaymentStatus(membership);
                break;
            case 5:
                addOffer(membership);
                break;
            case 6:
                removeOffer(membership);
                break;
            case 7:
                displayOffers(membership);
                break;
            default:
                cout << "Invalid choice! Please enter a number between 0 and 7." << endl;
        }
        
        // POLYMORPHISM: When notify() is called in any of the setter methods, it calls update() on each observer. 
        if (running) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
    
    cout << "\nThank you for using the Membership Management System!" << endl;
    return 0;
} 