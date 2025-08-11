#include "RectangleFactory.h"
#include "Rectangle.h"

Shape* RectangleFactory::createShape() {
    Shape* rect = new Rectangle(2, 1, "black", 0, 0);
    rect->setName("Rectangle");
    return rect;
}


void RectangleFactory::toString() {
    std::cout << "Created Rectangle Shape" << std::endl;
}