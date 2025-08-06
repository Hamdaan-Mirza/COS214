#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <fstream>

using namespace std;

class Shape
{
public:
    Shape();
    Shape(int l, int w, string c, int px, int py);
    virtual Shape *clone() = 0;

private:
    int length;
    int width;
    string color;
    int position_x;
    int position_y;
};

#endif