#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(double ulcx, double ulcy, double length, double width):x(ulcx),y(ulcy),l(length),w(width),shapeName("Rectangle"){}

Rectangle::~Rectangle(){}

double Rectangle::area() const {
        return l*w;
}

double Rectangle::perimeter() const{
        return 2*(l+w);
}

string Rectangle::getShapeN() const {return shapeName;}

void Rectangle::showArea()const{

    cout<< "Rectangle Area is " << (l*w) <<endl;
}

void Rectangle::showPerimeter()const{
    cout<< "Rectangle Perimeter is " << 2*(l+w) <<endl;
}

std::string Rectangle::getDec()const{

    stringstream ss;
    ss << "r(" << x << " " << y << " " << l << " " << w << ") ";

    return ss.str();
}

std::string Rectangle::getFullDec() const{

    stringstream ss;
    ss << "r(" << x << "," << y << "," << l << "," << w << ") ";


    return ss.str();
}
