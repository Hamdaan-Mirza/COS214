#ifndef PDFEXPORTER_H
#define PDFEXPORTER_H

#include "ExportCanvas.h"

class PDFExporter : public ExportCanvas
{
    public:
        PDFExporter();
        ~PDFExporter();

    private:    
        void prepareCanvas() override;
        void renderElements() override;
        void saveToFile() override;
};
#endif