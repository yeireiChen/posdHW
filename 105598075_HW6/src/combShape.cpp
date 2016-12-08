#include "combShape.h"

using namespace std;

combShape::combShape():shapeName("comboShape"){}  //std::vector <Shape *> component;

combShape::~combShape(){}


string combShape::getShapeN() const{
    return shapeName;
}

vector<Shape*> combShape::getVector() const{
    return component;
}
double combShape::area() const{

    double temp=0;
    for(Shape* t:component)
        temp+=t->area();

    return temp;
}

double combShape::perimeter() const{

    double temp=0;
    for(Shape* t:component)
        temp+=t->perimeter();

    return temp;
}

void combShape::add(Shape* s){

    component.push_back(s);
}

void combShape::add(vector<Shape*> ss){

    for(Shape* t :ss)
        component.push_back(t);
}

std::string combShape::getDec() const{
    return "";
}

std::string combShape::getFullDec() const{
    return "";
}
