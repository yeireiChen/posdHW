#include "Circle.h"
using namespace std;

Circle::Circle(double centerX,double centerY,double radius):cx(centerX),cy(centerY),r(radius),pi(3),shapeName("Circle"){};  //cx,cy,r,pi
Circle::~Circle(){}

double Circle::area() const{return pi*r*r;}
double Circle::perimeter() const {return 2*r*pi;}
string Circle::getShapeN() const {return shapeName;}
string Circle::getDec() const{

    stringstream ss;
    ss << "c(" << cx << " " << cy << " " << r << ") ";

    return ss.str();
}

std::string Circle::getFullDec() const{

    stringstream ss;
    ss << "Circle(" << cx << "," << cy << "," << r << ") ";

    return ss.str();
}
