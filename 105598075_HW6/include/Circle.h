#ifndef CIRCLE_H
#define CIRCLE_H
#include <Shape.h>
#include <sstream>

class Circle:public Shape
{
    public:
        Circle(double ,double ,double );
        ~Circle();

        std::string shapeName;

        double area() const;
        double perimeter() const;
        std::string getShapeN() const;
        std::string getDec() const;
        std::string getFullDec() const;
    protected:

    private:

        double cx,cy,r,pi;
};

#endif // CIRCLE_H
