#include "PNGExporter.h"

PNGExporter::PNGExporter() : ExportCanvas() {}

PNGExporter::~PNGExporter() {}

void PNGExporter::prepareCanvas() {
    Canvas* curr = getCanvas();
    if (!curr) return;
    curr->setDimensions(60, 60);
}

void PNGExporter::renderElements() {
    Canvas* curr = getCanvas();
    if (!curr) return;
    std::vector<Shape*> temp = curr->getShapes();
    for (int i = 0; i < temp.size(); i++) {
        curr->addShape(temp[i]->clone()); 
    }
}

void PNGExporter::saveToFile() {
    std::cout << "Saving canvas as a PNG." << std::endl;
}