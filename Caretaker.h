#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <list>

class CareTaker
{
    public:
        CareTaker();
        ~CareTaker();
        Memento* getPrev();
        Memento* getNext();
        void storeMemento(Memento* memento);

    private:
        std::list<Memento*> mementos;
        std::list<Memento*>::iterator curr;
};
#endif