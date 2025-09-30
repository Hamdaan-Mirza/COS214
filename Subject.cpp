    #include "Subject.h"

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