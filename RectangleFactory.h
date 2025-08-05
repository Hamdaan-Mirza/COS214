#ifndef RECTANGLE_FACTORY_H
#define RECTANGLE_FACTORY_H

#include "ShapeFactory.h"

class RectangleFactory : public ShapeFactory {
    public:
        RectangleFactory();
        ~RectangleFactory();
        Shape* createShape() override;
        void toString() override;
};

#endif