#ifndef TEXTBOXFACTORY_H
#define TEXTBOXFACTORY_H

#include "ShapeFactory.h"

class TextboxFactory : public ShapeFactory {
    public:
        Shape* createShape() override;
        void toString() override;
        TextboxFactory();
        virtual ~TextboxFactory();
};
#endif