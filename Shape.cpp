#include "Shape.h"

Shape::Shape(){
    length = 0;
    width = 0;
    color = "black";
    position_x = 0;
    position_y = 0;
}

Shape::Shape(int l, int w, string c, int px, int py){
    length = l;
    width = w;
    color = c;
    position_x = px;
    position_y = py;
}

int Shape::getLength() const {
    return length;
}

int Shape::getWidth() const {
    return width;
}

string Shape::getColor() const {
    return color;
}

int Shape::getPosX() const {
    return position_x;
}

int Shape::getPosY() const {
    return position_y;
}

