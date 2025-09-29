#ifndef CHATROOM_ITERATOR_H
#define CHATROOM_ITERATOR_H

#include "Iterator.h"
#include <vector>

template <typename T>
class ChatRoomIterator : public Iterator<T> {
    public:
    ChatRoomIterator(const std::vector<T>& coll)  {
        collection = coll;
        currentPosition = 0;
    }
    void first() override {
        currentPosition = 0;
    }
    void next() override {
        if (!isDone()) {
            currentPosition++;
        }
    }
    bool isDone() const override {
        return currentPosition >= collection.size();
    }
    T currentItem() const override {
        if (!isDone()) {
            return collection[currentPosition];
        }
        return nullptr;
    }
private:
    const std::vector<T>& collection;
    size_t currentPosition;
};

#endif