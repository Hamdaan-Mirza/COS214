
#ifndef TEXTBOXFACTORY_H
#define TEXTBOXFACTORY_H

#include "ShapeFactory.h"
#include "Shape.h"

class TextboxFactory : public ShapeFactory {
    public:
        Shape* createShape() override;
        void toString() override;
        TextboxFactory();
        ~TextboxFactory();
};

#endif