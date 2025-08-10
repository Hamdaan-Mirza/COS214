#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"

class CareTaker
{
    public:
        CareTaker();
        Memento* getPrev();
        Memento* getNext();
        void storeMemento(unique_ptr<Memento> memento);

    private:    
        list<unique_ptr<Memento>> mementos;
        list<unique_ptr<Memento>>::iterator curr;      
};
#endif