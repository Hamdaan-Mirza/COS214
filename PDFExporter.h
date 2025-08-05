#ifndef PDFEXPORTER_H
#define PDFEXPORTER_H

#include "ExportCanvas.h"

class PDFExporter : public ExportCanvas
{
    public:
        PDFExporter();
        ~PDFExporter();

    private:    
        void saveToFile() override;
};
#endif