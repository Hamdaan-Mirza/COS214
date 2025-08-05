#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <fstream>

#include "Shape.h"

class ShapeFactory {
    protected:
        virtual Shape* createShape() = 0;
        virtual void toString() = 0;
    public:
        ShapeFactory();
        virtual ~ShapeFactory();
};

#endif