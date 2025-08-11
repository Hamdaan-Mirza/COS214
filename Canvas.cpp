#include "Canvas.h"

Canvas::Canvas() : height(0), width(0) {}

Canvas::~Canvas() {
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i]; 
    }
    shapes.clear();
}    

void Canvas::setDimensions(int width, int height) {
    this->width = width;
    this->height = height;
}

void Canvas::addShape(Shape* shape){
    shapes.push_back(shape);
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

// void Canvas::addShapes(const std::vector<Shape*>& newShapes) {
//     for (const auto& shape : newShapes) {
//         shapes.push_back(shape->clone());
//     }
// }

int Canvas::getHeight() const {
    return height;
}

int Canvas::getWidth() const {
    return width;
}

const std::vector<Shape*>& Canvas::getShapes() const {
    return shapes;
}
