#ifndef CANVAS_H
#define CANVAS_H

#include "Shape.h"
#include "Memento.h"

class Canvas
{
    public:
        Canvas();
        ~Canvas();
        void setDimensions(int width, int height);
        void addShape(unique_ptr<Shape> shape);
        Memento* captureCurrent();
        void undoAction(Memento* prev);
        void redoAction(Memento* next);

    private:    
        vector<unique_ptr<Shape>> shapes;
        int height;
        int width;
};
#endif