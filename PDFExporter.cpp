#include "PDFExporter.h"

PDFExporter::PDFExporter() : ExportCanvas() {}

PDFExporter::~PDFExporter() {}

void PDFExporter::prepareCanvas() {
    Canvas* curr = getCanvas();
    if (!curr) return;
    curr->setDimensions(60, 60);
    std::cout << "Preparing canvas for PDF export..." << std::endl;
}

void PDFExporter::renderElements() {
    Canvas* curr = getCanvas();
    if (!curr) return;
    std::vector<Shape*> temp = curr->getShapes();
    for (int i = 0; i < temp.size(); i++) {
        curr->addShape(temp[i]->clone());
        std::cout << "Rendering shape at position (" << temp[i]->getPosX() << ", " << temp[i]->getPosY() << ") with color " 
        << temp[i]->getColor() << "." << std::endl;
    }
}

void PDFExporter::saveToFile() {
    std::cout << "Saving canvas as a PDF." << std::endl;
}