#include <iostream>
#include "Canvas.h"
#include "Memento.h"
#include "CareTaker.h"
#include "Shape.h"
#include "RectangleFactory.h"
#include "SquareFactory.h"
#include "PNGExporter.h"
#include "PDFExporter.h"

// ...existing code...

void tests() {
    // Canvas test
    Canvas canvas;
    canvas.setDimensions(100, 100);
    std::cout << "Canvas created and dimensions set.\n";

    // RectangleFactory and Rectangle test
    RectangleFactory rectFactory;
    Shape* rect = rectFactory.createShape();
    rect->setName("TestRectangle");
    std::cout << "Rectangle created: " << rect->getName() << "\n";

    // SquareFactory and Square test
    SquareFactory squareFactory;
    Shape* square = squareFactory.createShape();
    square->setName("TestSquare");
    std::cout << "Square created: " << square->getName() << "\n";

    // TextboxFactory and Textbox test
    TextboxFactory textboxFactory;
    Shape* textbox = textboxFactory.createShape();
    textbox->setName("TestTextbox");
    std::cout << "Textbox created: " << textbox->getName() << "\n";

    // Add shapes to canvas
    canvas.addShape(rect);
    canvas.addShape(square);
    std::cout << "Shapes added to canvas.\n";

    // Memento and CareTaker test
    Memento* memento = canvas.captureCurrent();
    CareTaker caretaker;
    caretaker.storeMemento(memento);
    std::cout << "Canvas state captured and stored.\n";

    // PNGExporter test
    PNGExporter pngExporter;
    pngExporter.setCanvas(&canvas); 
    pngExporter.exportToFile();
    std::cout << "Canvas exported to PNG.\n";

    // PDFExporter test
    PDFExporter pdfExporter;
    pdfExporter.setCanvas(&canvas);
    pdfExporter.exportToFile();
    std::cout << "Canvas exported to PDF.\n";


    // Clone test
    Shape* rectClone = rect->clone();
    rectClone->setName("ClonedRectangle");
    std::cout << "Rectangle cloned: " << rectClone->getName() << "\n";

    Shape* squareClone = square->clone();
    squareClone->setName("ClonedSquare");
    std::cout << "Square cloned: " << squareClone->getName() << "\n";

    Shape* textboxClone = textbox->clone();
    textboxClone->setName("ClonedTextbox");
    std::cout << "Textbox cloned: " << textboxClone->getName() << "\n";

    // Clean up
    // delete rect;
    // delete square;
    // // delete textbox;
    // delete rectClone;
    // delete squareClone;
    // delete textboxClone;
    // Memento may need deletion depending on ownership
}

// ...existing code...

int main() {
    try {
        tests();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}

