#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"

class Textbox : public Shape
{
public:
    Textbox(int l, int w, string c, int px, int py, string t);
    Shape *clone();
    std::string getName() const override;
    void setName(const std::string &name) override;
    private:
        std::string name;
        std::string text; 
};
#endif