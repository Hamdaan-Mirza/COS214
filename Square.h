#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{
    public:
        Square(int l, int w, string c, int px, int py);
        Shape* clone() override;
        std::string getName() const override;
        void setName(const std::string &name) override;
    private:
        std::string name;
};
#endif