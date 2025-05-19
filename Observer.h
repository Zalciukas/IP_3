#ifndef OBSERVER_H
#define OBSERVER_H

class Membership;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const Membership* membership) = 0;
};

#endif 