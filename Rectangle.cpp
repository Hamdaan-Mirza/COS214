#include "Rectangle.h"

Rectangle::Rectangle(int l, int w, string c, int px, int py) : Shape(l, w, c, px, py){
}

Shape* Rectangle::clone(){
    return new Rectangle(*this);
}

std::string Rectangle::getName() const {
    return name;
}

void Rectangle::setName(const std::string &name) {
    this->name = name;
}