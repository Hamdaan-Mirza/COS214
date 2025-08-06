#ifndef CANVAS_H
#define CANVAS_H

#include "Shape.h"
#include "Memento.h"

class Canvas
{
    public:
        Canvas();
        ~Canvas();
        Memento* captureCurrent();
        void undoAction(Memento* prev);

    private:    
        Shape* shapes;
};
#endif