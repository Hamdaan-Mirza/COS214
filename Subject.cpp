    #include "Subject.h"

    /**
     * @file Subject.cpp
     * @author Abdelrahman - u24898008
     * @brief It implements the Subject class with its attributes and functions.
     * @date 30-09-2025
     */

    Subject::~Subject() {
        observers.clear();
    }

    void Subject::attach(Observer* observer) {
        observers.push_back(observer);
    }

    void Subject::detach(Observer* observer) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void Subject::notify(const std::string& eventType, void* data) {
        for (auto observer : observers) {
            observer->update(eventType, data);
        }
    }