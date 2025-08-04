#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>


class Rectangle : public Shape
{
    public:
        Rectangle(int l, int w, string c, int px, int py);
        Shape* clone();
};
#endif