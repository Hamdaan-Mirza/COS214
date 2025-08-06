#include "TextboxFactory.h"
#include "Textbox.h"

Shape *TextboxFactory::createShape()
{
    return new Textbox(2, 1, "black", 0, 0, "...");
}

void TextboxFactory::toString()
{
    std::cout << "Created Textbox Shape" << std::endl;
}