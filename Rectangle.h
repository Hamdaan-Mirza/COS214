#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
    public:
        Rectangle(int l, int w, string c, int px, int py);
        Shape* clone() override;
        std::string getName() const override;
        void setName(const std::string &name) override;
    private:
        std::string name;    
};

#endif