#ifndef TRIANGLEC_H
#define TRIANGLEC_H

#include "Shape.h"
#include <sstream>

class TriangleC:public Shape
{
    public:

        virtual ~TriangleC();
        double area() const ;
        double perimeter() const;
        void showArea() const;
        void showPerimeter() const;
        std::string getShapeN() const;
        std::string getDec() const;
        std::string getFullDec() const;
        static TriangleC create(double,double,double,double,double,double);


        bool getSuccess() const;

    protected:

    private:
        std::string shapeName;
        TriangleC(double,double,double,double,double,double);
        double fx,fy,sx,sy,tx,ty,fWidth,sWidth,tWidth;
        bool t;
};

#endif // TRIANGLEC_H
