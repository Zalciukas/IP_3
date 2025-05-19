cmake_minimum_required(VERSION 3.10)
project(MembershipSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main application
add_executable(membership_system
    demo.cpp
    Membership.cpp
    BillingSystem.cpp
    MarketingSystem.cpp
    NotificationSystem.cpp
)

# Test executable
add_executable(notification_test
    test.cpp
    Membership.cpp
    BillingSystem.cpp
    MarketingSystem.cpp
    NotificationSystem.cpp
) 