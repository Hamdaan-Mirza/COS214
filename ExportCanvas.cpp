#include "ExportCanvas.h"

ExportCanvas::ExportCanvas() : canvas(nullptr) {}

ExportCanvas::~ExportCanvas() {
    // delete canvas;
}

void ExportCanvas::exportToFile() {
    if(canvas) {
        prepareCanvas();
        renderElements();
        saveToFile();
    }
}

Canvas* ExportCanvas::getCanvas() const {
    return canvas;
}

void ExportCanvas::setCanvas(Canvas* canvas) {
    this->canvas = canvas;
}