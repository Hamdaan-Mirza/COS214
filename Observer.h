#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @file Observer.h
 * @brief It defines the Observer class with its attributes and functions.
 * @author Abdelrahman - u24898008
 * @date 30-09-2025
 */

#include <string>

/**
 * @class Observer
 * @brief Abstract base class for all observers.
 * @details This class defines the interface for all observers that want to be notified of changes in the subject.
 */
class Observer {
public:
/**
 * @brief Destructor for Observer.
 */
    virtual ~Observer();
/**
 * @brief Updates the observer with the given event and data.
 * @param event The event that occurred.
 * @param data The data associated with the event.
 */
    virtual void update(const std::string& event, void* data) = 0;
};

#endif