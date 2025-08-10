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
        void addShape(Shape* shape);
        Memento* captureCurrent();
        void undoAction(Memento* prev);
        void redoAction(Memento* next);
        // void addShapes(const std::vector<Shape*>& newShapes);
        int getHeight() const;
        int getWidth() const;
        const std::vector<Shape*>& getShapes() const;

    private:    
        std::vector<Shape*> shapes;
        int height;
        int width;
};
#endif