#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>

class Observer;

class Subject
{
public:
    virtual ~Subject();
    virtual void attach(Observer *observer);
    virtual void detach(Observer *observer);
    virtual void notify(const std::string &eventType, void *data = nullptr);

private:
    std::vector<Observer *> observers;
};

#endif