#ifndef CHATOBSERVERS_H
#define CHATOBSERVERS_H

#include "Observer.h"  
#include "ChatRoom.h"  
#include <iostream>

/**
 * @brief 
 * @details 
 */
class ActivityObserver : public Observer {
public:
/**
 * @brief 
 * @param event 
 * @param data 
 * @return 
 */
    void update(const std::string& event, void* data) override;
};

/**
 * @brief 
 * @details 
 */
class StatisticsObserver : public Observer {
private:
    int numUsers;
    int numMessages;
    
public:
    StatisticsObserver();
/**
 * @brief 
 * @param event 
 * @param data 
 * @return 
 */
    void update(const std::string& event, void* data) override;
};

/**
 * @brief 
 * @details 
 */
class AdminObserver : public Observer {
public:
/**
 * @brief 
 * @param event 
 * @param data 
 * @return 
 */
    void update(const std::string& event, void* data) override;
};

#endif