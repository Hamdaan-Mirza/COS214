#ifndef ITERATOR_H
#define ITERATOR_H

/**
 * @file Iterator.h
 * @author Abdelrahman - u24898008
 * @brief It defines the Iterator class with its attributes and functions.
 * @date 30-09-2025
 */

template <typename T>
/**
 * @class Iterator
 * @brief Abstract base class for all iterators.
 * @details This class defines the interface for all iterators that want to traverse a collection.
 */
class Iterator
{
public:
/**
 * @brief Destructor for Iterator.
 */
    virtual ~Iterator(){};
/** @brief Resets the iterator to the first element.
 */
    virtual void first() = 0;
/** @brief Advances the iterator to the next element.
 */
    virtual void next() = 0;
/** @brief Checks if the iterator has reached the end of the collection.
 * @return true if the iterator has reached the end, false otherwise.
 */
    virtual bool isDone() const = 0;
/** @brief Returns the current element pointed to by the iterator.
 * @return The current element.
 */
    virtual T currentItem() const = 0;
};

#endif 