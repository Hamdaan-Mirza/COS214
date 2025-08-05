#include "TextboxFactory.h"
#include "Textbox.h"

Shape* TextboxFactory::createShape() {
    return new Textbox(); 
}

void TextboxFactory::toString() {
    std::cout << "Created Textbox Shape" << std::endl;
}