#ifndef CHATROOM_ITERATOR_H
#define CHATROOM_ITERATOR_H

/**
 * @file ChatRoomIterator.h
 * @brief It defines the ChatRoomIterator class with its functions for iterating over a collection of chat rooms.
 * @author Abdelrahman  - u24898008
 * @date 30-09-2025
 */

#include "Iterator.h"
#include <vector>

template <typename T>
/**
 * @class ChatRoomIterator
 * @brief Iterator for the ChatRoom class.
 * @details Implements the Iterator interface for iterating over chat rooms.
 */
class ChatRoomIterator : public Iterator<T> {
    public:
/**
 * @brief Constructor for ChatRoomIterator.
 * @param coll The collection of chat rooms to iterate over.
 */
    ChatRoomIterator(const std::vector<T>& coll) : collection(coll), currentPosition(0) {}
    
/**
 * @brief Resets the iterator to the first chat room.
 * @return void
 */
    void first() override {
        currentPosition = 0;
    }
/**
 * @brief Advances the iterator to the next chat room.
 * @return void
 */
    void next() override {
        if (!isDone()) {
            currentPosition++;
        }
    }
/**
 * @brief Checks if the iterator has reached the end of the collection.
 * @return True if the iterator is done, false otherwise.
 */
    bool isDone() const override {
        return currentPosition >= collection.size();
    }
/**
 * @brief Gets the current chat room.
 * @return The current chat room.
 */
    T currentItem() const override {
        if (!isDone()) {
            return collection[currentPosition];
        }
        return nullptr;
    }
private:
/**
 * @brief The collection of chat rooms.
 */
    const std::vector<T>& collection;
/** * @brief The current position of the iterator.
 */
    int currentPosition;
};

#endif