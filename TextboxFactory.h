#ifndef TEXTBOXFACTORY_H
#define TEXTBOXFACTORY_H

#include "ShapeFactory.h"
#include "Shape.h"

class TextboxFactory : public ShapeFactory {
    public:
        TextboxFactory();
        ~TextboxFactory();
        Shape* createShape() override;
        void toString() override;
};
#endif