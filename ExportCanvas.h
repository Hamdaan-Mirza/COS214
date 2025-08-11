#ifndef EXPORT_CANVAS_H
#define EXPORT_CANVAS_H

#include "Canvas.h"

class ExportCanvas
{
    public:
        ExportCanvas();
        virtual ~ExportCanvas();
        void exportToFile();
        Canvas* getCanvas() const;
        void setCanvas(Canvas* canvas);
    private:    
        Canvas* canvas; 
        virtual void prepareCanvas() = 0;
        virtual void renderElements() = 0;
        virtual void saveToFile() = 0;
};
#endif