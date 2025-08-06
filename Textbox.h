#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"

class Textbox : public Shape
{
public:
    Textbox(int l, int w, string c, int px, int py, string t);
    Shape *clone();

private:
    string text;
};

#endif