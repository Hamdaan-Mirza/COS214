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

