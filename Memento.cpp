#include "Memento.h"

Memento::Memento(vector<unique_ptr<Shape>> elements){
    shapes = elements;
}

vector<unique_ptr<Shape>> Memento::getShapes(){
    return shapes;
}