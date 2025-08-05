#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"

class ShapeFactory {
    protected:
        virtual Shape* createShape();
        virtual void toString();
    public:
        ShapeFactory();
        virtual ~ShapeFactory();
};

#endif