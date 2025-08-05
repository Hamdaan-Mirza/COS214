#include "RectangleFactory.h"
#include "Rectangle.h"

Shape* RectangleFactory::createShape() {
    return new Rectangle();
}

void RectangleFactory::toString() {
    std::cout << "Created Rectangle Shape" << std::endl;
}