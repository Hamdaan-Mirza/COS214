#include "Square.h"

Square::Square(int l, int w, string c, int px, int py) : Shape(l, w, c, px, py)
{
}

Shape *Square::clone()
{
    return new Square(*this);
}

std::string Square::getName() const
{
    return name;
}

void Square::setName(const std::string &name)
{
    this->name = name;
}