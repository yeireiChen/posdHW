#ifndef COMBSHAPE_H
#define COMBSHAPE_H


#include "Shape.h"
#include <vector>

class combShape:public Shape
{
    public:
        combShape();
        virtual ~combShape();

        std::string shapeName;

        double area() const;
        double perimeter() const;
        std::string getShapeN() const;

        void add(Shape *);
        void add(std::vector <Shape *>);
        std::string getDec() const;
        std::string getFullDec() const;

        std::vector<Shape*> getVector() const;

    protected:

    private:
        std::vector <Shape *> component;
        std::string shapeN;
};

#endif // COMBSHAPE_H
