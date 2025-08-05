#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <string>

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