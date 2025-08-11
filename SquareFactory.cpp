#include "SquareFactory.h"
#include "Square.h"

Shape* SquareFactory::createShape() {
    Shape* shape = new Square(2, 2, "black", 0, 0);
    shape->setName("Square");
    return shape;
}

void SquareFactory::toString() {
    std::cout << "Created Square Shape" << std::endl;
}