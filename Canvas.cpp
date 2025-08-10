#include "Canvas.h"

Canvas::Canvas() : height(0), width(0) {}

Canvas::~Canvas() {}

void Canvas::setDimensions(int width, int height) {
    this->width = width;
    this->height = height;
}

void Canvas::addShape(unique_ptr<Shape> shape){
    shapes.push_back(move(shape));
}

Memento* Canvas::captureCurrent(){
    return new Memento(shapes);
} 
void Canvas::undoAction(Memento* prev){
    shapes = prev->getShapes();
}
void Canvas::redoAction(Memento* next){
    shapes = next->getShapes();
}