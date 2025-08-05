#ifndef SQUAREFACTORY_H
#define SQUAREFACTORY_H

#include "ShapeFactory.h"
#include "Shape.h"

class SquareFactory : public ShapeFactory {
    public:
        Shape* createShape() override;
        void toString() override;
        SquareFactory();
        virtual ~SquareFactory();
};

#endif 