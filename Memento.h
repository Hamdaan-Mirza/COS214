#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"

class Memento
{
    public:
        Memento();
        ~Memento();
        Memento(const std::vector<Shape*>& elements);
        std::vector<Shape*> getShapes();

    private:    
        std::vector<Shape*> shapes;
};
#endif