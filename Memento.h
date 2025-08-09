#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"

class Memento
{
    public:
        Memento(vector<unique_ptr<Shape>> elements);
        vector<unique_ptr<Shape>> getShapes();

    private:    
        vector<unique_ptr<Shape>> shapes;
};
#endif