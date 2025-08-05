#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <fstream>

class ShapeFactory {
    protected:
        virtual Shape* createShape();
        virtual void toString();
    public:
        ShapeFactory();
        virtual ~ShapeFactory();
};

#endif