#include "NotificationSystem.h"
#include "Membership.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <string>

using namespace std;

void testNotificationSystem() {
    // Test constructor
    cout << "\n=== Testing Constructor ===" << endl;
    NotificationSystem notificationSystem("TestSystem");
    cout << "Constructor test passed!" << endl;
    
    // Test sendNotification
    cout << "\n=== Testing sendNotification method ===" << endl;
    stringstream output;
    auto old_cout = cout.rdbuf(output.rdbuf());
    
    notificationSystem.sendNotification("John Smith", "Welcome to our service!");
    
    cout.rdbuf(old_cout);
    string result = output.str();
    cout << result;  // Show the output
    
    assert(result.find("[TestSystem]") != string::npos && "System name not found in output");
    assert(result.find("John Smith") != string::npos && "Member name not found in output");
    assert(result.find("Welcome to our service!") != string::npos && "Message not found in output");
    cout << "sendNotification test passed!" << endl;
    
    // Test update method
    cout << "\n=== Testing update method ===" << endl;
    output.str("");  // Clear the stream
    old_cout = cout.rdbuf(output.rdbuf());
    
    Membership testMembership("Jane Smith", "Premium");
    notificationSystem.update(&testMembership);
    
    cout.rdbuf(old_cout);
    result = output.str();
    cout << result;  // Show the output
    
    assert(result.find("[TestSystem]") != string::npos && "System name not found in update output");
    assert(result.find("Jane Smith") != string::npos && "Member name not found in update output");
    assert(result.find("Membership update") != string::npos && "Update message not found in update output");
    cout << "update test passed!" << endl;
}

int main() {
    cout << "Starting NotificationSystem tests..." << endl;
    testNotificationSystem();
    cout << "\n=== All tests passed successfully! ===" << endl;
    return 0;
} 