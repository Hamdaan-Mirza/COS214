#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"
#include <string>

class Memento
{
    public:
        Memento(Shape* elements);
        Shape* getShapes();

    private:    
        Shape* shapes;
};
#endif