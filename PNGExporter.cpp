#include "PNGExporter.h"

PNGExporter::PNGExporter() : ExportCanvas() {}

PNGExporter::~PNGExporter() {}

void PNGExporter::prepareCanvas() {
    if (!canvas) return;
    canvas->setDimensions(60, 60);
}

void PNGExporter::renderElements() {
    if (!canvas) return;
    for (int i = 0; i < canvas->shapes.size(); i++) {
        canvas->addShape(make_unique<Shape>(*shape));
    }
}

void PNGExporter::saveToFile() {
    std::cout << "Saving canvas as a PNG." << std::endl;
}