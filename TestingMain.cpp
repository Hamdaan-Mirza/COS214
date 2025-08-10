#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <fstream>

#include "Canvas.h"
#include "Memento.h"
#include "Caretaker.h"
#include "ShapeFactory.h"
#include "Shape.h"
#include "ExportCanvas.h"
#include "PNGExporter.h"
#include "PDFExporter.h" 

void tests() {
    Canvas canvas;
    canvas.setDimensions(100, 100);
    
    auto shape1 = ShapeFactory::createShape("Rectangle", 10, 20, "red", 0, 0);
    auto shape2 = ShapeFactory::createShape("Square", 30, 40, "blue", 10, 10);
    
    canvas.addShape(std::move(shape1));
    canvas.addShape(std::move(shape2));
    
    Memento* memento = canvas.captureCurrent();
    
    CareTaker caretaker;
    caretaker.storeMemento(std::unique_ptr<Memento>(memento));
    
    PNGExporter pngExporter;
    pngExporter.exportToFile();
    
    PDFExporter pdfExporter;
    pdfExporter.exportToFile();
}

int main() {
    //try {
        tests();
    // } catch (const std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    //     return EXIT_FAILURE;
    // }
    return 0;
}

 