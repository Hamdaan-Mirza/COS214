#ifndef CHATOBSERVERS_H
#define CHATOBSERVERS_H

#include "Observer.h"  
#include "ChatRoom.h"  
#include <iostream>

class ActivityObserver : public Observer {
public:
    void update(const std::string& event, void* data) override;
};

class StatisticsObserver : public Observer {
private:
    int numUsers;
    int numMessages;
    
public:
    StatisticsObserver();
    void update(const std::string& event, void* data) override;
};

class AdminObserver : public Observer {
public:
    void update(const std::string& event, void* data) override;
};

#endif