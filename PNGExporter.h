#ifndef PNGEXPORTER_H
#define PNGEXPORTER_H

#include "ExportCanvas.h"

class PNGExporter : public ExportCanvas
{
    public:
        PNGExporter();
        ~PNGExporter();

    private:    
        void saveToFile() override;
};
#endif