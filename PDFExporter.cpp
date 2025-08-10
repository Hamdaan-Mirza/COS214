#include "PDFExporter.h"

PDFExporter::PDFExporter() : ExportCanvas() {}

PDFExporter::~PDFExporter() {}

void PDFExporter::prepareCanvas() {
    if (!canvas) return;
    canvas->setDimensions(60, 60);
}

void PDFExporter::renderElements() {
    if (!canvas) return;
    for (int i = 0; i < canvas->shapes.size(); i++) {
        canvas->addShape(make_unique<Shape>(*canvas->shapes[i]));
    }
}

void PDFExporter::saveToFile() {
    std::cout << "Saving canvas as a PDF." << std::endl;
}