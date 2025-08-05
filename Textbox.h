#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"
#include <string>


class Textbox : public Shape
{
    public:
        Textbox();
        Textbox(int l, int w, string c, int px, int py, string t);
        Shape* clone();
    private:
        string text;
};
#endif