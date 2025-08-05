#ifndef SQUAREFACTORY_H
#define SQUAREFACTORY_H

#include "ShapeFactory.h"

class SquareFactory : public ShapeFactory {
    public:
        SquareFactory();
        ~SquareFactory();
        Shape* createShape() override;
        void toString() override;
};

#endif 