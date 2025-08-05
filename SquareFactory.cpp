#include "SquareFactory.h"
#include "Square.h"

Shape* SquareFactory::createShape() {
    return new Square();
}

void SquareFactory::toString() {
    std::cout << "Created Square Shape" << std::endl;
}