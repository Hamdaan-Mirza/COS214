#include "ChatRoomIterator.h"

ChatRoomIterator::ChatRoomIterator(const std::vector<T> &coll) {
    collection = coll;
    currentPosition = 0;
}

void ChatRoomIterator::first()
{
    currentPosition = 0;
}

void ChatRoomItertor::next() 
    {
        if (!isDone())
        {
            currentPosition++;
        }
    }

        bool isDone() const 
    {
        return currentPosition >= collection.size();
    }

        T currentItem() const 
    {
        if (!isDone())
        {
            return collection[currentPosition];
        }
        return nullptr; // or throw an exception
    }
