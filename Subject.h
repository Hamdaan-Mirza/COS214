#ifndef SUBJECT_H
#define SUBJECT_H

/**
 * @file Subject.h
 * @author Abdelrahman - u24898008
 * @brief It defines the Subject class with its attributes and functions.
 * @date 30-09-2025
 */

#include "Observer.h"
#include <vector>

/**
 * @brief Forward declaration of Observer class to avoid circular dependency.
 */
class Observer;

/**
 * @class Subject
 * @brief It defines the Subject class with its attributes and functions.
 * @details The Subject class is responsible for managing a list of observers and notifying them of any changes.
 */
class Subject
{
public:
/**
 * @brief Destructor for Subject.
 */
    virtual ~Subject();
/**
 * @brief Attaches an observer to the subject.
 * @param observer The observer to attach.
 */
    virtual void attach(Observer *observer);
/**
 * @brief Detaches an observer from the subject.
 * @param observer The observer to detach.
 */
    virtual void detach(Observer *observer);
/**
 * @brief Notifies all observers of a change.
 * @param event The event that occurred.
 * @param data The data associated with the event.
 */
    virtual void notify(const std::string &event, void *data);

private:
/**
 * @brief The list of observers attached to the subject.
 */
    std::vector<Observer *> observers;
};

#endif