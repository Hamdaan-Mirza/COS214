
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <string>


class Square : public Shape
{
    public:
        Square();
        Square(int l, int w, string c, int px, int py);
        Shape* clone() override;
};
#endif