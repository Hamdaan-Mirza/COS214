#include "CareTaker.h"

CareTaker::CareTaker()
{
    curr = mementos.end();
}

CareTaker::~CareTaker()
{
    for (int i = 0; i < mementos.size(); i++)
    {
        delete memento; 
    }
    mementos.clear();
}

Memento *CareTaker::getPrev()
{
    if (mementos.empty() || curr == mementos.begin())
    {
        return nullptr;
    }
    else
    {
        curr--;
    }
    return curr->get();
}

Memento *CareTaker::getNext()
{
    if (mementos.empty() || curr == prev(mementos.end()))
    {
        return nullptr;
    }
    else
    {
        curr++;
    }
    return curr->get();
}

void CareTaker::storeMemento(Memento* memento)
{
    if (!mementos.empty())
    {
        curr++;
        mementos.erase(curr, mementos.end());
    }
    mementos.push_back(move(memento));
    curr = prev(mementos.end());
}