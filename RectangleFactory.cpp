#include "RectangleFactory.h"
#include "Rectangle.h"

Shape* RectangleFactory::createShape() {
    return new Rectangle(2, 1, "black", 0, 0);
}

void RectangleFactory::toString() {
    std::cout << "Created Rectangle Shape" << std::endl;
}