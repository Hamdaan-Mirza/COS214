#include "TextboxFactory.h"
#include "Textbox.h"

Shape *TextboxFactory::createShape()
{
    Shape* textbox = new Textbox(2, 1, "black", 0, 0, "...");
    textbox->setName("Textbox");
    return textbox;
}

void TextboxFactory::toString()
{
    std::cout << "Created Textbox Shape" << std::endl;
}