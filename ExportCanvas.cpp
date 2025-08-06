#include "ExportCanvas.h"

ExportCanvas::ExportCanvas() : canvas(nullptr) {}

ExportCanvas::~ExportCanvas() {
    delete canvas;
}

void ExportCanvas::exportToFile() {
    if(canvas) {
        prepareCanvas();
        renderElements();
        saveToFile();
    }
}