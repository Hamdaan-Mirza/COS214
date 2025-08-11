#include "Textbox.h"

Textbox::Textbox(int l, int w, string c, int px, int py, string t) : Shape(l, w, c, px, py)
{
    text = t;
}

Shape *Textbox::clone()
{
    return new Textbox(*this);
}

std::string Textbox::getName() const
{
    return name;
}

void Textbox::setName(const std::string &name)
{
    this->name = name;
}