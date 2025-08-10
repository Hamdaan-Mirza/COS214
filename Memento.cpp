#include "Memento.h"


Memento::Memento() {}

Memento::~Memento() {
    for (auto& shape : shapes) {
        delete shape;  
    }
    shapes.clear();
}

std::vector<Shape*> Memento::getShapes() {
    return shapes;
}

Memento::Memento(const std::vector<Shape*>& elements){
    shapes = elements;
}
