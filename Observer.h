#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer {
public:
    virtual ~Observer();
    virtual void update(const std::string& event, void* data) = 0;
};

#endif