#ifndef PNGEXPORTER_H
#define PNGEXPORTER_H

#include "ExportCanvas.h"

class PNGExporter : public ExportCanvas
{
    public:
        PNGExporter();
        ~PNGExporter();

    private:    
        void prepareCanvas() override;
        void renderElements() override;
        void saveToFile() override;
};
#endif