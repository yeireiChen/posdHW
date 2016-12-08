#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "Shape.h"
#include <sstream>

class Rectangle:public Shape
{
    public:
        Rectangle(double,double,double,double);
        ~Rectangle();

        std::string shapeName;

        double area() const;
        double perimeter() const;
        void showArea() const;
        void showPerimeter() const;
        std::string getDec() const;
        std::string getFullDec() const;
        std::string getShapeN() const;

    protected:

    public:
        double x,y,l,w;
};

#endif // RECTANGLE_H
