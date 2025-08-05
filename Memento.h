#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"

class Memento
{
    public:
        Memento(Shape* elements);
        Shape* getShapes();

    private:    
        Shape* shapes;
};
#endif