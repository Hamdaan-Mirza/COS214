#ifndef EXPORT_CANVAS_H
#define EXPORT_CANVAS_H

#include "Canvas.h"

class ExportCanvas
{
    public:
        ExportCanvas();
        virtual ~ExportCanvas();
        void exportToFile();
        virtual void prepareCanvas() = 0;
        virtual void renderElements() = 0;
        virtual void saveToFile() = 0;
        Canvas* getCanvas() const;
    private:    
        Canvas* canvas; 
};
#endif