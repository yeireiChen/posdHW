#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <sstream>

class Triangle :public Shape
{
    public:
        Triangle(double,double,double,double,double,double);
        virtual ~Triangle();



        double area() const ;
        double perimeter() const;
        void showArea() const;
        void showPerimeter() const;
        std::string getShapeN() const;
        std::string getDec() const;
        std::string getFullDec() const;

        bool getSuccess() const;

    protected:

    private:
        std::string shapeName;
        double fx,fy,sx,sy,tx,ty,fWidth,sWidth,tWidth;
        bool t;
};

#endif // TRIANGLE_H
