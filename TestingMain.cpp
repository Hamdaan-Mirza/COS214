#include <iostream>
#include "Canvas.h"
#include "Memento.h"
#include "CareTaker.h"
#include "Shape.h"
#include "RectangleFactory.h"
#include "SquareFactory.h"
#include "PNGExporter.h"
#include "PDFExporter.h"

void tests() {
    Canvas canvas;
    canvas.setDimensions(100, 100);

    RectangleFactory rectFactory;
    SquareFactory squareFactory;

    Shape* shape1 = rectFactory.createShape();   
    Shape* shape2 = squareFactory.createShape();

    canvas.addShape(shape1);
    canvas.addShape(shape2);

    Memento* memento = canvas.captureCurrent();

    CareTaker caretaker;
    caretaker.storeMemento(memento);

    PNGExporter pngExporter;
     pngExporter.setCanvas(&canvas); 
    pngExporter.exportToFile();

    PDFExporter pdfExporter;
    pdfExporter.setCanvas(&canvas);
    pdfExporter.exportToFile();

    
}

int main() {
    try {
        tests();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

