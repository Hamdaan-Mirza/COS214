#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"

class Caretaker
{
    public:
        Caretaker();
        Memento* getMemento();
        void setMemento(Memento* other);

    private:    
        Memento* memento;
};
#endif