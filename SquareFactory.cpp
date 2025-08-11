#include "SquareFactory.h"
#include "Square.h"

Shape* SquareFactory::createShape() {
    return new Square(2, 2, "black", 0, 0);
}

void SquareFactory::toString() {
    std::cout << "Created Square Shape" << std::endl;
}