#include "Canvas.h"

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